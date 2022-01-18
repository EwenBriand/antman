/*
** EPITECH PROJECT, 2021
** Project Name
** File description:
** compress file
*/

#include "../include/my.h"

void add_compressed_char(unsigned char *str, charter_t *charter, int mode)
{
    for (int i = 0; i < my_strlen(charter->huff) - 1; ++i) {
        write_bit(str, charter->huff[i], 0);
    }
    write_bit(str, charter->huff[my_strlen(charter->huff) - 1], mode);
}

unsigned char *compressor3000(char *str, charter_t **my_alpha)
{
    unsigned char *new_char = malloc(sizeof(unsigned char) * my_strlen(str));
    int j = 0;
    for (int i = 0; i < my_strlen(str) - 1; ++i) {
        for (j; my_alpha[j]->c != str[i]; ++j);
        add_compressed_char(new_char, my_alpha[j], 0);
        j = 0;
    }
    for (j; my_alpha[j]->c != str[my_strlen(str) - 1]; ++j);
    add_compressed_char(new_char, my_alpha[j], 1);
    j = 0;
    return new_char;
}
