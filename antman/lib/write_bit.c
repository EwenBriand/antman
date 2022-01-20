/*
** EPITECH PROJECT, 2021
** Project Name
** File description:
** strlen
*/

#include "../include/my.h"

void write_bit(unsigned char *buff, char bit, int mode)
{
    static char my_char[8] = "\0\0\0\0\0\0\0\0";
    int add_char = 0;

    if (bit == '0')
        my_char[my_strlen(my_char)] = '0';
    if (bit == '1')
        my_char[my_strlen(my_char)] = '1';
    if (mode == 1)
        for (int i = my_strlen(my_char); i < 8; ++i)
            my_char[i] = '0';
    if (my_strlen(my_char) == 8) {
        for (int i = 8; i > 0; --i) {
            add_char += my_power(2, i - 1) * (my_char[8 - i] - '0');
            my_char[8 - i] = '\0';
        }
        buff[my_strlen(buff)] = add_char;
        buff[my_strlen(buff)] = '\0';
    }
}
