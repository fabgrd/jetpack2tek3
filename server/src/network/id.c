/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** id.c
*/

#include "server.h"

void command_id(UNUSED server_t *srv, client_t *cli, UNUSED char **args)
{
    char str[4096];

    sprintf(str, "ID %d\n", cli->sockfd);
    broadcast(cli, str);
    cli->hasId = 1;
}

void command_map(server_t *srv, client_t *cli, UNUSED char **args)
{
    char str[4096];
    vec2 size = srv->map.size;

    sprintf(str, "MAP %lu %lu %s\n", size.x, size.y, srv->map.strmap);
    broadcast(cli, str);
    cli->hasMap = 1;
}

void command_ready(UNUSED server_t *srv, client_t *cli, UNUSED char **args)
{
    cli->isReady = true;
}

void command_fire(UNUSED server_t *srv, client_t *cli, char **args)
{
    cli->fire = atoi(args[1]);
}