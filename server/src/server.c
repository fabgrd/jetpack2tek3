/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** server.c
*/

#include "server.h"

static void sig_func(UNUSED int sig)
{
    exit(0);
}

void set_fds(server_t *srv)
{
    FD_ZERO(&srv->fdin);
    FD_ZERO(&srv->fdout);
    FD_SET(srv->socket, &srv->fdin);
    FD_SET(srv->socket, &srv->fdout);
    srv->max_sd = srv->socket;
    for (int i = 0; i < 2; i++) {
        if (srv->clients[i].sockfd > 0) {
            FD_SET(srv->clients[i].sockfd, &srv->fdin);
            FD_SET(srv->clients[i].sockfd, &srv->fdout);
        }
        if (srv->clients[i].sockfd > srv->max_sd)
            srv->max_sd = srv->clients[i].sockfd;
    }
}

void network_loop(server_t *srv)
{
    init_clients(srv);
    while (true) {
        int rs;
        struct timeval tv = (struct timeval){0, 200000};
        game_loop(srv);
        set_fds(srv);
        if ((rs = select(srv->max_sd + 1, &srv->fdin, \
            &srv->fdout, NULL, &tv)) == -1)
            throw(84, "select(): Failed to select");
        if (rs == 0)
            continue;
        if (FD_ISSET(srv->socket, &srv->fdin)) {
            register_client(srv);
            continue;
        }
        client_loop(srv);
    }
}

void get_server_data(server_t *server)
{
    server->protocol = getprotobyname("TCP");
    server->socket = socket(AF_INET, SOCK_STREAM, server->protocol->p_proto);
    if (server->socket == -1)
        throw(84, "socket(): Can't initialize server socket");
    server->sin.sin_family = AF_INET;
    server->sin.sin_port = htons(server->port);
    server->sin.sin_addr.s_addr = INADDR_ANY;
    server->cmds = NULL;
    server->max_sd = server->socket;
    server->clients = malloc(sizeof(client_t) * 2);
}

void init_server(server_t *srv)
{
    get_server_data(srv);
    register_all_commands(srv);
    if (bind(srv->socket, (const soaddr_t)&srv->sin, sizeof(srv->sin)) == -1) {
        shutdown(srv->socket, 2);
        close(srv->socket);
        throw(84, "bind(): Can't bind server socket");
    }
    if (listen(srv->socket, 2)){
        close(srv->socket);
        throw(84, "listen(): Unable to listen in server socket");
    }
    signal(SIGINT, sig_func);
    signal(SIGQUIT, sig_func);
    signal(SIGPIPE, SIG_IGN);
    srv->game.started = false;
}