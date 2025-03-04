/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-nathan.cheynet
** File description:
** tests_my_setting_up.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "error.h"
#include "settingup.h"
#include "my.h"

Test(setting_up, mark_largest_square_valid)
{
    char **map = malloc(sizeof(char *) * 4);
    square_t square = { .max_size = 3, .max_rows = 2, .max_cols = 2 };
    map[0] = strdup(".....");
    map[1] = strdup(".....");
    map[2] = strdup(".....");
    map[3] = NULL;
    map = mark_largest_square(map, square);
    cr_assert_str_eq(map[0], "xxx..");
    cr_assert_str_eq(map[1], "xxx..");
    cr_assert_str_eq(map[2], "xxx..");
    for (int i = 0; i < 3; i++) free(map[i]);
    free(map);
}

Test(setting_up, mark_largest_square_no_square)
{
    char *map[] = {".....", ".....", ".....", NULL};
    square_t square = { .max_size = 0, .max_rows = 0, .max_cols = 0 };

    char **result = mark_largest_square(map, square);
    cr_assert_str_eq(result[0], ".....");
}

Test(setting_up, update_cache_valid)
{
    char *map[] = {".....", "..o..", ".....", NULL};
    int *cache[] = {calloc(5, sizeof(int)), calloc(5, sizeof(int)), calloc(5, sizeof(int))};
    cache[1][1] = 1;
    square_t square = { .max_size = 0, .max_rows = 0, .max_cols = 0, .rows = 2, .cols = 2 };

    square = update_cache(map, cache, square);
    cr_assert_eq(cache[2][2], 1);
    cr_assert_eq(square.max_size, 1);

    for (int i = 0; i < 3; i++) free(cache[i]);
}

Test(setting_up, initialise_square_infos_valid)
{
    square_t square;
    initialise_square_infos(&square);

    cr_assert_eq(square.max_size, 0);
    cr_assert_eq(square.max_rows, 0);
    cr_assert_eq(square.max_cols, 0);
    cr_assert_eq(square.rows, 0);
    cr_assert_eq(square.cols, 0);
}

Test(setting_up, find_largest_square_valid)
{
    char **map = malloc(sizeof(char *) * 4);
    map[0] = strdup(".....");
    map[1] = strdup("..o..");
    map[2] = strdup(".....");
    map[3] = NULL;
    int **cache = allocate_cache(map, 3, 5);
    map = find_largest_square(map, cache);
    cr_assert_str_eq(map[0], "xx...");
    cr_assert_str_eq(map[1], "xxo..");
    cr_assert_str_eq(map[2], ".....");

    for (int i = 0; i < 3; i++) {
        free(cache[i]);
        free(map[i]);
    }
    free(cache);
    free(map);
}

Test(setting_up, setting_up_valid_single_row)
{
    char **map = malloc(sizeof(char *) * 2);
    int size = 1;
    map[0] = strdup(".....");
    map[1] = NULL;
    cr_redirect_stdout();
    int result = setting_up(map, size);
    cr_assert_stdout_eq_str("x....\n");
    cr_assert_eq(result, SUCCESS);
}

Test(setting_up, setting_up_valid_single_col)
{
    char **map = malloc(sizeof(char *) * 4);
    int size = 3;
    map[0] = strdup("o");
    map[1] = strdup(".");
    map[2] = strdup(".");
    map[3] = NULL;
    cr_redirect_stdout();
    int result = setting_up(map, size);
    cr_assert_stdout_eq_str("o\nx\n.\n");
    cr_assert_eq(result, SUCCESS);
}
