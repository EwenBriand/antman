/*
** EPITECH PROJECT, 2021
** Project Name
** File description:
** destroy charter
*/

#include "../include/my.h"

int find_hiden_str(char *argv, char const *str)
{
    int pos_act = 0;
    for (int i = 0; i < my_strlen(str); ++i) {
        if (argv[pos_act] == str[i])
            ++pos_act;
        if (pos_act == my_strlen(argv))
            return 0;
    }
    return 1;
}
