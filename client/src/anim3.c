/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** anim3.c
*/

#include "jetpack.h"

void game_animator(graphic_t *graphic, engine_t *eng)
{
    ply_fly1(graphic, eng);
    ply_fly2(graphic, eng);
    move_plx4(graphic);
    move_plx3(graphic);
    move_plx2(graphic);
    move_plx1(graphic);
}

void move_plx4(graphic_t *graphic)
{
    int pos = graphic->cam_pos.x - graphic->rdr->quality.width / 2;

    graphic->plx4->pos.x = pos;
    sfSprite_setPosition(graphic->plx4->sp, graphic->plx4->pos);
}

void move_plx3(graphic_t *graphic)
{
    int pos = graphic->cam_pos.x - graphic->rdr->quality.width / 2;

    graphic->plx3->pos.x = pos;
    sfSprite_setPosition(graphic->plx3->sp, graphic->plx3->pos);
    graphic->plx3->rect.left += 1;
    if (graphic->plx3->rect.left >= 1280)
        graphic->plx3->rect.left = 0;
    sfSprite_setTextureRect(graphic->plx3->sp, graphic->plx3->rect);
}

void move_plx2(graphic_t *graphic)
{
    int pos = graphic->cam_pos.x - graphic->rdr->quality.width / 2;

    graphic->plx2->pos.x = pos;
    sfSprite_setPosition(graphic->plx2->sp, graphic->plx2->pos);
    graphic->plx2->rect.left += 2;
    if (graphic->plx2->rect.left >= 2560)
        graphic->plx2->rect.left = 0;
    sfSprite_setTextureRect(graphic->plx2->sp, graphic->plx2->rect);
}

void move_plx1(graphic_t *graphic)
{
    int pos = graphic->cam_pos.x - graphic->rdr->quality.width / 2;

    graphic->plx1->pos.x = pos;
    sfSprite_setPosition(graphic->plx1->sp, graphic->plx1->pos);
    graphic->plx1->rect.left += 3;
    if (graphic->plx1->rect.left >= 3840)
        graphic->plx1->rect.left = 0;
    sfSprite_setTextureRect(graphic->plx1->sp, graphic->plx1->rect);
}