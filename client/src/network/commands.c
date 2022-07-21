/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** commands.c
*/

#include "jetpack.h"

void command_id(network_t *net, char **args)
{
    net->id = atoi(args[1]);
    broadcast(net, "MAP\n");
}

void command_coins(network_t *net, char **args)
{
    ivec2 pos = { atoi(args[2]), net->map.size.y - 1 - atoi(args[3]) };

    mutex_lock(&net->map.lock);
    net->map.map[pos.y][pos.x] = '_';
    mutex_unlock(&net->map.lock);
}

void command_finish(network_t *net, char **args)
{
    mutex_lock(&net->game.lock);
    net->game.winner = atoi(args[1]);
    printf("WINNER : %i\n", net->game.winner);
    mutex_unlock(&net->game.lock);
    pthread_exit(0);
}

void command_start(network_t *net, UNUSED char **args)
{
    mutex_lock(&net->game.lock);
    net->game.started = true;
    mutex_unlock(&net->game.lock);
}