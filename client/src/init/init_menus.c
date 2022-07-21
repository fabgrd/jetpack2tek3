/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** init_menus.c
*/

#include "jetpack.h"

void init_ply1_menu(graphic_t *graphic)
{
    graphic->ply1_m->sp = sfSprite_create();
    graphic->ply1_m->tex = sfTexture_createFromFile(\
    "./client/assets/cuphead_menu.png", NULL);
    graphic->ply1_m->pos.x = 350;
    graphic->ply1_m->pos.y = 200;
    graphic->ply1_m->scale = (sfVector2f) {0.8, 0.8};
    graphic->ply1_m->rect = (sfIntRect) {0, 0, 300, 450};
    graphic->ply1_m->clock = sfClock_create();

    sfSprite_setTexture(graphic->ply1_m->sp, graphic->ply1_m->tex, sfFalse);
    sfSprite_setTextureRect(graphic->ply1_m->sp, graphic->ply1_m->rect);
    sfSprite_setPosition(graphic->ply1_m->sp, graphic->ply1_m->pos);
    sfSprite_setScale(graphic->ply1_m->sp, graphic->ply1_m->scale);
}

void init_ply2_menu(graphic_t *graphic)
{
    graphic->ply2_m->sp = sfSprite_create();
    graphic->ply2_m->tex = sfTexture_createFromFile(\
    "./client/assets/mugman_menu.png", NULL);
    graphic->ply2_m->pos.x = 660;
    graphic->ply2_m->pos.y = 200;
    graphic->ply2_m->scale = (sfVector2f) {0.8, 0.8};
    graphic->ply2_m->rect = (sfIntRect) {0, 0, 400, 450};
    graphic->ply2_m->clock = sfClock_create();

    sfSprite_setTexture(graphic->ply2_m->sp, graphic->ply2_m->tex, sfFalse);
    sfSprite_setTextureRect(graphic->ply2_m->sp, graphic->ply2_m->rect);
    sfSprite_setPosition(graphic->ply2_m->sp, graphic->ply2_m->pos);
    sfSprite_setScale(graphic->ply2_m->sp, graphic->ply2_m->scale);
}

void init_loader(graphic_t *graphic)
{
    graphic->loader->sp = sfSprite_create();
    graphic->loader->tex = sfTexture_createFromFile(\
    "./client/assets/hourglass.png", NULL);
    graphic->loader->pos.x = 1000;
    graphic->loader->pos.y = 420;
    graphic->loader->scale = (sfVector2f) {1, 1};
    graphic->loader->rect = (sfIntRect) {0, 0, 200, 300};
    graphic->loader->clock = sfClock_create();

    sfSprite_setTexture(graphic->loader->sp, graphic->loader->tex, sfFalse);
    sfSprite_setTextureRect(graphic->loader->sp, graphic->loader->rect);
    sfSprite_setPosition(graphic->loader->sp, graphic->loader->pos);
    sfSprite_setScale(graphic->loader->sp, graphic->loader->scale);
}

void init_scoreboard(graphic_t *graphic)
{
    graphic->scr_brd->sp = sfSprite_create();
    graphic->scr_brd->tex = sfTexture_createFromFile(\
    "./client/assets/scoreboard.png", NULL);
    graphic->scr_brd->rect = (sfIntRect) {0, 0, 1280, 720};

    sfSprite_setTexture(graphic->scr_brd->sp, graphic->scr_brd->tex, sfFalse);
    sfSprite_setTextureRect(graphic->scr_brd->sp, graphic->scr_brd->rect);
}

void init_finish_line(graphic_t *graphic, engine_t *eng)
{
    int tile_size = 720 / eng->network->map.size.y;

    graphic->fnsh->sp = sfSprite_create();
    graphic->fnsh->tex = sfTexture_createFromFile(\
    "./client/assets/finnish_line.png", NULL);
    graphic->fnsh->rect = (sfIntRect) {0, 0, 70, 2000};
    graphic->fnsh->pos.x = eng->network->map.size.x * tile_size - 150;

    sfSprite_setTexture(graphic->fnsh->sp, graphic->fnsh->tex, sfFalse);
    sfSprite_setTextureRect(graphic->fnsh->sp, graphic->fnsh->rect);
    sfSprite_setPosition(graphic->fnsh->sp, graphic->fnsh->pos);
}