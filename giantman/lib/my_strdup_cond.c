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

    for (size = 0; str[size] != cond; size++) {
    }
    dup = malloc(sizeof(char) * (size + 1));
    for (int i = 0; str[i] != cond; i++) {
        dup[i] = str[i];
    }
    return dup;
}
