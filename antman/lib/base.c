/*
** EPITECH PROJECT, 2021
** Project Name
** File description:
** base convertor
*/

#include "../include/my.h"

void add_char_in_beg(char *huff, char add)
{
    int len = my_strlen(huff);
    my_revstr(huff);
    huff[len] = add;
    huff[len + 1] = '\0';
    my_revstr(huff);
    huff[len + 1] = '\0';
}

char *base(int nb, char *str)
{
    int power = 0;
    int temp = 0;
    int base = my_strlen(str);
    char *result;

    for (int i = 0; my_power(base, i) <= nb; ++i) {
        power = i;
    }
    result = malloc(sizeof(char) * (9));
    for (int i = power; i >= 0; --i) {
        temp = nb / my_power(base, i);
        result[power - i] = str[temp];
        nb -= temp * my_power(base, i);
    }
    result[power] = str[temp];
    result[power + 1] = '\0';
    for (int i = my_strlen(result); i < 8; ++i) {
        add_char_in_beg(result, '0');
    }
    return result;
}

char *convertor_str_bin(unsigned char const *str)
{
    int len = my_strlen(str);
    unsigned char *temp;
    unsigned char *bin = malloc(sizeof(char) * (len * 8 + 1));
    bin[0] = '\0';

    for (int i = 0; i < len; ++i) {
        temp = base(str[i], "01");
        my_strcat(bin, temp);
        free(temp);
        temp = malloc(sizeof(char) * (len * 8 + 1));
    }
    free(temp);
    return bin;
}
