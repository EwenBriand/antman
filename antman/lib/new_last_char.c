/*
** EPITECH PROJECT, 2022
** Project Name
** File description:
** creat the last char of the alpha
*/

#include "../include/my.h"

charter_t *new_last_char(void)
{
    charter_t *new = malloc(sizeof(charter_t));
    new->last_char = 1;
    new->c = '\0';
    new->nb_it = 0;

    return new;
}
