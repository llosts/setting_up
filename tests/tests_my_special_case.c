/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-nathan.cheynet
** File description:
** tests_my_special_case.c
*/

#include <criterion/criterion.h>
#include <stddef.h>
#include <stdlib.h>

#include "settingup.h"
#include <stdio.h>
Test(special_case, replace_single_col_with_dot)
{
    char **map = malloc(sizeof(char *) * 3);
    map[0] = strdup("o");
    map[1] = strdup(".");
    map[2] = NULL;
    map = replace_single_col(map);
    cr_assert_str_eq(map[0], "o");
    cr_assert_str_eq(map[1], "x");
    free_map(map);
}

Test(special_case, replace_single_col_no_dot)
{
    char **map = malloc(sizeof(char *) * 3);
    map[0] = strdup("o");
    map[1] = strdup("o");
    map[2] = NULL;
    map = replace_single_col(map);
    cr_assert_str_eq(map[0], "o");
    cr_assert_str_eq(map[1], "o");
    free_map(map);
}

Test(special_case, replace_single_row_with_dot)
{
    char **map = malloc(sizeof(char *) * 2);
    map[0] = strdup("....");
    map[1] = NULL;
    map = replace_single_row(map);
    cr_assert_str_eq(map[0], "x...");
    free_map(map);
}

Test(special_case, replace_single_row_no_dot)
{
    char **map = malloc(sizeof(char *) * 2);
    map[0] = strdup("oooo");
    map[1] = NULL;
    map = replace_single_row(map);
    cr_assert_str_eq(map[0], "oooo");
    free_map(map);
}

Test(special_case, check_first_row_with_dot)
{
    char *map[] = {"...o", "oooo", NULL};
    square_t square = { .max_size = 0, .max_rows = 0, .max_cols = 0 };

    square = check_first_row_and_col(map, square);
    cr_assert_eq(square.max_size, 1);
    cr_assert_eq(square.max_rows, 0);
    cr_assert_eq(square.max_cols, 0);
}

Test(special_case, check_first_col_with_dot)
{
    char *map[] = {"oooo", ".ooo", NULL};
    square_t square = { .max_size = 0, .max_rows = 0, .max_cols = 0 };

    square = check_first_row_and_col(map, square);
    cr_assert_eq(square.max_size, 1);
    cr_assert_eq(square.max_rows, 1);
    cr_assert_eq(square.max_cols, 0);
}

Test(special_case, check_first_row_and_col_no_dot)
{
    char *map[] = {"oooo", "oooo", NULL};
    square_t square = { .max_size = 0, .max_rows = -1, .max_cols = -1 };

    square = check_first_row_and_col(map, square);
    cr_assert_eq(square.max_size, 0);
    cr_assert_eq(square.max_rows, -1);
    cr_assert_eq(square.max_cols, -1);
}
