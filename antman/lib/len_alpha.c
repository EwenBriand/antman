/*
** EPITECH PROJECT, 2022
** Project Name
** File description:
** creat the last char of the alpha
*/

#include "../include/my.h"

int len_alpha(charter_t **my_alpha)
{
    int count = 0;
    for (count; my_alpha[count]->last_char == 0; ++count);
    return count;
}
