/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** init_enities.c
*/

#include "jetpack.h"

void init_ply_fly1(graphic_t *graphic)
{
    graphic->ply1->sp = sfSprite_create();
    graphic->ply1->tex = sfTexture_createFromFile(\
    "./client/assets/cuphead_fly.png", NULL);
    graphic->ply1->pos.x = 0;
    graphic->ply1->pos.y = 0;
    graphic->ply1->scale = (sfVector2f) {0.8, 0.8};
    graphic->ply1->rect = (sfIntRect) {0, 0, 115, 115};
    graphic->ply1->clock = sfClock_create();

    sfSprite_setTexture(graphic->ply1->sp, graphic->ply1->tex, sfFalse);
    sfSprite_setTextureRect(graphic->ply1->sp, graphic->ply1->rect);
    sfSprite_setPosition(graphic->ply1->sp, graphic->ply1->pos);
    sfSprite_setScale(graphic->ply1->sp, graphic->ply1->scale);
}

void init_ply_fly2(graphic_t *graphic)
{
    graphic->ply2->sp = sfSprite_create();
    graphic->ply2->tex = sfTexture_createFromFile(\
    "./client/assets/mugman_fly.png", NULL);
    graphic->ply2->pos.x = 0;
    graphic->ply2->pos.y = 0;
    graphic->ply2->scale = (sfVector2f) {0.8, 0.8};
    graphic->ply2->rect = (sfIntRect) {0, 0, 115, 115};
    graphic->ply2->clock = sfClock_create();

    sfSprite_setTexture(graphic->ply2->sp, graphic->ply2->tex, sfFalse);
    sfSprite_setTextureRect(graphic->ply2->sp, graphic->ply2->rect);
    sfSprite_setPosition(graphic->ply2->sp, graphic->ply2->pos);
    sfSprite_setScale(graphic->ply2->sp, graphic->ply2->scale);
}

void create_coin(graphic_t *graphic, sfVector2f pos)
{
    object_t *coin = malloc(sizeof(object_t));

    float scale = graphic->tile_size / 300;
    coin->sp = sfSprite_create();
    coin->tex = graphic->coin_tex;
    coin->pos = pos;
    coin->scale = (sfVector2f) {scale, scale};
    coin->rect = (sfIntRect) {0, 0, 300, 300};
    coin->clock = sfClock_create();
    coin->next = NULL;
    sfSprite_setTexture(coin->sp, coin->tex, sfFalse);
    sfSprite_setTextureRect(coin->sp, coin->rect);
    sfSprite_setPosition(coin->sp, coin->pos);
    sfSprite_setScale(coin->sp, coin->scale);
    push_back(&graphic->coins, coin);
}

void create_fence(graphic_t *graphic, sfVector2f pos)
{
    object_t *fence = malloc(sizeof(object_t));

    fence->sp = sfSprite_create();
    fence->tex = graphic->fence_tex;
    fence->pos = pos;
    fence->scale = (sfVector2f) {0.5, 0.5};
    fence->rect = (sfIntRect) {0, 0, 175, 175};
    fence->clock = sfClock_create();
    fence->next = NULL;
    sfSprite_setTexture(fence->sp, fence->tex, sfFalse);
    sfSprite_setTextureRect(fence->sp, fence->rect);
    sfSprite_setPosition(fence->sp, fence->pos);
    sfSprite_setScale(fence->sp, fence->scale);
    push_back(&graphic->fences, fence);
}

void init_cam(graphic_t *graphic)
{
    sfVideoMode m = graphic->rdr->quality;
    graphic->cam_rect = (sfFloatRect) {0, 0, m.width, m.height};
    graphic->cam = sfView_createFromRect(graphic->cam_rect);
}