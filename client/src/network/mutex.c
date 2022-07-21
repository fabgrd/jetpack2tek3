/*
** EPITECH PROJECT, 2022
** jetpack
** File description:
** mutex.c
*/

#include "jetpack.h"

void mutex_init(mutex_t *mutex)
{
    *mutex = (mutex_t)PTHREAD_MUTEX_INITIALIZER;
}

int	mutex_lock(mutex_t *mutex)
{
    return (pthread_mutex_lock(mutex));
}

int	mutex_unlock(mutex_t *mutex)
{
    return (pthread_mutex_unlock(mutex));
}

void wait_mutex(mutex_t *mutex)
{
    mutex_lock(mutex);
    mutex_unlock(mutex);
}