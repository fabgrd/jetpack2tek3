/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-jetpack2tek3-fabien.giraudier
** File description:
** jetpack
*/

#ifndef JETPACK_H_
#define JETPACK_H_

#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "network.h"

typedef struct score_s {
    sfFont *font;
    sfText *txt;
    char *str;
    sfVector2f pos;
} score_t;

typedef struct object_s {
    sfSprite *sp;
    sfTexture *tex;
    sfVector2f pos;
    sfVector2f move;
    sfVector2f scale;
    sfVector2i mouse;
    sfIntRect rect;
    sfTime time;
    sfClock *clock;
    float seconds;
    struct object_s *next;
} object_t;

typedef struct player_s {
    sfSprite *sp;
    sfTexture *tex;
    sfVector2f pos;
    sfVector2f move;
    sfVector2f scale;
    sfVector2i mouse;
    sfIntRect rect;
    sfTime time;
    sfClock *clock;
    float seconds;
} player_t;

typedef struct paralax_s {
    sfSprite *sp;
    sfTexture *tex;
    sfVector2f pos;
    sfIntRect rect;
    sfTime time;
    sfClock *clock;
    float seconds;
} paralax_t;

typedef struct render_s {
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode quality;
} render_t;

typedef struct graphic_s {
    sfView *cam;
    sfFloatRect cam_rect;
    sfVector2f cam_pos;
    sfMusic *music;
    double tile_size;
    sfTexture *coin_tex;
    sfTexture *fence_tex;
    struct render_s *rdr;
    struct object_s *coin;
    struct object_s *loader;
    struct player_s *ply1;
    struct player_s *ply2;
    struct player_s *ply1_m;
    struct player_s *ply2_m;
    struct paralax_s *fnsh;
    struct paralax_s *scr_brd;
    struct paralax_s *plx1;
    struct paralax_s *plx2;
    struct paralax_s *plx3;
    struct paralax_s *plx4;
    struct score_s *scr_ply1;
    struct score_s *scr_ply2;
    object_t *coins;
    object_t *fences;
} graphic_t;

typedef struct engine {
    network_t *network;
} engine_t;

// network
void throw(int exitCode, char *reason);
void get_args(engine_t *eng, int ac, char **av);
int is_number(char *str);
void init_csfml(engine_t *eng);
int get_next_line(const int fd, char **buff);
int my_str_find(char *c, char const *arr);
char **my_str_split(char const *str, char *del);
void free_array(char **tab);
// init
void init_graphic(graphic_t *graphic, engine_t *eng);
void init_struct(graphic_t *graphic);
void init_window(graphic_t *graphic);
void init_cam(graphic_t *graphic);
void init_game(graphic_t *graphic);
void init_score1(graphic_t *graphic);
void init_score2(graphic_t *graphic);
void find_ply_scr1(graphic_t *graphic, engine_t *eng);
void find_ply_scr2(graphic_t *graphic, engine_t *eng);
void init_ply_fly1(graphic_t *graphic);
void init_ply_fly2(graphic_t *graphic);
void init_ply1_menu(graphic_t *graphic);
void init_ply2_menu(graphic_t *graphic);
void init_loader(graphic_t *graphic);
void create_coin(graphic_t *graphic, sfVector2f pos);
void init_scoreboard(graphic_t *graphic);
void init_finish_line(graphic_t *graphic, engine_t *eng);
void init_plx1(graphic_t *graphic);
void init_plx2(graphic_t *graphic);
void init_plx3(graphic_t *graphic);
void init_plx4(graphic_t *graphic);
void event_loop(graphic_t *graphic, network_t *network);
void create_fence(graphic_t *graphic, sfVector2f pos);
// anim
void anim(graphic_t *graphic, engine_t *eng);
void anim_loader(graphic_t *graphic);
void coin_anim(object_t *);
void fences_anim(object_t *fences);
void game_animator(graphic_t *graphic, engine_t *eng);
void scoreboard_animator(graphic_t *graphic, engine_t *eng);
void ply_fly1(graphic_t *graphic, engine_t *eng);
void ply_fly2(graphic_t *graphic, engine_t *eng);
void ply1_menu_anim(graphic_t *graphic);
void ply2_menu_anim(graphic_t *graphic);
void move_plx1(graphic_t *graphic);
void move_plx2(graphic_t *graphic);
void move_plx3(graphic_t *graphic);
void move_plx4(graphic_t *graphic);
// display
void display(graphic_t *graphic, engine_t *eng);
void display_game(graphic_t *gr, engine_t *eng);
void display_scoreboard(graphic_t *gr);
void display_coins(graphic_t *graphic, engine_t *eng);
// destroy
void destroy_graphic(graphic_t *graphic);
void destroy_network(network_t *net);
void push_back(object_t **head, object_t *new);
void destroy_para(paralax_t *player);
void destroy_score(graphic_t *graphic);
void destroy_obj(object_t *player);
void destroy_ply(player_t *player);

sfVector2f get_camera_position(graphic_t *graphic, network_t *net);

#endif /* !JETPACK_H_ */