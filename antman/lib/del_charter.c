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

void destroy_all_charter(charter_t *my_alpha)
{
    if (my_alpha->c != '\0') {
        free(my_alpha->huff);
        free(my_alpha);
    } else if (my_alpha->last_char == 1)
        free(my_alpha);
    else {
        free(my_alpha->huff);
        destroy_all_charter(my_alpha->left);
        destroy_all_charter(my_alpha->right);
        free(my_alpha);
    }
}

void destroy_alpha(charter_t **my_alpha)
{
    int len = len_alpha(my_alpha);

    for (int i = 0; i < len + 1; ++i){
        destroy_all_charter(my_alpha[i]);
    }
    free(my_alpha);
}
