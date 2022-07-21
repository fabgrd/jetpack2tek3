/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** broadcast.c
*/

#include "server.h"

void broadcast_all(server_t *srv, const char *msg)
{
    for (int i = 0; i < 2; i++)
        broadcast(&srv->clients[i], msg);
}

void send_message(client_t *cli)
{
    char msg[4096];
    size_t buff = 0;
    int i = 0;
    int tmpptr = cli->buffer.readptr;

    for (; tmpptr != cli->buffer.writeptr; i++) {
        msg[i] = cli->buffer.buffer[tmpptr];
        tmpptr = (tmpptr + 1) % 4096;
    }
    msg[i] = 0;
    if (strlen(msg) <= 0)
        return;
    buff = dprintf(cli->sockfd, "%s", msg + buff);
    cli->buffer.readptr = (cli->buffer.readptr + buff) % 4096;
}

void broadcast(client_t *cli, const char *msg)
{
    buffer_write(cli, msg);
}