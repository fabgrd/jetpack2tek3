/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** cmd.c
*/

#include "jetpack.h"

void register_cmd(network_t *srv, char *name, void (*cb)(network_t *, char **))
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

command_t *get_server_cmd(network_t *srv, char *name)
{
    command_t *cmd = srv->cmds;

    for (; cmd != NULL; cmd = cmd->next) {
        if (!strcasecmp(cmd->name, name))
            return cmd;
    }
    return NULL;
}

void exec_cmd(network_t *srv, char **tab)
{
    command_t *cmd;

    if (!tab[0] || !strcmp(tab[0], ""))
        return;
    cmd = get_server_cmd(srv, tab[0]);
    if (!cmd)
        return;
    cmd->callback(srv, tab);
}

void handle_server_command(network_t *net)
{
    char **split;
    char *cmd = net->message;

    if (!cmd || !strlen(cmd))
        return;
    split = my_str_split(cmd, " \n\r\t");
    if (split) {
        exec_cmd(net, split);
        free_array(split);
    }
}

void register_all_commands(network_t *net)
{
    register_cmd(net, "ID", &command_id);
    register_cmd(net, "MAP", &command_map);
    register_cmd(net, "PLAYER", &command_player);
    register_cmd(net, "COIN", &command_coins);
    register_cmd(net, "FINISH", &command_finish);
    register_cmd(net, "START", &command_start);
}