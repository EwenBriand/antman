/*
** EPITECH PROJECT, 2021
** libmy.h
** File description:
** creat the header of the libmy.a
*/

#ifndef _LIBALL_POOL
    #define _LIBALL_POOL

#include <stdlib.h>

int my_strlen_int(int nb);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
int my_strlen(char const *str);
int my_strlen_int(int nb);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
int my_putstr(char const *str);
void my_putnbr(int nb);
void my_putchar(char c);

#endif
