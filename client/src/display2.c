/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-jetpack2tek3-fabien.giraudier
** File description:
** display2
*/

#include "jetpack.h"

void display_scoreboard(graphic_t *gr)
{
    sfRenderWindow_drawSprite(gr->rdr->window, gr->scr_brd->sp, NULL);
    sfRenderWindow_drawSprite(gr->rdr->window, gr->ply1_m->sp, NULL);
    sfRenderWindow_drawSprite(gr->rdr->window, gr->ply2_m->sp, NULL);
    sfRenderWindow_drawText(gr->rdr->window, gr->scr_ply1->txt, NULL);
    sfRenderWindow_drawText(gr->rdr->window, gr->scr_ply2->txt, NULL);
}
