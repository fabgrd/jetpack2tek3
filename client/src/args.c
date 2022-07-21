/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** args.c
*/

#include "jetpack.h"

void get_port(engine_t *eng, char *arg)
{
    if (!is_number(arg))
        throw(84, "Flag Error: -p flag need integer value");
    eng->network->port = atoi(arg);
}

void get_host(engine_t *eng, char *arg)
{
    if (false)
        throw(84, "Flag Error: -h flag need a valid ip");
    eng->network->clearip = arg;
}

void get_args(engine_t *eng, int ac, char **av)
{
    eng->network->clearip = NULL;
    eng->network->port = -1;
    for (int i = 1; i < ac; i += 2) {
        (strcmp(av[i], "-p") == 0) ? get_port(eng, av[i + 1]) : (void)0;
        (strcmp(av[i], "-h") == 0) ? get_host(eng, av[i + 1]) : (void)0;
    }

    if (eng->network->clearip == NULL || eng->network->port == -1)
        throw(84, "Argument Error: -p & -h flags are required");
}