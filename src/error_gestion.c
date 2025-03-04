/*
** EPITECH PROJECT, 2024
** error_gestion
** File description:
** handle the error gestion of setting_up
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "my.h"
#include "error.h"

int isvalid_first_line(char *line)
{
    int index = 0;

    while (line[index] != '\n' && line[index] != '\0') {
        if (line[index] < '0' || line[index] > '9')
            return FAILURE;
        index += 1;
    }
    return SUCCESS;
}

int isvalid_char(char *line)
{
    int index = 0;

    while (line[index] != '\0') {
        if (line[index] != '.' && line[index] != 'o')
            return display_error(PATTERN);
        index += 1;
    }
    return SUCCESS;
}

int isvalid_map(char **map, int size, char *first_line)
{
    int cols_size = my_strlen(map[0]);
    int rows = 0;

    if (isvalid_first_line(first_line) != SUCCESS) {
        free(first_line);
        return display_error(INVALID_FIRST_LINE);
    }
    while (map[rows] != NULL) {
        if (my_strlen(map[rows]) != cols_size) {
            free(first_line);
            return display_error(INVALID_COLS_SIZE);
        }
        rows += 1;
    }
    if (rows != size) {
        free(first_line);
        return display_error(INVALID_ROWS_SIZE);
    }
    return SUCCESS;
}

int isvalid_file(char const *filepath, struct stat *st)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1 || close(fd) == -1)
        return display_error(FILE_NOT_FOUND);
    if ((st->st_mode & S_IFMT) != S_IFREG)
        return display_error(FILE_NOT_REGULAR);
    return SUCCESS;
}

int isvalid_args(int argc, char const *argv[])
{
    if (argc < 2 || argc > 3)
        return display_error(ARGC);
    if ((argc == 3 && my_getnbr(argv[1]) <= 0) || (argc == 3 &&
            isvalid_first_line((char *)argv[1]) != SUCCESS))
        return display_error(SIZE);
    if (argc == 3 && argv[2][0] == '\0')
        return display_error(PATTERN);
    if (argc == 3 && isvalid_char((char *)argv[2]) != SUCCESS)
            return FAILURE;
    return SUCCESS;
}
