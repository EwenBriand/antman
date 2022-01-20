/*
** EPITECH PROJECT, 2021
** Project Name
** File description:
** use huffman tree
*/

#include "../include/my.h"

void add_char_in_beg(char *huff, char add)
{
    int len = my_strlen(huff);
    huff[len] = add;
    huff[len + 1] = '\0';
}

void setup_using_huffman_tree(charter_t *my_charter, charter_t **my_alpha,
    int *len, int first_loop)
{
    my_charter->right->huff = malloc(sizeof(char) * 9);
    my_charter->left->huff = malloc(sizeof(char) * 9);

    my_charter->right->huff[0] = '0';
    my_charter->right->huff[1] = '\0';
    use_huffman_tree(my_charter->right, my_alpha, len, 1);
    my_charter->left->huff[0] = '1';
    my_charter->left->huff[1] = '\0';
    use_huffman_tree(my_charter->left, my_alpha, len, 1);
}

void use_huffman_tree(charter_t *my_charter, charter_t **my_alpha,
    int *len, int first_loop)
{
    if (my_charter->c != '\0') {
        my_alpha[*len] = my_charter;
        ++*len;
    }
    else {
        if (first_loop != 0) {
            my_charter->right->huff = str_copy(my_charter->huff);
            add_char_in_beg(my_charter->right->huff, '0');
            use_huffman_tree(my_charter->right, my_alpha, len, first_loop + 1);
            my_charter->left->huff = str_copy(my_charter->huff);
            add_char_in_beg(my_charter->left->huff, '1');
            use_huffman_tree(my_charter->left, my_alpha, len, first_loop + 1);
            free(my_charter->huff);
        } else {
            setup_using_huffman_tree(my_charter, my_alpha, len, first_loop);
        }
    }
}
