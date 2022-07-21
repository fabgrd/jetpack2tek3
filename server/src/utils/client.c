/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** client.c
*/

#include "server.h"

void remove_client(server_t *srv, int id)
{
    FD_CLR(srv->clients[id].sockfd, &srv->fdin);

    srv->clients[id].message = NULL;
    memset(&srv->clients[id].address, 0, sizeof(srv->clients[id].address));
}