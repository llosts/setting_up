/*
** EPITECH PROJECT, 2024
** error.h
** File description:
** header file for the error gestion
*/

#include <sys/stat.h>
#include <stddef.h>

#ifndef ERROR_H_
    #define ERROR_H_

    #define FAILURE 84
    #define SUCCESS 0

typedef enum error_type {
    ARGC = 0,
    SIZE = 1,
    PATTERN = 2,
    FILE_NOT_FOUND = 3,
    FILE_NOT_REGULAR = 4,
    OPEN = 5,
    READ = 6,
    CLOSE = 7,
    INVALID_ROWS_SIZE = 8,
    INVALID_COLS_SIZE = 9,
    CACHE = 10,
    INVALID_FIRST_LINE = 11
} error_type_t;

int isvalid_first_line(char *first_line);
int isvalid_char(char *line);
int isvalid_map(char **map, int size, char *buffer);
int isvalid_file(char const *filepath, struct stat *st);
int isvalid_args(int argc, char const *argv[]);
int display_error(error_type_t type);

#endif
