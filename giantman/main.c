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

int print_h(void)
{
    my_putstr("\nUSAGE\n   ./giantman file.data\n\nOPTIONS\n");
    my_putstr("\t-h print the usage and quit.\n");

    return 0;
}

int main(int ac, char const *av[])
{
    if (av[1][0] == '-' && av[1][1] == 'h')
        return print_h();
    struct stat st;
    stat(av[1], &st);
    int size = st.st_size;
    int fd = open(av[1], O_RDONLY);
    char *text = malloc(sizeof(char) * (size + 1));

    read(fd, text, size);
    for (int i = 0; i < size; i ++)
        my_putchar(text[i]);
    printf("\n");
    return 0;
}
