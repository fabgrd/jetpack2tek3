/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-jetpack2tek3-fabien.giraudier
** File description:
** display
*/

#include "jetpack.h"

void display_coins(graphic_t *graphic, engine_t *eng)
{
    int s = graphic->tile_size;

    for (object_t *pt = graphic->coins; pt != NULL; pt = pt->next) {
        ivec2 pos = { (int)(pt->pos.x / s), (int)(pt->pos.y / s) };
        if (eng->network->map.map[pos.y][pos.x] == 'c') {
            sfRenderWindow_drawSprite(graphic->rdr->window, pt->sp, NULL);
            coin_anim(pt);
        }
    }
    for (object_t *pt = graphic->fences; pt != NULL; pt = pt->next) {
        ivec2 pos = { (int)(pt->pos.x / s), (int)(pt->pos.y / s) };
        if (eng->network->map.map[pos.y][pos.x] == 'e') {
            sfRenderWindow_drawSprite(graphic->rdr->window, pt->sp, NULL);
            fences_anim(pt);
        }
    }
}

void create_router(graphic_t *graphic, network_t *net, int i, int j)
{
    char **map = net->map.map;
    int s = graphic->tile_size;

    if (map[i][j] == 'c')
        create_coin(graphic, (sfVector2f){ j * s, i * s });
    else if (map[i][j] == 'e')
        create_fence(graphic, (sfVector2f){ j * s, i * s });
}

void create_coins(graphic_t *graphic, engine_t *eng)
{
    for (int i = 0; i < eng->network->map.size.y; ++i)
        for (int j = 0; j < eng->network->map.size.x; ++j)
            create_router(graphic, eng->network, i, j);
}

void display_game(graphic_t *gr, engine_t *eng)
{
    sfRenderWindow_drawSprite(gr->rdr->window, gr->plx4->sp, NULL);
    sfRenderWindow_drawSprite(gr->rdr->window, gr->plx3->sp, NULL);
    sfRenderWindow_drawSprite(gr->rdr->window, gr->plx2->sp, NULL);
    sfRenderWindow_drawSprite(gr->rdr->window, gr->plx1->sp, NULL);
    sfRenderWindow_drawSprite(gr->rdr->window, gr->fnsh->sp, NULL);
    sfRenderWindow_drawSprite(gr->rdr->window, gr->ply2->sp, NULL);
    sfRenderWindow_drawSprite(gr->rdr->window, gr->ply1->sp, NULL);
    mutex_lock(&eng->network->map.lock);
    display_coins(gr, eng);
    mutex_unlock(&eng->network->map.lock);
}

void display(graphic_t *gr, engine_t *eng)
{
    mutex_lock(&eng->network->game.lock);
    int winner = eng->network->game.winner;
    mutex_unlock(&eng->network->game.lock);
    if (eng->network->map_ready && !eng->network->coins_created) {
        gr->tile_size = 720 / eng->network->map.size.y;
        create_coins(gr, eng);
        mutex_lock(&eng->network->lock);
        eng->network->coins_created = true;
        mutex_unlock(&eng->network->lock);
    }
    if (winner == -2) {
        if (eng->network->game.started == false) {
            sfRenderWindow_drawSprite(gr->rdr->window, gr->loader->sp, NULL);
        }
        else if (eng->network->game.started == true) {
            display_game(gr, eng);
        }
    } else {
        display_scoreboard(gr);
    }
}