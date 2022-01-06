/*
** EPITECH PROJECT, 2022
** Project Name
** File description:
** antman main
*/

#include "./include/my.h"

int print_h(void)
{
	my_putstr("\nUSAGE\n   ./antman file.txt\n\nOPTIONS\n");
	my_putstr("\t-h print the usage and quit.\n");

	return 0;
}

int main(int argc, char const *argv[])
{
	if (argv[1][0] == '-' && argv[1][1] == 'h')
		return print_h();
	return 0;
}
