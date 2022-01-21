/*
** EPITECH PROJECT, 2021
** libmy.h
** File description:
** creat the header of the libmy.a
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef _LIBALL_POOL
    #define _LIBALL_POOL

typedef struct charter_s {
    char c;
    char *huff;
    struct charter_s *left;
    struct charter_s *right;
    int nb_it;
    int last_char;
} charter_t;

int my_getnbr(char const *str);
int my_str_isnum(char const *str);
char *my_str_dup_cond(const char *str, char cond);
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
int count_strspaces(char *str);
int len_alpha(charter_t **my_alpha);

#endif
