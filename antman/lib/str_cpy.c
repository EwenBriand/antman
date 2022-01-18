/*
** EPITECH PROJECT, 2021
** Project Name
** File description:
** str copy
*/

#include "../include/my.h"

char *str_copy(char *copy)
{
    int len = my_strlen(copy);
    char *my_copy = malloc(sizeof(char) * len);

    for (int i = 0; i < len; ++i) {
        my_copy[i] = copy[i];
    }
    my_copy[len] = '\0';

    return my_copy;
}
