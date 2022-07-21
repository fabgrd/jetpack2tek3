/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-jetpack2tek3-fabien.giraudier
** File description:
** init_scr
*/

#include "jetpack.h"

void find_ply_scr1(graphic_t *graphic, engine_t *eng)
{
    char nbr[1000];

    mutex_lock(&eng->network->game.ply1.lock);
    sprintf(nbr, "%d", eng->network->game.ply1.score);
    mutex_unlock(&eng->network->game.ply1.lock);
    sfText_setString(graphic->scr_ply1->txt, nbr);
}

void find_ply_scr2(graphic_t *graphic, engine_t *eng)
{
    char nbr[1000];

    mutex_lock(&eng->network->game.ply2.lock);
    sprintf(nbr, "%d", eng->network->game.ply2.score);
    mutex_unlock(&eng->network->game.ply2.lock);
    sfText_setString(graphic->scr_ply2->txt, nbr);
}