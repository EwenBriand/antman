/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** get a number
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int cnt = 0;
    int nb = 0;
    int temp = 1;

    for (cnt = 0; str[cnt] == '-' || str[cnt] == '+'; cnt++) {
        if (str[cnt] == '-' && str[cnt + 1] >= '0' && str[cnt + 1] <= '9') {
            temp = -1;
        }
    }
    for (cnt; str[cnt] >= '0' && str[cnt] <= '9'; cnt++) {
        if (my_str_isnum(str) == 1) {
            nb = nb * 10;
            nb = nb + (str[cnt] - 48);
        }
    }
    nb = nb * temp;
    return nb;
}
