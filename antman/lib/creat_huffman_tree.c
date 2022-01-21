/*
** EPITECH PROJECT, 2021
** Project Name
** File description:
** huffman tree
*/

#include "../include/my.h"

charter_t *give_new_charter(charter_t **my_alpha, int *min1, int *min2)
{
    int len = len_alpha(my_alpha);
    charter_t *new = malloc(sizeof(charter_t));

    for (int i = 1; i < len; ++i) {
        if (my_alpha[i]->nb_it < my_alpha[*min1]->nb_it) {
            *min2 = *min1;
            *min1 = i;
        } else if (my_alpha[i]->nb_it < my_alpha[*min2]->nb_it)
            *min2 = i;
    }
    new->nb_it = my_alpha[*min1]->nb_it + my_alpha[*min2]->nb_it;
    new->left = my_alpha[*min2];
    new->right = my_alpha[*min1];
    new->last_char = 0;
    my_alpha[len]->last_char = 1;
    new->c = '\0';
//    printf("min1 = %c min2 = %c   -->  %i\n", new->left->c, new->right->c, new->nb_it);
    return new;
}

void new_tree_whitout_tow_lowests(charter_t **new_tree, charter_t**my_alpha,
    int min1, int min2)
{
    int count = 0;

    for (int i = 0; i < len_alpha(my_alpha) + 1; ++i) {
        if (i != min1 && i != min2)
            new_tree[i - count] = my_alpha[i];
        else
            ++count;
    }
}

charter_t **huffman_tree(charter_t **my_alpha)
{
    int len = len_alpha(my_alpha);
    charter_t **new_tree;
    charter_t *temp;
    int min1 = 0;
    int min2 = 1;
    while (len > 1) {
        min1 = 0;
        min2 = 1;
        temp = give_new_charter(my_alpha, &min1, &min2);
        new_tree = malloc(sizeof(charter_t *) * (len));
        new_tree_whitout_tow_lowests(new_tree, my_alpha, min1, min2);
        new_tree[len - 1] = new_last_char();
        new_tree[len - 2] = temp;
        free(my_alpha);
        my_alpha = new_tree;
        --len;
    }
    return my_alpha;
}
