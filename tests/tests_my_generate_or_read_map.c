/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-nathan.cheynet
** File description:
** tests_my_generate_or_read_map.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/stat.h>

#include "settingup.h"
#include "my.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(generate_or_read_map, file_to_buffer_valid, .init = redirect_all_stdout)
{
    struct stat st;
    stat("tests/example_files/map.txt", &st);
    char *buffer = file_to_buffer("tests/example_files/map.txt", st.st_size);
    cr_assert_not_null(buffer);
    cr_assert_str_eq(buffer, "3\nooooo\no...o\nooooo\n");
    free(buffer);
}

Test(generate_or_read_map, file_to_buffer_invalid_path, .init = redirect_all_stdout)
{
    char *buffer = file_to_buffer("non_existent.txt", 10);
    cr_assert_null(buffer);
}

Test(generate_or_read_map, file_to_buffer_invalid_size, .init = redirect_all_stdout)
{
    char *buffer = file_to_buffer("tests/example_files/map.txt", -1);
    cr_assert_null(buffer);
}

Test(generate_or_read_map, get_map_valid)
{
    int size;
    struct stat st;
    stat("tests/example_files/map.txt", &st);
    char **map = get_map("tests/example_files/map.txt", st.st_size, &size);
    cr_assert_not_null(map);
    cr_assert_eq(size, 3);
    cr_assert_str_eq(map[0], "ooooo");
    cr_assert_str_eq(map[1], "o...o");
    cr_assert_str_eq(map[2], "ooooo");
    free_map(map);
}

Test(generate_or_read_map, get_map_invalid_map)
{
    int size;
    struct stat st;
    stat("tests/example_files/map.txt", &st);
    char **map = get_map("tests/example_files/invalid.txt", st.st_size, &size);
    cr_assert_null(map);
}

Test(generate_or_read_map, get_map_invalid_structure)
{
    int size;
    char **map = get_map("invalid_map.txt", 20, &size);
    cr_assert_null(map);
}

Test(generate_or_read_map, generate_map_valid)
{
    char **map = generate_map(".o", 3);
    cr_assert_not_null(map);
    cr_assert_str_eq(map[0], ".o.");
    cr_assert_str_eq(map[1], "o.o");
    cr_assert_str_eq(map[2], ".o.");
}

Test(generate_or_read_map, generate_or_read_map_invalid_size)
{
    int size = 0;
    char const *argv[] = {"./program", "0", ".....oo."};
    char **map = generate_or_read_map(3,argv, &size);
    cr_assert_eq(size, 0);
}

Test(generate_or_read_map, generate_or_read_map_valid_file)
{
    int size;
    char const *argv[] = {"./program", "tests/example_files/map.txt"};
    char **map = generate_or_read_map(2, argv, &size);
    cr_assert_not_null(map);
    cr_assert_eq(size, 3);
    free_map(map);
}

Test(generate_or_read_map, generate_or_read_map_generate)
{
    int size;
    char const *argv[] = {"./program", "3", ".o"};
    char **map = generate_or_read_map(3, argv, &size);
    cr_assert_not_null(map);
    cr_assert_eq(size, 3);
    cr_assert_str_eq(map[0], ".o.");
    cr_assert_str_eq(map[1], "o.o");
    cr_assert_str_eq(map[2], ".o.");
}

Test(generate_or_read_map, generate_or_read_map_invalid_file)
{
    int size;
    char const *argv[] = {"./program", "non_existent.txt"};
    char **map = generate_or_read_map(2, argv, &size);
    cr_assert_null(map);
}

Test(generate_or_read_map, generate_or_read_map_isvalid_file)
{
    int size;
    char const *argv[] = {"./program", "tests"};
    char **map = generate_or_read_map(2, argv, &size);
    cr_assert_null(map);
}

Test(generate_or_read_map, generate_or_read_map_invalid_args)
{
    int size;
    char const *argv[] = {"./program", "-3", ".o"};
    char **map = generate_or_read_map(3, argv, &size);
    cr_assert_null(map);
}

