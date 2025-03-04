/*
** EPITECH PROJECT, 2024
** file_gestion.c
** File description:
** gestion of file for open, read and close
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#include "my.h"
#include "error.h"

int open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return -1;
    return fd;
}

int read_file(int fd, char *buffer, int size)
{
    int nbr_read = read(fd, buffer, size);
    int index = 0;

    if (nbr_read == -1 || nbr_read != size)
        return display_error(READ);
    while (buffer[index] != '\n')
        index += 1;
    index += 1;
    for (int i = index; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            continue;
        if (buffer[i] != '.' && buffer[i] != 'o')
            return display_error(PATTERN);
    }
    return SUCCESS;
}

int close_file(int fd)
{
    if (close(fd) == -1)
        return display_error(CLOSE);
    return SUCCESS;
}
