/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-jetpack2tek3-fabien.giraudier
** File description:
** anim
*/

#include "jetpack.h"

void coin_anim(object_t *coin)
{
    coin->time = sfClock_getElapsedTime(coin->clock);
    coin->seconds = coin->time.microseconds / 1000000.0;
    if (coin->seconds > 0.05) {
        coin->rect.left += 300;
        if (coin->rect.left >= 4800)
            coin->rect.left = 0;
        sfSprite_setTextureRect(coin->sp, coin->rect);
        sfClock_restart(coin->clock);
    }
}

void fences_anim(object_t *fences)
{
    fences->time = sfClock_getElapsedTime(fences->clock);
    fences->seconds = fences->time.microseconds / 1000000.0;
    if (fences->seconds > 0.05) {
        fences->rect.left += 175;
        if (fences->rect.left >= 2100)
            fences->rect.left = 0;
        sfSprite_setTextureRect(fences->sp, fences->rect);
        sfClock_restart(fences->clock);
    }
}

void anim_loader(graphic_t *graphic)
{
    graphic->loader->time = sfClock_getElapsedTime(graphic->loader->clock);
    graphic->loader->seconds = graphic->loader->time.microseconds / 1000000.0;
    if (graphic->loader->seconds > 0.05) {
        graphic->loader->rect.left += 200;
        if (graphic->loader->rect.left >= 9200)
            graphic->loader->rect.left = 0;
        sfSprite_setTextureRect(graphic->loader->sp, graphic->loader->rect);
        sfClock_restart(graphic->loader->clock);
    }
}

void anim(graphic_t *gr, engine_t *eng)
{
    sfVideoMode m = gr->rdr->quality;

    mutex_lock(&eng->network->game.lock);
    int winner = eng->network->game.winner;
    mutex_unlock(&eng->network->game.lock);
    if (winner == -2) {
        if (eng->network->game.started == false) {
            anim_loader(gr);
        } else if (eng->network->game.started == true) {
            game_animator(gr, eng);
            gr->cam_pos = get_camera_position(gr, eng->network);
            sfView_setCenter(gr->cam, gr->cam_pos);
            sfRenderWindow_setView(gr->rdr->window, gr->cam);
        }
    } else {
        scoreboard_animator(gr, eng);
        sfView_setCenter(gr->cam, (sfVector2f){ m.width / 2, m.height / 2 });
        sfRenderWindow_setView(gr->rdr->window, gr->cam);
    }
}