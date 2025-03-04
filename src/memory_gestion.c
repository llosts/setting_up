/*
** EPITECH PROJECT, 2024
** memory_gestion.c
** File description:
** handle the memory allocate, init and free
*/

#include <stdlib.h>

#include "settingup.h"

void free_map(char **map)
{
    int index = 0;

    while (map[index] != NULL) {
        free(map[index]);
        index += 1;
    }
    free(map);
}

void free_ressources(char **map, int **cache, int size)
{
    int index = 0;

    while (index < size) {
        free(map[index]);
        free(cache[index]);
        index += 1;
    }
    free(map);
    free(cache);
}

int *initialise_cache(char *map, int *cache)
{
    int cols = 0;

    while (map[cols] != '\0') {
        cache[cols] = (map[cols] == 'o') ? 0 : 1;
        cols += 1;
    }
    return cache;
}

int **allocate_cache(char **map, int size, int cols_size)
{
    int **cache = malloc(sizeof(int *) * size);
    int index = 0;

    while (map[index] != NULL) {
        cache[index] = malloc(sizeof(int) * cols_size);
        if (!cache[index]) {
            free_ressources(map, cache, size);
            return NULL;
        }
        cache[index] = initialise_cache(map[index], cache[index]);
        index += 1;
    }
    return cache;
}
