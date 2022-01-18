/*
** EPITECH PROJECT, 2022
** Project Name
** File description:
** antman main
*/

#include "include/my.h"

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
    return buffer;
}

int print_h(void)
{
	my_putstr("\nUSAGE\n   ./antman file.txt\n\nOPTIONS\n");
	my_putstr("\t-h print the usage and quit.\n");

	return 0;
}

void destroy_all_charter(charter_t *my_alpha)
{
	if (my_alpha->c != '\0')
		free(my_alpha->huff);
	else {
		free(my_alpha->huff);
		destroy_all_charter(my_alpha->left);
		destroy_all_charter(my_alpha->right);
		free(my_alpha);
	}
}

void destroy_alpha(charter_t **my_alpha)
{
	for (int i = 0; i < len_alpha(my_alpha); ++i){
		destroy_all_charter(my_alpha[i]);
	}
	free(my_alpha);
}

int rigor(int argc, char const **argv)
{
	return 0;
}

int main(int argc, char const *argv[])
{
	if (rigor(argc, argv) == 1)
		return 84;
	if (argv[1][0] == '-' && argv[1][0] == 'h')
		return print_h();
    char *buf = give_buffer(argv[1]);
    char *new_buff;
    charter_t **my_alpha = init_alphabet(buf);
    charter_t **my_new_alpha = malloc(sizeof(charter_t *) * len_alpha(my_alpha));
    my_new_alpha = set_huff(my_alpha);

    new_buff = add_alpha_to_buff(my_new_alpha, buf);
    my_strcat(new_buff, compressor3000(buf, my_new_alpha));
    printf("%s\n", new_buff);

    printf("%c\n", 235);
  //  printf("%i\n%c\n", my_strlen(new_buff), 345);

   /* charter_t *test = malloc(sizeof(charter_t));
    test->huff = "011000011";
    test->c = 'a';

    add_compressed_char(new_buff, test, 0);
    printf("%i %s\n", new_buff[my_strlen(new_buff) - 1], new_buff);
*/
    free(buf);
    free(new_buff);
    destroy_alpha(my_new_alpha); 
    return 0;
}











/*


int main(int argc, char const *argv[])
{
	if (argv[1][0] == '-' && argv[1][1] == 'h')
		return print_h();
	return 0;
}
*/