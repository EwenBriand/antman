##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Make file
##

SRC	=	my_getnbr.c	\
		my_putchar.c	\
		my_putnbr.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_str_isnum.c	\
		my_strcat.c	\
		my_strdup_cond.c	\
		my_strlen_int.c	\
		my_strlen.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c $(SRC) -g3
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean:	clean
	rm $(NAME)

re:	fclean all
