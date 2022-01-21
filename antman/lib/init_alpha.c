/*
** EPITECH PROJECT, 2021
** Project Name
** File description:
** init alpha
*/

#include "../include/my.h"

int nb_iteration(char *str, char c)
{
    int count = 0;
    int len = my_strlen(str);

    for (int i = 0; i < len; ++i) {
        if (str[i] == c)
            ++count;
    }
    return count;
}

void del_usless_char(charter_t **my_alpha)
{
    int j = 0;
    int type = 0;
    int len = len_alpha(my_alpha);

    for (int i = 0; i < len; ++i) {
        if (my_alpha[i]->nb_it == 0 && type == 0) {
            destroy_charter_t(my_alpha[i]);
            my_alpha[i] = new_last_char();
            type = 1;
        } else if (my_alpha[i]->nb_it == 0)
            destroy_charter_t(my_alpha[i]);
    }
}

void tri_alpha(charter_t **my_alpha)
{
    charter_t *temp;
    int finish = 0;
    int j;

    for (int i = 0; i < len_alpha(my_alpha) && finish == 0; ++i) {
        if (my_alpha[i]->nb_it == 0) {
            for (j = i; my_alpha[j]->nb_it == 0 && j < len_alpha(my_alpha); ++j);
            if (j == len_alpha(my_alpha))
                finish = 1;
            else {
                temp = my_alpha[i];
                my_alpha[i] = my_alpha[j];
                my_alpha[j] = temp;
                i = 0;
            }
        }
    }
}

charter_t *init_charter(char c, char *str)
{
    charter_t *new = malloc(sizeof(charter_t));
    new->c = c;
    new->nb_it = nb_iteration(str, c);
    new->huff = malloc(sizeof(char) * 9);
    new->last_char = 0;
    return new;
}

charter_t **init_alphabet(char *str)
{
    charter_t **my_alpha = malloc(sizeof(charter_t *) * 128);
    charter_t *temp;

    my_alpha[0] = init_charter(1, str);
    for (int i = 2; i < 127; ++i) {
        my_alpha[i - 1] = init_charter(i, str);
    }
    my_alpha[126] = init_charter(-32, str);
    my_alpha[127] = new_last_char();
    tri_alpha(my_alpha);
    del_usless_char(my_alpha);
    return my_alpha;
}
