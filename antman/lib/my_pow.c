/*
** EPITECH PROJECT, 2021
** Project Name
** File description:
** pow
*/

#include "../include/my.h"

int my_power(int nb, int p)
{
    int result = 1;

    if (p < 0) {
        return 0;
    }
    for (;p > 0; p--) {
        result *= nb;
    }
    return (result);
}
