/*
** EPITECH PROJECT, 2021
** Project Name
** File description:
** base convertor
*/

#include "../include/my.h"

char *base(int nb, char *str)
{
    int power = 0;
    int temp = 0;
    int base = my_strlen(str);
    char *result;

    for (int i = 0; my_power(base, i) < nb; ++i) {
        power = i;
    }
    result = malloc(sizeof(char) * (power + 1));
    for (int i = power; i >= 0; --i) {
        temp = nb / my_power(base, i);
        result[power - i] = str[temp];
        nb -= temp * my_power(base, i);
    }
    result[power] = str[temp];
    result[power + 1] = '\0';
    return result;
}
