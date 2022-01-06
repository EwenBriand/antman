/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** oui
*/

#include "../include/my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++) {
        my_putchar(str[i]);
    }
    return 0;
}
