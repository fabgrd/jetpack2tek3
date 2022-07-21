/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** server.h
*/

#pragma once

#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <signal.h>
#include <uuid/uuid.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#include <signal.h>

#include "map.h"

#define soaddr_t struct sockaddr *
#define UNUSED __attribute__((unused))
typedef struct command command_t;
typedef struct client client_t;
typedef struct server server_t;

enum game_state {
    FINISHED,
    RUNNING,
    ERROR
};

struct command {
    char *name;
    void (*callback)(server_t *, client_t *, char **);
    command_t *next;
};

typedef struct game {
    float gravity;
    bool started;
    int winner;
} game_t;

typedef struct player {
    dvec2 pos;
    dvec2 speed;
    dvec2 velocity;
    double max;

} player_t;

typedef struct buffer {
    int readptr;
    int writeptr;
    char buffer[4096];
} buffer_t;

struct client {
    int sockfd;
    struct sockaddr_in address;
    ssize_t ip;
    int len_addr;
    player_t ply;
    char *message;
    buffer_t buffer;
    int hasId;
    int hasMap;
    int isReady;
    int fire;
    int coins;
};

struct server {
    fd_set fdin;
    fd_set fdout;
    map_t map;
    int socket;
    int max_sd;
    struct protoent *protocol;
    struct sockaddr_in sin;
    command_t *cmds;
    client_t *clients;
    int port;
    game_t game;
};

void throw(int exitCode, char *reason);

//Utils
bool file_exists(const char *filename);
char *my_get_next_line(const int fd);
char **my_str_split(char *str, char *del);
void init_map(server_t *srv);
int my_str_find(char *c, char *arr);
void delete_char(char *str, char c);

//Array
int get_array_length(char **arr);
void free_array(char **tab);
int is_number(char *str);

//Client
void remove_client(server_t *srv, int id);
void init_clients(server_t *server);
void client_loop(server_t *srv);
int read_client(server_t *srv, int id);
void register_client(server_t *srv);
bool all_ready(server_t *server);

void register_cmd(server_t *, char *,
void (*)(server_t *, client_t *, char **));
command_t *get_server_cmd(server_t *srv, char *name);
void exec_cmd(server_t *srv, char **tab, client_t *clt);
void handle_client_command(server_t *server, int id);
void register_all_commands(server_t *srv);

void get_args(server_t *srv, int ac, char **av);

//server
void network_loop(server_t *srv);
void get_server_data(server_t *server);
void init_server(server_t *srv);


// Commands
void command_id(server_t *srv, client_t *cli, char **args);
void command_map(server_t *srv, client_t *cli, char **args);
void command_ready(server_t *srv, client_t *cli, char **args);
void command_fire(UNUSED server_t *srv, client_t *cli, char **args);

void broadcast_all(server_t *srv, const char *msg);
void broadcast(client_t *cli, const char *msg);
void game_loop(server_t *srv);
void move_player(server_t *srv, client_t *cli, double time);
int check_colliders(server_t *srv, client_t *cli, char *buff, size_t *);
void send_message(client_t *cli);

void buffer_write(client_t *cli, const char *value);