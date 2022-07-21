/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** array.c
*/

#include "jetpack.h"

int get_array_length(char **arr)
{
    int i = 0;

    for (; arr[i]; i++);
    return i;
}

void buffer_write(network_t *net, const char *value)
{
    for (int i = 0; value[i]; i++) {
        int writeptr = net->buffer.writeptr;
        net->buffer.buffer[writeptr] = value[i];
        net->buffer.writeptr = (net->buffer.writeptr + 1) % 4096;
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

void push_back(object_t **head, object_t *new)
{
    object_t *pt = *head;

    if (pt == NULL) {
        *head = new;
        printf("new coin\n");
        return;
    }

    while (pt->next)
        pt = pt->next;
    pt->next = new;
}