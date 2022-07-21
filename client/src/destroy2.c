/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** destroy2.c
*/

#include "jetpack.h"

void destroy_ply(player_t *player)
{
    sfSprite_destroy(player->sp);
    sfTexture_destroy(player->tex);
    sfClock_destroy(player->clock);
    free(player);
}

void destroy_obj(object_t *player)
{
    sfSprite_destroy(player->sp);
    sfTexture_destroy(player->tex);
    sfClock_destroy(player->clock);
    free(player);
}

void destroy_para(paralax_t *player)
{
    sfSprite_destroy(player->sp);
    sfTexture_destroy(player->tex);
    free(player);
}