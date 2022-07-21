/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** my_str_split.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int my_str_find(char *c, char const *arr)
{
    int res = 0;

    for (int i = 0; arr[i]; ++i)
        for (int j = 0; c[j]; ++j)
            res += (c[j] == arr[i]) ? 1 : 0;
    return res;
}

char **my_str_split(char const *str, char *del)
{
    char *buff = strdup(str);
    char len = my_str_find(del, buff) + 2;
    char **res = malloc(sizeof(char *) * len);
    char *token = strtok(buff, del);
    int i = 0;

    for (; token != NULL; i++) {
        res[i] = strdup(token);
        token = strtok(NULL, del);
    }
    res[i] = NULL;
    free(buff);
    return res;
}

int get_next_line(const int fd, char **buff)
{
    char buffer[2] = "";
    int size = 0;

    (*buff)[0] = '\0';
    for (;read(fd, buffer, 1) > 0; ++size) {
        strncat(*buff, buffer, 1);
        if (buffer[0] == '\n')
            break;
    }
    (*buff)[size] = '\0';
    return size;
}

void delete_char(char *str, char c)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] != c)
            continue;
        for (int j = i; str[j]; j++)
            str[j] = str[j + 1];
        i--;
    }
}