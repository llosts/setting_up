/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** find the biggest square and display it
*/

#include "settingup.h"
#include "mymacros.h"
#include "error.h"
#include "my.h"

char **mark_largest_square(char **map, square_t square)
{
    int rows = square.max_rows - square.max_size + 1;
    int cols = 0;

    while (rows <= square.max_rows) {
        cols = square.max_cols - square.max_size + 1;
        while (cols <= square.max_cols) {
            map[rows][cols] = 'x';
            cols += 1;
        }
        rows += 1;
    }
    return map;
}

square_t update_cache(char **map, int **cache, square_t square)
{
    int rows = square.rows;
    int cols = square.cols;

    if (map[rows][cols] == '.') {
        cache[rows][cols] = MIN(cache[rows - 1][cols], cache[rows][cols - 1],
            cache[rows - 1][cols - 1]) + 1;
    }
    if (cache[rows][cols] > square.max_size) {
        square.max_size = cache[rows][cols];
        square.max_rows = rows;
        square.max_cols = cols;
    }
    return square;
}

void initialise_square_infos(square_t *square)
{
    square->max_size = 0;
    square->max_rows = 0;
    square->max_cols = 0;
    square->rows = 0;
    square->cols = 0;
}

char **find_largest_square(char **map, int **cache)
{
    square_t square;
    int rows = 1;
    int cols = 0;

    initialise_square_infos(&square);
    while (map[rows] != NULL) {
        cols = 1;
        while (map[rows][cols] != '\0') {
            square.rows = rows;
            square.cols = cols;
            square = update_cache(map, cache, square);
            cols += 1;
        }
        rows += 1;
    }
    if (square.max_size <= 1)
        square = check_first_row_and_col(map, square);
    return mark_largest_square(map, square);
}

int setting_up(char **map, int size)
{
    int cols_size = my_strlen(map[0]);
    int **cache = allocate_cache(map, size, cols_size);

    if (!cache)
        return display_error(CACHE);
    if (size == 1)
        map = replace_single_row(map);
    else if (cols_size == 1)
        map = replace_single_col(map);
    else
        map = find_largest_square(map, cache);
    display_map(map, cols_size);
    free_ressources(map, cache, size);
    return SUCCESS;
}
