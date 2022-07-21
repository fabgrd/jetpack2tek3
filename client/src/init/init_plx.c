/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** init_plx.c
*/

#include "jetpack.h"

void init_plx4(graphic_t *graphic)
{
    graphic->plx4->pos.x = 0;
    graphic->plx4->pos.y = 0;
    graphic->plx4->sp = sfSprite_create();
    graphic->plx4->tex = sfTexture_createFromFile(\
    "./client/assets/paralax4.png", NULL);

    sfSprite_setTexture(graphic->plx4->sp, graphic->plx4->tex, sfFalse);
}

void init_plx3(graphic_t *graphic)
{
    graphic->plx3->pos.x = 0;
    graphic->plx3->pos.y = 0;
    graphic->plx3->sp = sfSprite_create();
    graphic->plx3->tex = sfTexture_createFromFile(\
    "./client/assets/plx3.png", NULL);
    graphic->plx3->rect = (sfIntRect) {0, 0, 1280, 720};

    sfSprite_setTexture(graphic->plx3->sp, graphic->plx3->tex, sfFalse);
    sfSprite_setTextureRect(graphic->plx3->sp, graphic->plx3->rect);
}

void init_plx2(graphic_t *graphic)
{
    graphic->plx2->pos.x = 0;
    graphic->plx2->pos.y = 0;
    graphic->plx2->sp = sfSprite_create();
    graphic->plx2->tex = sfTexture_createFromFile(\
    "./client/assets/plx2.png", NULL);
    graphic->plx2->rect = (sfIntRect) {0, 0, 1280, 720};

    sfSprite_setTexture(graphic->plx2->sp, graphic->plx2->tex, sfFalse);
    sfSprite_setTextureRect(graphic->plx2->sp, graphic->plx2->rect);
}

void init_plx1(graphic_t *graphic)
{
    graphic->plx1->pos.x = 0;
    graphic->plx1->pos.y = 0;
    graphic->plx1->sp = sfSprite_create();
    graphic->plx1->tex = sfTexture_createFromFile(\
    "./client/assets/plx1.png", NULL);
    graphic->plx1->rect = (sfIntRect) {0, 0, 1280, 720};

    sfSprite_setTexture(graphic->plx1->sp, graphic->plx1->tex, sfFalse);
    sfSprite_setTextureRect(graphic->plx1->sp, graphic->plx1->rect);
}