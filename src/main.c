/*
** EPITECH PROJECT, 2024
** main
** File description:
** main function for setting_up program
*/

#include <stddef.h>

#include "error.h"
#include "settingup.h"
#include <stdio.h>
int main(int argc, char const *argv[])
{
    char **map = NULL;
    int row_size = 0;

    if (isvalid_args(argc, argv) != SUCCESS)
        return FAILURE;
    map = generate_or_read_map(argc, argv, &row_size);
    if (!map)
        return FAILURE;
    return setting_up(map, row_size);
}
