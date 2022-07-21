/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** engine.c
*/

#include "server.h"
static struct timeval last;

ivec2 get_winner(server_t *srv)
{
    ivec2 winner = (ivec2){ 0, 0 };

    for (int i = 0; i < 2; i++) {
        if (!winner.x || srv->clients[i].coins > winner.y)
            winner = (ivec2){srv->clients[i].sockfd, srv->clients[i].coins};
        else if (winner.x && srv->clients[i].coins == winner.y)
            winner = (ivec2){-1, 0};
    }
    return winner;
}

void end_game(server_t *srv)
{
    char buff[24];
    ivec2 winner = (ivec2){ 0, 0 };

    if (srv->game.winner == -1)
        winner = get_winner(srv);
    else
        winner.x = srv->game.winner;
    snprintf(buff, 24, "FINISH %d\n", winner.x);
    broadcast_all(srv, buff);
    srv->game.started = false;
}

int get_game_state(server_t *srv)
{
    char buff[4096];
    size_t offset = 0;
    struct timeval now;
    double time;

    gettimeofday(&now, NULL);
    time = ((now.tv_sec - last.tv_sec) + 1e-6 * (now.tv_usec - last.tv_usec));
    for (int i = 0; i < 2; i++) {
        client_t *cli = &srv->clients[i];
        move_player(srv, cli, time);
        if (check_colliders(srv, cli, buff, &offset) == FINISHED)
            return FINISHED;
        snprintf(&buff[offset], 4096 - offset, "PLAYER %d %f %f %d\n", \
        cli->sockfd, cli->ply.pos.x, cli->ply.pos.y, cli->coins);
        offset = strlen(buff);
        if (cli->ply.pos.x >= srv->map.size.x - 1)
            return (FINISHED);
    }
    broadcast_all(srv, buff);
    return (RUNNING);
}

void game_loop(server_t *srv)
{
    int ret;

    if (!all_ready(srv))
        return;
    if (!srv->game.started) {
        srv->game.started = true;
        srv->game.winner = -1;
        gettimeofday(&last, NULL);
        broadcast_all(srv, "START\n");
        return;
    }
    if ((ret = get_game_state(srv)) == ERROR)
        throw(84, "Game Error: Error during game processing");
    if (ret == FINISHED || srv->game.winner != -1)
        end_game(srv);
    gettimeofday(&last, NULL);
}