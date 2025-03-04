/*
** EPITECH PROJECT, 2024
** my_strncpy
** File description:
** copy n character of a string and return it
*/

#include <stddef.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int index = 0;

    if (src == NULL)
        return NULL;
    while (index < n && src[index] != '\0') {
        dest[index] = src[index];
        index += 1;
    }
    while (index < n) {
        dest[index] = '\0';
        index += 1;
    }
    return dest;
}
