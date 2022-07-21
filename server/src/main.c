/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** main.c
*/

#include "server.h"

void throw(int exitCode, char *reason)
{
    fprintf(stderr, "%s\n", reason);
    exit(exitCode);
}

int main(int ac, char **av)
{
    server_t srv;

    if (ac % 2 == 0)
        return 84;
    if (ac > 1)
        get_args(&srv, ac, av);
    else
        return 84;
    init_map(&srv);
    init_server(&srv);
    printf("Server started\n");
    network_loop(&srv);
    return 0;
}