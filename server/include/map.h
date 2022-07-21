/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** map.h
*/

#pragma once

typedef struct dvec2_s {
    double x;
    double y;
} dvec2;

typedef struct ivec2_s {
    int x;
    int y;
} ivec2;

typedef struct vec2_s {
    unsigned long x;
    unsigned long y;
} vec2;

typedef struct map {
    char **map;
    char *strmap;
    char *path;
    vec2 size;

} map_t;