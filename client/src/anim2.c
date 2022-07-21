/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** anim2.C
*/

#include "jetpack.h"

void ply_fly1(graphic_t *graphic, engine_t *eng)
{
    mutex_lock(&eng->network->game.ply1.lock);
    graphic->ply1->pos.y = eng->network->game.ply1.pos.y * graphic->tile_size;
    graphic->ply1->pos.x = eng->network->game.ply1.pos.x * graphic->tile_size;
    sfSprite_setPosition(graphic->ply1->sp, graphic->ply1->pos);
    mutex_unlock(&eng->network->game.ply1.lock);
    graphic->ply1->time = sfClock_getElapsedTime(graphic->ply1->clock);
    graphic->ply1->seconds = graphic->ply1->time.microseconds / 1000000.0;
    if (graphic->ply1->seconds > 0.05) {
        graphic->ply1->rect.left += 115;
        if (graphic->ply1->rect.left >= 460 * 3)
            graphic->ply1->rect.left = 460 * 2;
        sfSprite_setTextureRect(graphic->ply1->sp, graphic->ply1->rect);
        sfClock_restart(graphic->ply1->clock);
    }
}

void ply_fly2(graphic_t *graphic, engine_t *eng)
{
    mutex_lock(&eng->network->game.ply2.lock);
    graphic->ply2->pos.y = eng->network->game.ply2.pos.y * graphic->tile_size;
    graphic->ply2->pos.x = eng->network->game.ply2.pos.x * graphic->tile_size;
    sfSprite_setPosition(graphic->ply2->sp, graphic->ply2->pos);
    mutex_unlock(&eng->network->game.ply2.lock);
    graphic->ply2->time = sfClock_getElapsedTime(graphic->ply2->clock);
    graphic->ply2->seconds = graphic->ply2->time.microseconds / 1000000.0;
    if (graphic->ply2->seconds > 0.05) {
        graphic->ply2->rect.left += 115;
        if (graphic->ply2->rect.left >= 460 * 3)
            graphic->ply2->rect.left = 460 * 2;
        sfSprite_setTextureRect(graphic->ply2->sp, graphic->ply2->rect);
        sfClock_restart(graphic->ply2->clock);
    }
}

void ply1_menu_anim(graphic_t *graphic)
{
    graphic->ply1_m->time = sfClock_getElapsedTime(graphic->ply1_m->clock);
    graphic->ply1_m->seconds = graphic->ply1_m->time.microseconds / 1000000.0;
    if (graphic->ply1_m->seconds > 0.06) {
        graphic->ply1_m->rect.left += 300;
        if (graphic->ply1_m->rect.left >= 2100)
            graphic->ply1_m->rect.left = 0;
        sfSprite_setTextureRect(graphic->ply1_m->sp, graphic->ply1_m->rect);
        sfClock_restart(graphic->ply1_m->clock);
    }
}

void ply2_menu_anim(graphic_t *graphic)
{
    graphic->ply2_m->time = sfClock_getElapsedTime(graphic->ply2_m->clock);
    graphic->ply2_m->seconds = graphic->ply2_m->time.microseconds / 1000000.0;
    if (graphic->ply2_m->seconds > 0.06) {
        graphic->ply2_m->rect.left += 400;
        if (graphic->ply2_m->rect.left >= 2800)
            graphic->ply2_m->rect.left = 0;
        sfSprite_setTextureRect(graphic->ply2_m->sp, graphic->ply2_m->rect);
        sfClock_restart(graphic->ply2_m->clock);
    }
}

void scoreboard_animator(graphic_t *graphic, engine_t *eng)
{
    find_ply_scr1(graphic, eng);
    find_ply_scr2(graphic, eng);
    ply1_menu_anim(graphic);
    ply2_menu_anim(graphic);
}