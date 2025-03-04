/*
** EPITECH PROJECT, 2024
** display_functions
** File description:
** display functions for the setting_up program
*/

#include <unistd.h>

#include "error.h"

static const int error_msg_size[] = {
    35, 27, 36, 25, 39, 39,
    38, 38, 50, 50, 42, 57};

static const char *error_msg[] = {
    "Error: invalid number of arguments\n",
    "Error: invalid size of map\n",
    "Error: invalid character in pattern\n",
    "Error: file do not exist\n",
    "Error: the type of file is not regular\n",
    "Error: during the openning of the file\n",
    "Error: during the reading of the file\n",
    "Error: during the closing of the file\n",
    "Error: the size and the nbr of rows are different\n",
    "Error: the size and the nbr of cols are different\n",
    "Error: during the allocation of the cache\n",
    "Error: the first line of the file is an incorrect format\n", NULL};

int display_error(error_type_t error)
{
    write(2, error_msg[error], error_msg_size[error]);
    return FAILURE;
}

void display_map(char **map, int cols_size)
{
    int row = 0;

    while (map[row] != NULL) {
        write(1, map[row], cols_size);
        write(1, "\n", 1);
        row += 1;
    }
}
