/*
** EPITECH PROJECT, 2021
** libmy.h
** File description:
** creat the header of the libmy.a
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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

char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
int my_strlen(char const *str);
int my_putstr(char const *str);
void my_putnbr(int nb);
void my_putchar(char c);
char *str_copy(char *copy);
int my_power(int nb, int p);
char *base(int nb, char *str);


charter_t *new_last_char(void);
char *give_buffer(char const *file);
int len_alpha(charter_t **my_alpha);
charter_t **init_alphabet(char *str);
void destroy_alpha(charter_t **my_alpha);
void destroy_charter_t(charter_t *charter);
void destroy_all_charter(charter_t *my_alpha);
charter_t **set_huff(charter_t **my_alpha);
charter_t **huffman_tree(charter_t **my_alpha);
int find_hiden_str(char *argv, char const *str);
void write_bit(unsigned char *buff, char bit, int mode);
unsigned char *compressor3000(char *str, charter_t **my_alpha);
char *add_alpha_to_buff(charter_t **my_alpha, char *str);
void use_huffman_tree(charter_t *my_charter, charter_t **my_alpha, int *len, int first_loop);


char *convertor_str_bin(unsigned char const *str);

#endif
