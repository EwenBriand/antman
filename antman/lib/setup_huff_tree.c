/*
** EPITECH PROJECT, 2021
** Project Name
** File description:
** set huff tree
*/

#include "../include/my.h"

charter_t **set_huff(charter_t **my_alpha)
{
    int len = len_alpha(my_alpha);
    charter_t **my_new_alpha = malloc(sizeof(charter_t *) * len);
    my_alpha = huffman_tree(my_alpha);
    my_alpha[0]->huff = malloc(sizeof(char) * 8);
    len = 0;
    use_huffman_tree(my_alpha[0], my_new_alpha, &len, 0);
    my_new_alpha[len] = new_last_char();

 //   for (int i = 0; i < len_alpha(my_new_alpha); ++i)
   //     printf("%c %i %s\n", my_new_alpha[i]->c, my_new_alpha[i]->nb_it, my_new_alpha[i]->huff);

    return my_new_alpha;
}
