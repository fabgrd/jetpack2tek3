/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** map.c
*/

#include "jetpack.h"

void format_map(map_t *map)
{
    map->map = malloc(sizeof(char *) * (map->size.y + 1));
    int counter = 0;

    for (int i = 0; i < map->size.y; i++) {
        map->map[i] = malloc(sizeof(char) * map->size.x);
        for (int j = 0; j < map->size.x; j++, counter++) {
            map->map[i][j] = *(map->strmap + counter);
        }
    }
    map->map[map->size.y] = NULL;
}

sfVector2f get_camera_position(graphic_t *gr, network_t *net)
{
    sfVideoMode m = gr->rdr->quality;
    sfVector2f pos = { gr->ply1->pos.x + m.width / 2, m.height / 2 };

    if ((pos.x + m.width / 2) > net->map.size.x * gr->tile_size)
        pos.x = (net->map.size.x * gr->tile_size) - m.width / 2;

    return pos;
}