/*
** EPITECH PROJECT, 2021
** Project Name
** File description:
** strcat
*/

#include "../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int l_dest = my_strlen(dest);
    char *result = malloc(sizeof(char) * (my_strlen(src) + l_dest + 1));

    while (dest[i] != '\0') {
        result[i] = dest[i];
        i++;
    }
    for (int j = 0; src[j] != '\0'; ++j) {
        result[i] = src[j];
        i++;
    }
    result[i] = '\0';
    return result;
}
