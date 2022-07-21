/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** init_score.c
*/

#include "jetpack.h"

void init_score1(graphic_t *graphic)
{
    graphic->scr_ply1->txt = sfText_create();
    graphic->scr_ply1->font = sfFont_createFromFile(\
    "./client/assets/retro.ttf");
    graphic->scr_ply1->pos.x = 480;
    graphic->scr_ply1->pos.y = 563;

    sfText_setCharacterSize(graphic->scr_ply1->txt, 50);
    sfText_setColor(graphic->scr_ply1->txt, sfRed);
    sfText_setFont(graphic->scr_ply1->txt, graphic->scr_ply1->font);
    sfText_setPosition(graphic->scr_ply1->txt, graphic->scr_ply1->pos);
}

void init_score2(graphic_t *graphic)
{
    graphic->scr_ply2->txt = sfText_create();
    graphic->scr_ply2->font = graphic->scr_ply1->font;
    graphic->scr_ply2->pos.x = 730;
    graphic->scr_ply2->pos.y = 563;

    sfText_setCharacterSize(graphic->scr_ply2->txt, 50);
    sfText_setColor(graphic->scr_ply2->txt, sfBlue);
    sfText_setFont(graphic->scr_ply2->txt, graphic->scr_ply2->font);
    sfText_setPosition(graphic->scr_ply2->txt, graphic->scr_ply2->pos);
}