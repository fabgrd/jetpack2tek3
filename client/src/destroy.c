/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-jetpack2tek3-fabien.giraudier
** File description:
** destroy
*/

#include "jetpack.h"

void destroy_coins(graphic_t *graphic)
{
    object_t *object;
    for (object_t *pt = graphic->coins; pt != NULL;) {
        sfSprite_destroy(pt->sp);
        sfClock_destroy(pt->clock);
        object = pt;
        pt = pt->next;
        free(object);
    }

    for (object_t *pt = graphic->fences; pt != NULL;) {
        sfSprite_destroy(pt->sp);
        sfClock_destroy(pt->clock);
        object = pt;
        pt = pt->next;
        free(object);
    }
}

void destroy_cmds(network_t *net)
{
    command_t *tmp;
    for (command_t *pt = net->cmds; pt != NULL;) {
        tmp = pt;
        pt = pt->next;
        free(tmp);
    }
}

void destroy_network(network_t *net)
{
    free_array(net->map.map);
    free(net->map.strmap);
    destroy_cmds(net);
    free(net);
}

void destroy_score(graphic_t *graphic)
{
    sfText_destroy(graphic->scr_ply1->txt);
    sfText_destroy(graphic->scr_ply2->txt);
    sfFont_destroy(graphic->scr_ply1->font);
    destroy_ply(graphic->ply1);
    destroy_ply(graphic->ply2);
    destroy_ply(graphic->ply1_m);
    destroy_ply(graphic->ply2_m);
    destroy_obj(graphic->loader);
    destroy_para(graphic->plx1);
    destroy_para(graphic->plx2);
    destroy_para(graphic->plx3);
    destroy_para(graphic->plx4);
    destroy_para(graphic->scr_brd);
}

void destroy_graphic(graphic_t *graphic)
{
    sfView_destroy(graphic->cam);
    sfMusic_destroy(graphic->music);
    destroy_coins(graphic);
    sfTexture_destroy(graphic->coin_tex);
    sfTexture_destroy(graphic->fence_tex);
    sfRenderWindow_destroy(graphic->rdr->window);
    destroy_score(graphic);
    free(graphic->scr_ply1);
    free(graphic->scr_ply2);
    free(graphic->rdr);
    free(graphic);
}