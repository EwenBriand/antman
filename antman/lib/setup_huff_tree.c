/*
** EPITECH PROJECT, 2021
** Project Name
** File description:
** set huff tree
*/

#include "../include/my.h"

void sort_my_alpha_grow(charter_t **my_alpha)
{
    int best_char;
    int len = len_alpha(my_alpha);
    charter_t *temp;

    for (int i = 0; i < len; ++i) {
        best_char = i;
        for (int j = i + 1; j < len; ++j) {
            if (my_alpha[best_char]->nb_it > my_alpha[j]->nb_it)
                best_char = j;
        }
        if (i != best_char) {
            temp = my_alpha[i];
            my_alpha[i] = my_alpha[best_char];
            my_alpha[best_char] = temp;
        }
    }
}

charter_t **set_huff(charter_t **my_alpha)
{
    int len = len_alpha(my_alpha);
    charter_t **my_new_alpha = malloc(sizeof(charter_t *) * (len + 1));
    sort_my_alpha_grow(my_alpha);
    my_alpha = huffman_tree(my_alpha);
    len = 0;
    use_huffman_tree(my_alpha[0], my_new_alpha, &len, 0);
    my_new_alpha[len] = new_last_char();

    free(my_alpha);
    return my_new_alpha;
}
