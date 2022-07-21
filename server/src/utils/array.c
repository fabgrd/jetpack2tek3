/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** array.c
*/

#include "server.h"

int get_array_length(char **arr)
{
    int i = 0;

    for (; arr[i]; i++);
    return i;
}

void buffer_write(client_t *cli, const char *value)
{
    for (int i = 0; value[i]; i++) {
        int writeptr = cli->buffer.writeptr;
        cli->buffer.buffer[writeptr] = value[i];
        cli->buffer.writeptr = (cli->buffer.writeptr + 1) % 4096;
    }
}

void free_array(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

int is_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return 0;
    return 1;
}