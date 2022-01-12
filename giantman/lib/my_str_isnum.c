/*
** EPITECH PROJECT, 2021
** my_str_isnum.c
** File description:
** my string is a number
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    for (int i; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}
