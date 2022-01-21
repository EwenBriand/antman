/*
** EPITECH PROJECT, 2022
** count_strspaces
** File description:
** count spaces of string
*/

#include "my.h"

int count_strspaces(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 32)
            count ++;
    }
    return count;
}
