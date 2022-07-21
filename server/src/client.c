/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** client.c
*/

#include "server.h"

void init_clients(server_t *server)
{
    for (int i = 0; i < 2; i++) {
        server->clients[i].sockfd = 0;
        server->clients[i].coins = 0;
        server->clients[i].message = NULL;
        server->clients[i].buffer.readptr = 0;
        server->clients[i].buffer.writeptr = 0;
        server->clients[i].fire = false;
        server->clients[i].hasId = false;
        server->clients[i].hasMap = false;
        server->clients[i].isReady = false;
        server->clients[i].ply.max = 5;
        server->clients[i].ply.pos = (dvec2){ 0, 0 };
        server->clients[i].ply.speed = (dvec2){ 0, 0 };
        server->clients[i].ply.velocity = (dvec2){ 5, 5 };
    }
}

void client_loop(server_t *srv)
{
    for (int i = 0; i < 2; i++) {
        client_t *cli = &srv->clients[i];
        if (FD_ISSET(cli->sockfd, &srv->fdin) && read_client(srv, i) == -1) {
            remove_client(srv, i);
            return;
        }
        if (FD_ISSET(cli->sockfd, &srv->fdout))
            send_message(cli);
    }
}

bool all_ready(server_t *server)
{
    for (int i = 0; i < 2; ++i)
        if (!server->clients[i].isReady)
            return false;

    return true;
}

int read_client(server_t *srv, int id)
{
    char *buff = my_get_next_line(srv->clients[id].sockfd);

    if (srv->clients[id].message == NULL) {
        srv->clients[id].message = strdup(buff);
    } else {
        srv->clients[id].message = realloc(srv->clients[id].message, \
        sizeof(char) * (strlen(srv->clients[id].message) + strlen(buff) + 1));
        strcat(srv->clients[id].message, buff);
    }
    free(buff);
    if (srv->clients[id].message == NULL)
        return -1;
    if (my_str_find("\n", srv->clients[id].message)) {
        handle_client_command(srv, id);
        free(srv->clients[id].message);
        srv->clients[id].message = NULL;
    }
    return 0;
}

void register_client(server_t *srv)
{
    int sock;
    struct sockaddr_in cli;
    int cli_size = sizeof(cli);
    socklen_t *s = (socklen_t *)&cli_size;

    if ((sock = accept(srv->socket, (soaddr_t)&cli, s)) == -1)
        throw(84, "accept(): Can't accept connexion");

    for (int i = 0; i < 2; i++) {
        srv->clients[i].ip = cli.sin_addr.s_addr;
        srv->clients[i].address = cli;
        srv->clients[i].len_addr = sizeof(cli);
        if (srv->clients[i].sockfd == 0) {
            srv->clients[i].sockfd = sock;
            printf("Client connected to server\n");
            srv->clients[i].ply.pos.y = srv->map.size.y / 2;
            break;
        }
    }
}