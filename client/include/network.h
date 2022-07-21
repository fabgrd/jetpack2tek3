/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** network.h
*/

#pragma once


#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>

#define soaddr_t struct sockaddr *
#define soin struct sockaddr_in
#define UNUSED __attribute__((unused))

typedef struct network network_t;
typedef pthread_mutex_t mutex_t;
typedef struct command command_t;

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
    int x;
    int y;
    ivec2 size;
    mutex_t lock;
} map_t;

typedef struct net_ply {
    int score;
    dvec2 pos;
    mutex_t lock;
} net_ply_t;

struct command {
    char *name;
    void (*callback)(network_t *, char **);
    command_t *next;
};

typedef struct game {
    int winner;
    bool started;
    net_ply_t ply1;
    net_ply_t ply2;
    mutex_t lock;
} game_t;

typedef struct buffer {
    int readptr;
    int writeptr;
    char buffer[4096];
} buffer_t;

struct network {
    char *clearip;
    int port;
    int socket;
    int max_sd;
    fd_set fdin;
    fd_set fdout;
    struct protoent *protocol;
    struct sockaddr_in sin;
    game_t game;
    command_t *cmds;
    pthread_t thread;
    mutex_t lock;
    char *message;
    char rdbuffer[4096];
    buffer_t buffer;
    int id;
    bool exit;
    map_t map;
    bool csfml_ready;
    bool map_ready;
    bool ready;
    bool coins_created;

};

void *start_thread(void *net);
void broadcast(network_t *net, const char *msg);
int read_server(network_t *net);

void init_network(network_t *net);
void get_network_data(network_t *net);

void command_id(UNUSED network_t *net, char **args);
void command_map(network_t *net, char **args);
void command_player(network_t *net, char **args);
void command_coins(network_t *net, char **args);
void command_finish(network_t *net, char **args);
void command_start(network_t *net, char **args);

void register_all_commands(network_t *srv);
void handle_server_command(network_t *net);
void exec_cmd(network_t *srv, char **tab);
command_t *get_server_cmd(network_t *srv, char *name);
void register_cmd(network_t *srv, char *name, void (*cb)(network_t *, char **));

int	mutex_unlock(mutex_t *mutex);
int	mutex_lock(mutex_t *mutex);
void mutex_init(mutex_t *mutex);
void wait_mutex(mutex_t *mutex);
void init_thread(network_t *net);

void send_message(network_t *net);
void buffer_write(network_t *net, const char *value);


void format_map(map_t *map);