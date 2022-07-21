/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-jetpack2tek3-fabien.giraudier
** File description:
** event
*/

#include "jetpack.h"

void fire_event(graphic_t *graphic, network_t *net)
{
    if (graphic->rdr->event.type == sfEvtKeyPressed) {
        if (graphic->rdr->event.key.code == sfKeySpace)
            dprintf(net->socket, "FIRE 1\n");
    }
    if (graphic->rdr->event.type == sfEvtKeyReleased) {
        if (graphic->rdr->event.key.code == sfKeySpace)
            dprintf(net->socket, "FIRE 0\n");
    }
}

void event_loop(graphic_t *graphic, network_t *net)
{
    while (sfRenderWindow_pollEvent(graphic->rdr->window, \
    &graphic->rdr->event)) {
        if (graphic->rdr->event.type == sfEvtClosed)
            sfRenderWindow_close(graphic->rdr->window);
        fire_event(graphic, net);
    }
}

