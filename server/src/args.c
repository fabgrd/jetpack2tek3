/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** args.c
*/

#include "server.h"

void get_port(server_t *srv, char *arg)
{
    if (!is_number(arg))
        throw(84, "Flag Error: -p flag need integer value");
    srv->port = atoi(arg);
}

void get_gravity(server_t *srv, char *arg)
{
    if (!is_number(arg))
        throw(84, "Flag Error: -g flag need integer value");
    srv->game.gravity = atoi(arg);
}

void get_map(server_t *srv, char *arg)
{
    if (!file_exists(arg))
        throw(84, "Flag Error: -m flag need a valid file");
    srv->map.path = arg;
}

void get_args(server_t *srv, int ac, char **av)
{
    srv->map.path = NULL;
    srv->game.gravity = -1;
    srv->port = -1;
    for (int i = 1; i < ac; i += 2) {
        (strcmp(av[i], "-p") == 0) ? get_port(srv, av[i + 1]) : (void)0;
        (strcmp(av[i], "-g") == 0) ? get_gravity(srv, av[i + 1]) : (void)0;
        (strcmp(av[i], "-m") == 0) ? get_map(srv, av[i + 1]) : (void)0;
    }

    if (srv->map.path == NULL || srv->game.gravity == -1 || srv->port == -1)
        throw(84, "Argument Error: -p, -g & -m flags are required");
}