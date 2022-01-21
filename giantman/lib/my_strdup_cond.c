/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** duplicating a string
*/

#include "my.h"
#include <stdlib.h>

char *my_str_dup_cond(const char *str, char cond)
{
    char *dup;
    int size;
    int nb_cond = 0;
    int i;

    for (size = 0; str[size] != cond || str[size + 1] != cond; ++size);
    printf("%i %i %i\n", size, str[size], str[size - 1]);
    dup = malloc(sizeof(char) * (size + 1));
    for (i = 0; i < size; i++) {
        dup[i] = str[i];
    }
    return dup;
}
