/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** commands2.c
*/

#include "jetpack.h"

void command_map(network_t *net, char **args)
{
    ivec2 size = { atoi(args[1]), atoi(args[2]) };

    mutex_lock(&net->map.lock);
    net->map.size = size;
    net->map.strmap = strdup(args[3]);
    format_map(&net->map);
    mutex_unlock(&net->map.lock);
    mutex_lock(&net->game.ply1.lock);
    net->game.ply1.pos = (dvec2){ 0, size.y / 2 };
    mutex_unlock(&net->game.ply1.lock);
    mutex_lock(&net->game.ply2.lock);
    net->game.ply2.pos = (dvec2){ 0, size.y / 2 };
    mutex_unlock(&net->game.ply2.lock);
    net->map_ready = true;
}

void command_player(network_t *net, char **av)
{
    ivec2 size = net->map.size;
    if (atoi(av[1]) == net->id) {
        mutex_lock(&net->game.ply1.lock);
        net->game.ply1.pos = (dvec2){ atof(av[2]), size.y - 1 - atof(av[3]) };
        net->game.ply1.score = atoi(av[4]);
        mutex_unlock(&net->game.ply1.lock);
    } else {
        mutex_lock(&net->game.ply2.lock);
        net->game.ply2.pos = (dvec2){ atof(av[2]), size.y - 1 - atof(av[3]) };
        net->game.ply2.score = atoi(av[4]);
        mutex_unlock(&net->game.ply2.lock);
    }
}