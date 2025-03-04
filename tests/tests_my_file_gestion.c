/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-nathan.cheynet
** File description:
** tests_my_file_gestion.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <fcntl.h>

#include "settingup.h"
#include "error.h"

Test(open_file, valid_file)
{
    int fd = open_file("src/main.c");
    cr_assert_neq(fd, -1);
    close(fd);
}

Test(open_file, invalid_file)
{
    int fd = open_file("non_existent.txt");
    cr_assert_eq(fd, -1);
}

Test(read_file, valid_read)
{
    int fd = open("tests/example_files/intermediate_map_one_empty_box", O_RDONLY);
    char buffer[4];
    int result = read_file(fd, buffer, 4);
    cr_assert_eq(result, SUCCESS);
    close(fd);
}

Test(read_file, partial_read)
{
    int fd = open("tests/example_files/intermediate_map_one_empty_box", O_RDONLY);
    char buffer[20];
    int result = read_file(fd, buffer, 20);
    cr_assert_eq(result, FAILURE);
    close(fd);
}

Test(read_file, invalid_fd)
{
    char buffer[10];
    int result = read_file(-1, buffer, 10);
    cr_assert_eq(result, FAILURE);
}

Test(close_file, valid_fd)
{
    int fd = open("src/main.c", O_RDONLY);
    int result = close_file(fd);
    cr_assert_eq(result, SUCCESS);
}

Test(close_file, invalid_fd)
{
    int result = close_file(-1);
    cr_assert_eq(result, FAILURE);
}
