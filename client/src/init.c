/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-jetpack2tek3-fabien.giraudier
** File description:
** init
*/

#include "jetpack.h"

void init_window(graphic_t *graphic)
{
    graphic->rdr->quality = (sfVideoMode) {1280, 720, 32};
    graphic->rdr->window = sfRenderWindow_create(graphic->rdr->quality, \
    "Tete de tasse", sfClose, NULL);
    sfRenderWindow_setKeyRepeatEnabled(graphic->rdr->window, sfFalse);
}

void init_struct(graphic_t *graphic)
{
    graphic->rdr = malloc(sizeof(render_t));
    graphic->scr_ply1 = malloc(sizeof(score_t));
    graphic->scr_ply2 = malloc(sizeof(score_t));
    graphic->loader = malloc(sizeof(object_t));
    graphic->ply1 = malloc(sizeof(player_t));
    graphic->ply2 = malloc(sizeof(player_t));
    graphic->ply1_m = malloc(sizeof(player_t));
    graphic->ply2_m = malloc(sizeof(player_t));
    graphic->scr_brd = malloc(sizeof(paralax_t));
    graphic->fnsh = malloc(sizeof(paralax_t));
    graphic->plx1 = malloc(sizeof(paralax_t));
    graphic->plx2 = malloc(sizeof(paralax_t));
    graphic->plx3 = malloc(sizeof(paralax_t));
    graphic->plx4 = malloc(sizeof(paralax_t));
    graphic->coins = NULL;
    graphic->fences = NULL;
    graphic->coin_tex = sfTexture_createFromFile(\
    "./client/assets/coin.png", NULL);
    graphic->fence_tex = sfTexture_createFromFile(\
    "./client/assets/fences.png", NULL);
}

void init_game(graphic_t *graphic)
{
    init_cam(graphic);
    init_plx1(graphic);
    init_plx2(graphic);
    init_plx3(graphic);
    init_plx4(graphic);
    init_ply_fly1(graphic);
    init_ply_fly2(graphic);
}

void init_graphic(graphic_t *graphic, engine_t *eng)
{
    init_struct(graphic);
    init_window(graphic);
    init_game(graphic);
    init_loader(graphic);
    init_scoreboard(graphic);
    init_finish_line(graphic, eng);
    init_ply1_menu(graphic);
    init_ply2_menu(graphic);
    init_score1(graphic);
    init_score2(graphic);
    mutex_lock(&eng->network->lock);
    eng->network->csfml_ready = true;
    mutex_unlock(&eng->network->lock);
    graphic->music = sfMusic_createFromFile(\
    "./client/assets/floral_fleury.ogg");
    sfMusic_setLoop(graphic->music, sfTrue);
    sfMusic_play(graphic->music);
}

void init_csfml(engine_t *eng)
{
    graphic_t *graphic = malloc(sizeof(graphic_t));

    init_graphic(graphic, eng);
    while (sfRenderWindow_isOpen(graphic->rdr->window)) {
        sfRenderWindow_clear(graphic->rdr->window, sfBlack);
        event_loop(graphic, eng->network);
        anim(graphic, eng);
        display(graphic, eng);
        sfRenderWindow_display(graphic->rdr->window);
    }
    mutex_lock(&eng->network->lock);
    eng->network->exit = true;
    mutex_unlock(&eng->network->lock);
    destroy_graphic(graphic);
}