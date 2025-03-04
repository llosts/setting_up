/*
** EPITECH PROJECT, 2024
** generate_or_read_map
** File description:
** read the file with the map or generate one
*/

#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "my.h"
#include "error.h"
#include "settingup.h"

char *file_to_buffer(char const *filepath, int size)
{
    int fd = open_file(filepath);
    char *buffer = malloc(sizeof(char) * (size + 1));

    if (!buffer) {
        close_file(fd);
        display_error(OPEN);
        return NULL;
    }
    if (fd == -1 || size == 0 || read_file(fd, buffer, size) != SUCCESS) {
        close_file(fd);
        free(buffer);
        return NULL;
    }
    if (close_file(fd) != SUCCESS) {
        free(buffer);
        return NULL;
    }
    return buffer;
}

char **get_map(char const *filepath, int byte_size, int *size)
{
    char *buffer = file_to_buffer(filepath, byte_size);
    char **map = NULL;
    int start = 0;

    if (!buffer)
        return NULL;
    *size = my_getnbr(buffer);
    while (buffer[start] != '\n')
        start += 1;
    map = my_str_to_word_array((char const *)&buffer[start + 1]);
    if (!map) {
        free(buffer);
        return NULL;
    }
    if (isvalid_map(map, *size, buffer) == FAILURE) {
        free_map(map);
        return NULL;
    }
    free(buffer);
    return map;
}

char **generate_map(char const *pattern, int size)
{
    char **map_generate = malloc(sizeof(char *) * (size + 1));
    int index = 0;
    int rows = 0;

    if (!map_generate || !pattern)
        return NULL;
    while (rows < size) {
        map_generate[rows] = malloc(sizeof(char) * (size + 1));
        if (!map_generate[rows]) {
            free_map(map_generate);
            return NULL;
        }
        for (int cols = 0; cols < size; cols += 1) {
            map_generate[rows][cols] = pattern[index];
            index = (pattern[index + 1] != '\0') ? index + 1 : 0;
        }
        map_generate[rows][size] = '\0';
        rows += 1;
    }
    return map_generate;
}

char **generate_or_read_map(int argc, char const *argv[], int *size)
{
    struct stat st;

    if (argc == 2 && stat(argv[1], &st) == -1)
        return NULL;
    if (argc == 2 && isvalid_file(argv[1], &st) != FAILURE)
        return get_map(argv[1], st.st_size, size);
    *size = my_getnbr(argv[1]);
    return generate_map(argv[2], *size);
}
