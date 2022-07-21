/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** broadcast.c
*/

#include "jetpack.h"

void broadcast(network_t *net, const char *msg)
{
    buffer_write(net, msg);
}

void send_message(network_t *net)
{
    char msg[4096];
    size_t buff = 0;
    int i = 0;
    int tmpptr = net->buffer.readptr;

    for (; tmpptr != net->buffer.writeptr; i++) {
        msg[i] = net->buffer.buffer[tmpptr];
        tmpptr = (tmpptr + 1) % 4096;
    }
    msg[i] = 0;

    if (strlen(msg) <= 0)
        return;
    buff = dprintf(net->socket, "%s", msg + buff);
    net->buffer.readptr = (net->buffer.readptr + buff) % 4096;
    printf("%s", msg);
}
