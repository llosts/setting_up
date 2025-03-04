/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** allocate a string and return it
*/

#include <stddef.h>
#include <stdlib.h>

#include "my.h"

char *my_strdup(char const *str)
{
    int i = 0;
    int lenght = my_strlen(str);
    char *copy_str = malloc(sizeof(char) * lenght);

    if (str == NULL)
        return NULL;
    while (i < lenght) {
        copy_str[i] = str[i];
        i += 1;
    }
    copy_str[i] = '\0';
    return copy_str;
}
