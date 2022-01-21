/*
** EPITECH PROJECT, 2022
** Project Name
** File description:
** giantman main
*/

#include "lib/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

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

void allocate_dictio(char **dictio, char *str_dictio)
{
    int y = 0;
    int y2 = 0;
    int count = 0;

    for (int x = 0; x < (count_strspaces(str_dictio) + 1); x++) {
        for (y; str_dictio[y] != ' ' && str_dictio[y] != '\0'; y++)
            count++;
        dictio[x] = malloc(sizeof(char) * (count + 2));
        y++;
        count = 0;
    }
    for (int x = 0; x < (count_strspaces(str_dictio) + 1); x++) {
        for (y2; str_dictio[y2] != ' ' && str_dictio[y2] != '\0'; y2++) {
            dictio[x][count] = str_dictio[y2];
            count ++;
        }
	    y2++;
        count = 0;
    }
}

int main(int ac, char const *av[])
{
    if (ac != 2 || (av[1][0] == '-' && av[1][1] == 'h'))
        return print_h(ac, av);
    struct stat st;
    stat(av[1], &st);
    int size = st.st_size;
    int fd = open(av[1], O_RDONLY);
    char *text = malloc(sizeof(char) * (size + 1));
    char *str_dictio = malloc(sizeof(char) * (my_strlen(text) + 1));
    char **dictio;

    read(fd, text, size);
    str_dictio = my_str_dup_cond(text, '\n');
    dictio = malloc(sizeof(char *) * (count_strspaces(str_dictio) + 1));
    allocate_dictio(dictio, str_dictio);
    free(str_dictio);
    return 0;
}
