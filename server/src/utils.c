/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** utils.c
*/

#include "server.h"

bool file_exists(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    bool is_exist = false;
    if (fp != NULL) {
        is_exist = true;
        fclose(fp);
    }
    return is_exist;
}

char *load_file(char *path)
{
    struct stat f_stat;
    int buffsize;
    char *memory = malloc(sizeof(char));
    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        memory[0] = '\0';
        return memory;
    }
    stat(path, &f_stat);
    buffsize = f_stat.st_size;
    free(memory);
    memory = malloc(sizeof(char) * (buffsize + 1));
    read(fd, memory, buffsize);
    memory[buffsize] = '\0';
    close(fd);
    return (memory);
}

vec2 get_map_size(map_t map)
{
    vec2 size;

    for (size.y = 0; map.map[size.y]; size.y++)
        for (size.x = 0; map.map[size.y][size.x]; size.x++);
    return size;
}

void init_map(server_t *srv)
{
    srv->map.strmap = load_file(srv->map.path);
    srv->map.map = my_str_split(srv->map.strmap, "\n");
    delete_char(srv->map.strmap, '\n');
    srv->map.size = get_map_size(srv->map);
}