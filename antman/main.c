/*
** EPITECH PROJECT, 2022
** Project Name
** File description:
** antman main
*/

#include "include/my.h"

int print_h(void)
{
    my_putstr("\nUSAGE\n   ./antman file.txt\n\nOPTIONS\n");
    my_putstr("\t-h print the usage and quit.\n");

    return 1;
}

int rigor(int argc, char const **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
        return print_h();
    if (argc != 3)
        return 1;
    if (argv[2][0] != '1' && argv[2][0] != '2' && argv[2][0] != '3')
        return 1;
    if (find_hiden_str(".txt", argv[1]) == 1 && argv[2][0] == '1')
        return 1;
    if (find_hiden_str(".html", argv[1]) == 1 && argv[2][0] == '2')
        return 1;
    if (find_hiden_str(".ppm", argv[1]) == 1 && argv[2][0] == '3')
        return 1;

    return 0;
}

void sort_my_alpha_decrease(charter_t **my_alpha)
{
    int best_char;
    int len = len_alpha(my_alpha);
    charter_t *temp;

    for (int i = 0; i < len; ++i) {
        best_char = i;
        for (int j = i + 1; j < len; ++j) {
            if (my_alpha[best_char]->nb_it < my_alpha[j]->nb_it)
                best_char = j;
        }
        if (i != best_char) {
            temp = my_alpha[i];
            my_alpha[i] = my_alpha[best_char];
            my_alpha[best_char] = temp;
        }
    }
}

int main(int argc, char const *argv[])
{
    if (rigor(argc, argv) == 1)
        return 84;
    if (argv[1][0] == '-' && argv[1][0] == 'h')
        return print_h();
    char *buf = give_buffer(argv[1]);
    if (buf[0] == '\0')
        return 84;
    char *new_buff;
    charter_t **my_alpha = init_alphabet(buf);
    charter_t **my_new_alpha = set_huff(my_alpha);

    sort_my_alpha_decrease(my_new_alpha);
    new_buff = add_alpha_to_buff(my_new_alpha, buf);
    my_putstr(new_buff);
    my_putstr(compressor3000(buf, my_new_alpha));

    free(buf);
    free(new_buff);
    destroy_alpha(my_new_alpha); 
    return 0;
}
