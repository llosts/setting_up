/*
** EPITECH PROJECT, 2024
** settingup.h
** File description:
** header file for setting_up program
*/

#include <stddef.h>

#ifndef SETTINGUP_H_
    #define SETTINGUP_H_

typedef struct square_s {
    int max_size;
    int max_rows;
    int max_cols;
    int rows;
    int cols;
} square_t;

int setting_up(char **map, int size);
char **find_largest_square(char **map, int **cache);
char **mark_largest_square(char **map, square_t square);
square_t update_cache(char **map, int **cache, square_t square);
void initialise_square_infos(square_t *square);

void free_map(char **map);
void free_ressources(char **map, int **cache, int size);
int *initialise_cache(char *map, int *cache);
int **allocate_cache(char **map, int size, int cols_size);

char *file_to_buffer(char const *filepath, int size);
char **generate_or_read_map(int argc, char const *argv[], int *size);
char **get_map(char const *filepath, int byte_size, int *size);
char **generate_map(char const *pattern, int size);

square_t check_first_row_and_col(char **map, square_t square);
char **replace_single_col(char **map);
char **replace_single_row(char **map);

void display_map(char **map, int size);

int open_file(char const *filepath);
int read_file(int fd, char *buffer, int size);
int close_file(int fd);

#endif
