/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-settingup-nathan.cheynet
** File description:
** special_case.c
*/

#include <stddef.h>

#include "settingup.h"

char **replace_single_col(char **map)
{
    int index = 0;

    while (map[index] != NULL) {
        if (map[index][0] == '.') {
            map[index][0] = 'x';
            break;
        }
        index += 1;
    }
    return map;
}

char **replace_single_row(char **map)
{
    int index = 0;

    while (map[0][index] != '\0') {
        if (map[0][index] == '.') {
            map[0][index] = 'x';
            break;
        }
        index += 1;
    }
    return map;
}

square_t check_first_row_and_col(char **map, square_t square)
{
    for (int col = 0; map[0][col] != '\0'; col++) {
        if (map[0][col] == '.' &&
            (col < square.max_cols || square.max_rows >= 0)) {
            square.max_size = 1;
            square.max_rows = 0;
            square.max_cols = col;
            return square;
        }
    }
    for (int row = 1; map[row] != NULL; row++) {
        if (map[row][0] == '.' &&
            (row < square.max_rows || square.max_cols >= 0)) {
            square.max_size = 1;
            square.max_rows = row;
            square.max_cols = 0;
            return square;
        }
    }
    return square;
}
