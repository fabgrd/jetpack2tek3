/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** connect.c
*/

#include "jetpack.h"

void get_network_data(network_t *net)
{
    net->protocol = getprotobyname("TCP");
    net->socket = socket(AF_INET, SOCK_STREAM, net->protocol->p_proto);
    if (net->socket == -1)
        throw(84, "socket(): Can't initialize server socket");
    net->sin.sin_family = AF_INET;
    net->sin.sin_port = htons(net->port);
    net->sin.sin_addr.s_addr = inet_addr(net->clearip);
    net->cmds = NULL;
    net->max_sd = net->socket;
}

void init_net2(network_t *net)
{
    net->game.ply1.score = 0;
    net->game.ply2.score = 0;
    net->game.winner = -2;
    net->game.started = false;
    net->exit = false;
    net->csfml_ready = false;
    net->map_ready = false;
    net->coins_created = false;
    net->ready = false;
    net->message = NULL;
    net->buffer.readptr = 0;
    net->buffer.writeptr = 0;
}

void init_network(network_t *net)
{
    get_network_data(net);
    register_all_commands(net);
    if (connect(net->socket, (soaddr_t)&net->sin, sizeof(soin)) == -1)
        throw(84, "connect(): Unable to connect server");
    mutex_init(&net->lock);
    mutex_init(&net->map.lock);
    mutex_init(&net->game.lock);
    mutex_init(&net->game.ply1.lock);
    mutex_init(&net->game.ply2.lock);
    mutex_lock(&net->lock);
    init_net2(net);
}

void init_thread(network_t *net)
{
    pthread_create(&net->thread, NULL, start_thread, (void *) net);
}