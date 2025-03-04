/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-nathan.cheynet
** File description:
** tests_my_error_gestion.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/stat.h>
#include <unistd.h>

#include "settingup.h"
#include "my.h"
#include "error.h"

Test(error_gestion, isvalid_first_line_valid)
{
    cr_assert_eq(isvalid_first_line("123\n"), SUCCESS);
}

Test(error_gestion, isvalid_first_line_invalid)
{
    cr_assert_eq(isvalid_first_line("12a3\n"), FAILURE);
    cr_assert_eq(isvalid_first_line("12.3\n"), FAILURE);
    cr_redirect_stderr();
    display_error(INVALID_FIRST_LINE);
    cr_assert_stderr_eq_str("Error: the first line of the file is an incorrect format\n");
}

Test(error_gestion, isvalid_line_no_backslash)
{
    cr_assert_eq(isvalid_first_line("123"), SUCCESS);
}

Test(error_gestion, isvalid_map_valid)
{
    char **map = malloc(sizeof(char *) * 4);
    map[0] = strdup("ooooo");
    map[1] = strdup("o...o");
    map[2] = strdup("ooooo");
    map[3] = NULL;
    int res = isvalid_map(map, 3, "3\n");
    cr_assert_eq(res, SUCCESS);
    free_map(map);
}

/*Test(error_gestion, isvalid_map_inconsistent_cols)
{
    char *map[] = {"ooooo", "o....o", NULL};
    int res = isvalid_map(map, 3, "3\nooooo\no....o\n");
    cr_assert_eq(res, FAILURE);
    //free_map(map);
}

Test(error_gestion, isvalid_map_invalid_rows)
{
    char **map = malloc(sizeof(char *) * 3);
    map[0] = strdup("ooooo");
    map[1] = strdup("ooooo");
    map[2] = NULL;
    int res = isvalid_map(map, 1, "1\nooooo\nooooo\n");
    cr_assert_eq(res, FAILURE);
    free_map(map);
}*/

Test(error_gestion, isvalid_file_valid)
{
    struct stat st;
    stat("src/main.c", &st);
    cr_assert_eq(isvalid_file("src/main.c", &st), SUCCESS);
}

Test(error_gestion, isvalid_file_not_found)
{
    struct stat st;
    cr_assert_eq(isvalid_file("non_existent.txt", &st), FAILURE);
}

Test(error_gestion, isvalid_file_not_regular)
{
    struct stat st;
    stat("src", &st);
    cr_assert_eq(isvalid_file("src", &st), FAILURE);
}

Test(error_gestion, isvalid_args_valid)
{
    char const *argv[] = {"./program", "10", ".o"};
    cr_assert_eq(isvalid_args(3, argv), SUCCESS);
}

Test(error_gestion, isvalid_args_invalid_argc)
{
    char const *argv[] = {"./program"};
    cr_assert_eq(isvalid_args(1, argv), FAILURE);
}

Test(error_gestion, isvalid_args_invalid_size)
{
    char const *argv[] = {"./program", "-10", ".o"};
    cr_assert_eq(isvalid_args(3, argv), FAILURE);
}

Test(error_gestion, isvalid_args_invalid_pattern)
{
    char const *argv[] = {"./program", "10", "invalid"};
    cr_assert_eq(isvalid_args(3, argv), FAILURE);
}

Test(error_gestion, isvalid_args_pattern_empty)
{
    char const *argv[] = {"./program", "10", ""};
    cr_assert_eq(isvalid_args(3, argv), FAILURE);
}
