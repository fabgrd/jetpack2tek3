/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** Physic.c
*/

#include "server.h"

void move_player(server_t *srv, client_t *cli, double time)
{
    dvec2 *speed = &cli->ply.speed;
    dvec2 *vel = &cli->ply.velocity;
    dvec2 *pos = &cli->ply.pos;

    speed->x = vel->x;
    speed->y = vel->y * (cli->fire ? -1 : 1);
    if (speed->y > 0)
        speed->y *= (srv->game.gravity / 10);
    if (speed->y < 0)
        speed->y *= (10 / srv->game.gravity);
    if (pos->y >= 0 && pos->y <= srv->map.size.y - 1) {
        pos->y -= speed->y * time;
    } if (pos->y <= 0) {
        speed->y /= 1.2;
        pos->y = 0;
    } else if (pos->y >= srv->map.size.y - 1) {
        speed->y = 0;
        pos->y = srv->map.size.y - 1;
    }
    pos->x += speed->x * time;
}

int check_fences(server_t *srv, client_t *cli)
{
    vec2 size = srv->map.size;
    ivec2 real_pos = { cli->ply.pos.x, size.y - 1 - cli->ply.pos.y};

    if (srv->map.map[real_pos.y][real_pos.x] != 'e')
        return RUNNING;

    for (int i = 0; i < 2; ++i)
        if (srv->clients[i].sockfd != cli->sockfd)
            srv->game.winner = srv->clients[i].sockfd;
    return FINISHED;
}

int check_colliders(server_t *srv, client_t *cli, char *buff, size_t *off)
{
    dvec2 pos = cli->ply.pos;
    vec2 size = srv->map.size;
    ivec2 real_pos = { pos.x, size.y - 1 - pos.y};

    if (srv->map.map[real_pos.y][real_pos.x] == 'c') {
        srv->map.map[real_pos.y][real_pos.x] = '_';
        cli->coins++;
        *off += snprintf(&buff[*off], 4096 - *off, "COIN %i %i %i\n", \
        cli->sockfd, (int)pos.x, (int)pos.y);
    }
    if (check_fences(srv, cli) == FINISHED)
        return FINISHED;

    return (RUNNING);
}