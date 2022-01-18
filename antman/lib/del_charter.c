/*
** EPITECH PROJECT, 2021
** Project Name
** File description:
** destroy charter
*/

#include "../include/my.h"

void destroy_charter_t(charter_t *charter)
{
    free(charter->huff);
    free(charter);
}
