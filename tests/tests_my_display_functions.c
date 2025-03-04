/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-nathan.cheynet
** File description:
** tests_my_display_functions.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>

#include "error.h"
#include "settingup.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(display_functions, display_error_valid, .init = redirect_all_stdout)
{
    int result = display_error(ARGC);
    cr_assert_eq(result, FAILURE);
    cr_assert_stderr_eq_str("Error: invalid number of arguments\n");
}

Test(display_functions, display_map_valid, .init = redirect_all_stdout)
{
    char *map[] = {"#####", "#...#", "#####", NULL};
    display_map(map, 5);
    cr_assert_stdout_eq_str("#####\n#...#\n#####\n");
}

Test(display_functions, display_map_empty, .init = redirect_all_stdout)
{
    char *map[] = {NULL};
    display_map(map, 0);
    cr_assert_stdout_eq_str("");
}
