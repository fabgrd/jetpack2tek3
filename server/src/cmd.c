/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** cmd.c
*/

#include "server.h"

void register_cmd(server_t *srv, char *name,
void (*cb)(server_t *, client_t *, char **))
{
    command_t *new = malloc(sizeof(command_t));
    command_t *cmd = srv->cmds;

    new->name = name;
    new->callback = cb;
    new->next = NULL;
    if (!cmd)
        srv->cmds = new;
    else {
        for (; cmd->next != NULL; cmd = cmd->next);
        cmd->next = new;
    }
}

command_t *get_server_cmd(server_t *srv, char *name)
{
    command_t *cmd = srv->cmds;

    for (; cmd != NULL; cmd = cmd->next) {
        if (!strcasecmp(cmd->name, name))
            return cmd;
    }
    return NULL;
}

void exec_cmd(server_t *srv, char **tab, client_t *clt)
{
    command_t *cmd;

    if (!tab[0] || !strcmp(tab[0], ""))
        return;
    cmd = get_server_cmd(srv, tab[0]);
    if (!cmd)
        return;
    cmd->callback(srv, clt, tab);
}

void handle_client_command(server_t *server, int id)
{
    char **split;
    char *cmd = server->clients[id].message;

    if (!cmd || !strlen(cmd))
        return;
    split = my_str_split(cmd, " \n\r\t");
    if (split) {
        exec_cmd(server, split, &server->clients[id]);
        free_array(split);
    }
}

void register_all_commands(server_t *srv)
{
    register_cmd(srv, "ID", &command_id);
    register_cmd(srv, "MAP", &command_map);
    register_cmd(srv, "READY", &command_ready);
    register_cmd(srv, "FIRE", &command_fire);
}