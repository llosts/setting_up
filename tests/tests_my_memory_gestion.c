/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-nathan.cheynet
** File description:
** tests_my_memory_gestion.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "settingup.h"

Test(memory_gestion, free_map_valid)
{
    char **map = malloc(sizeof(char *) * 3);
    map[0] = strdup("ooooo");
    map[1] = strdup("o...o");
    map[2] = NULL;

    free_map(map);
    cr_assert(1);
}

Test(memory_gestion, free_map_empty)
{
    char **map = malloc(sizeof(char *));
    map[0] = NULL;

    free_map(map);
    cr_assert(1);
}

Test(memory_gestion, free_ressources_valid)
{
    char **map = malloc(sizeof(char *) * 3);
    int **cache = malloc(sizeof(int *) * 3);

    for (int i = 0; i < 2; i++) {
        map[i] = strdup("ooooo");
        cache[i] = malloc(sizeof(int) * 5);
    }
    map[2] = NULL;
    cache[2] = NULL;

    free_ressources(map, cache, 2);
    cr_assert(1);
}

Test(memory_gestion, initialise_cache_valid)
{
    char *map_row = "o.o.o";
    int *cache = malloc(sizeof(int) * 5);
    int *result = initialise_cache(map_row, cache);

    cr_assert_eq(result[0], 0);
    cr_assert_eq(result[1], 1);
    cr_assert_eq(result[2], 0);
    cr_assert_eq(result[3], 1);
    cr_assert_eq(result[4], 0);

    free(cache);
}

Test(memory_gestion, initialise_cache_empty)
{
    char *map_row = "";
    int *cache = malloc(sizeof(int));
    int *result = initialise_cache(map_row, cache);

    cr_assert_not_null(result);
    free(cache);
}

Test(memory_gestion, allocate_cache_valid)
{
    char *map[] = {"o.o..", "..oooo..", NULL};
    int **cache = allocate_cache(map, 3, 5);

    cr_assert_not_null(cache);
    cr_assert_eq(cache[0][0], 0);
    cr_assert_eq(cache[0][1], 1);
    cr_assert_eq(cache[1][0], 1);
}

Test(memory_gestion, allocate_cache_empty_map)
{
    char *map[] = {NULL};
    int **cache = allocate_cache(map, 0, 0);
    cr_assert_null(cache[1]);
}
