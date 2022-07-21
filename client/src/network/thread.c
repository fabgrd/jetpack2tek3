/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** thread.c
*/

#include "jetpack.h"

void process_token(network_t *net, char *token, char del)
{
    if (net->message == NULL) {
        net->message = strdup(token);
    } else {
        net->message = realloc(net->message, sizeof(char) * \
        (strlen(net->message) + strlen(token) + 1));
        strcat(net->message, token);
    }
    if (del == '\n') {
        handle_server_command(net);
        free(net->message);
        net->message = NULL;
    }
}

int read_server(network_t *net)
{
    char buffer[4096];
    char copy[4096];
    char *token;
    char *ptr;
    size_t len = read(net->socket, buffer, 4095);

    buffer[len] = 0;
    strcpy(copy, buffer);
    token = strtok_r(buffer, "\n", &ptr);

    while (token) {
        process_token(net, token, copy[token-buffer+strlen(token)]);
        token = strtok_r(NULL, "\n", &ptr);
    }
    return 0;
}

void all_ready(network_t *net)
{
    bool csfml;
    bool coins;

    if (net->ready)
        return;
    mutex_lock(&net->lock);
    csfml = net->csfml_ready;
    coins = net->coins_created;
    mutex_unlock(&net->lock);
    if (net->map_ready && csfml && coins) {
        net->ready = true;
        broadcast(net, "READY\n");
    }
}

int thread_loop(network_t *net)
{
    mutex_lock(&net->lock);
    if (net->exit)
        return 1;
    mutex_unlock(&net->lock);
    all_ready(net);
    FD_ZERO(&net->fdin);
    FD_ZERO(&net->fdout);
    FD_SET(net->socket, &net->fdin);
    FD_SET(net->socket, &net->fdout);
    return 0;
}

void *start_thread(void *network)
{
    network_t *net = (network_t *)network;

    mutex_unlock(&net->lock);
    broadcast(net, "ID\n");
    while (true) {
        struct timeval timer = {0, 200000};
        int res;
        if (thread_loop(net))
            break;
        res = select(net->socket + 1, &net->fdin, &net->fdout, NULL, &timer);
        if (res == -1)
            throw(84, "select(): Error when selecting");
        else if (res == 0)
            continue;
        if (FD_ISSET(net->socket, &net->fdin))
            read_server(net);
        if (FD_ISSET(net->socket, &net->fdout))
            send_message(net);
    }
    return NULL;
}