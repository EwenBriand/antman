/*
** EPITECH PROJECT, 2022
** Project Name
** File description:
** giantman main
*/

#include "lib/my.h"

int len_alpha(charter_t **my_alpha)
{
    int count = 0;
    for (count; my_alpha[count]->last_char == 0; ++count);
    return count;
}

int print_h(int ac, char const *av[])
{
    if (ac != 2) {
        return 84;
    } else if (av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("\nUSAGE\n   ./giantman file.data\n\nOPTIONS\n");
        my_putstr("\t-h print the usage and quit.\n");
        return 0;
    }
}

charter_t *new_charter(void)
{
    charter_t *new = malloc(sizeof(charter_t));
    new->huff = malloc(sizeof(char) * 20);
    new->last_char = 0;

    return new;
}

charter_t *new_last_char(void)
{
    charter_t *new = malloc(sizeof(charter_t));
    new->last_char = 1;
    new->c = '\0';
    new->nb_it = 0;

    return new;
}

charter_t **allocate_dictio(char **dictio, char *str_dictio)
{
    charter_t **my_alpha = malloc(sizeof(charter_t *) * 127);
    charter_t *charter = new_charter();
    int y = 0;
    int y2 = 0;
    int count = 0;
    int x = 0;

    for (int x = 0; x < (count_strspaces(str_dictio) + 1); x++) {
        for (y; str_dictio[y] != ' ' && str_dictio[y] != '\0'; y++)
            count++;
        dictio[x] = malloc(sizeof(char) * (count + 2));
        y++;
        count = 0;
    }
    for (x; x < (count_strspaces(str_dictio) + 1); x++) {
        charter->c = str_dictio[y2];
        y2++;
        for (y2; str_dictio[y2] != ' ' && str_dictio[y2] != '\0'; y2++) {
            charter->huff[count] = str_dictio[y2];
            count ++;
        }
	    y2++;
        count = 0;
        my_alpha[x] = charter;
        charter = new_charter();
    }
    my_alpha[x] = new_last_char();
    free(charter);
    return my_alpha;
}

void destroy_charter_t(charter_t *charter)
{
    free(charter->huff);
    free(charter);
}

void destroy_all_charter(charter_t *my_alpha)
{
    if (my_alpha->c != '\0') {
        free(my_alpha->huff);
        free(my_alpha);
    } else if (my_alpha->last_char == 1)
        free(my_alpha);
    else {
        free(my_alpha->huff);
        destroy_all_charter(my_alpha->left);
        destroy_all_charter(my_alpha->right);
        free(my_alpha);
    }
}

void destroy_alpha(charter_t **my_alpha)
{
    int len = len_alpha(my_alpha);

    for (int i = 0; i < len + 1; ++i){
        destroy_all_charter(my_alpha[i]);
    }
    free(my_alpha);
}

char *give_buffer(char const *file)
{
    char *buffer;
    int fd = open(file, O_RDONLY, S_IRUSR | S_IRGRP | S_IROTH);
    struct stat buf;
    stat(file, &buf);

    buffer = malloc(sizeof(char) * (buf.st_size + 1));
    if (fd != -1) {
        read(fd, buffer, buf.st_size);
    }
    close(fd);
    buffer[buf.st_size] = '\0';
    return buffer;
}

int main(int ac, char const *av[])
{
    if (ac != 2 || (av[1][0] == '-' && av[1][1] == 'h'))
        return print_h(ac, av);
    charter_t **my_alpha;
    struct stat st;
    stat(av[1], &st);
    int size = st.st_size;
    char *str_dictio = malloc(sizeof(char) * (st.st_size + 1));
    char **dictio = malloc(sizeof(char *) * (count_strspaces(str_dictio) + 1));

    str_dictio = my_str_dup_cond(give_buffer(av[1]), '\n');
    my_alpha = allocate_dictio(dictio, str_dictio);
    

    for (int i = 0; i < len_alpha(my_alpha); ++i) 
        printf("%c %s\n", my_alpha[i]->c, my_alpha[i]->huff);
    free(str_dictio);
    destroy_alpha(my_alpha);
    return 0;
}
