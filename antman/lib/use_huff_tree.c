/*
** EPITECH PROJECT, 2021
** Project Name
** File description:
** use huffman tree
*/

#include "../include/my.h"

void use_huffman_tree(charter_t *my_charter, charter_t **my_alpha, int *len, int first_loop)
{
    if (my_charter->c != '\0') {
        my_alpha[*len] = my_charter;
        ++*len;
    }
    else {
        if (first_loop != 0) {
            my_charter->right->huff = str_copy(my_charter->huff);
            my_charter->right->huff[first_loop] = '1';
            my_charter->right->huff[first_loop + 1] = '\0';
            use_huffman_tree(my_charter->right, my_alpha, len, first_loop + 1);
            my_charter->left->huff = str_copy(my_charter->huff);
            my_charter->left->huff[first_loop] = '0';
            my_charter->left->huff[first_loop + 1] = '\0';
            use_huffman_tree(my_charter->left, my_alpha, len, first_loop + 1);
        } else {
            my_charter->right->huff = malloc(sizeof(char) * 8);            
            my_charter->left->huff = malloc(sizeof(char) * 8);

            my_charter->right->huff[0] = '1';
            my_charter->right->huff[1] = '\0';
            use_huffman_tree(my_charter->right, my_alpha, len, 1);
            my_charter->left->huff[0] = '0';
            my_charter->left->huff[1] = '\0';
            use_huffman_tree(my_charter->left, my_alpha, len, 1);
        }
    }
}
