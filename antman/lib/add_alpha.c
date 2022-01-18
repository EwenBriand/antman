/*
** EPITECH PROJECT, 2021
** Project Name
** File description:
** add alpha to buff
*/

#include "../include/my.h"

char *add_alpha_to_buff(charter_t **my_alpha, char *str)
{
    int len_new_char = 0;
    char *new_char = malloc(sizeof(char) * 8 * len_alpha(my_alpha) * my_strlen(str));
    for (int i = 0; i < len_alpha(my_alpha); ++i) {
        new_char[len_new_char] = my_alpha[i]->c;
        new_char[len_new_char + 1] = '\0';
        my_strcat(new_char, my_alpha[i]->huff);
        len_new_char = my_strlen(new_char);
        new_char[len_new_char] = ' ';
        new_char[len_new_char + 1] = '\0';
        len_new_char = my_strlen(new_char);
    }
    new_char[len_new_char - 1] = '\n';
    new_char[len_new_char] = '\n';
    new_char[len_new_char + 1] = '\0';
    return new_char;
}
