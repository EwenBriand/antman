/*
** EPITECH PROJECT, 2021
** Project Name
** File description:
** destroy charter
*/

#include "../include/my.h"

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