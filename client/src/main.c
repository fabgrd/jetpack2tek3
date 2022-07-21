/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-jetpack2tek3-fabien.giraudier
** File description:
** main
*/

#include "jetpack.h"

void throw(int exitCode, char *reason)
{
    fprintf(stderr, "%s\n", reason);
    exit(exitCode);
}

int main(int ac, char **av)
{
    engine_t eng;

    if (ac % 2 == 0)
        return 84;
    if (ac <= 1)
        return 84;
    eng.network = malloc(sizeof(network_t));
    get_args(&eng, ac, av);
    init_network(eng.network);
    init_thread(eng.network);
    wait_mutex(&eng.network->lock);
    init_csfml(&eng);
    pthread_join(eng.network->thread, NULL);
    destroy_network(eng.network);
    return 0;
}
