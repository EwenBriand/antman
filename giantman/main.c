/*
** EPITECH PROJECT, 2022
** Project Name
** File description:
** giantman main
*/

#include "./include/my.h"

int print_h(void)
{
	my_putstr("\nUSAGE\n   ./giantman file.data\n\nOPTIONS\n");
	my_putstr("\t-h print the usage and quit.\n");

	return 0;
}

int main(int argc, char const *argv[])
{
	if (argv[1][0] == '-' && argv[1][1] == 'h')
		return print_h();
	return 0;
}
