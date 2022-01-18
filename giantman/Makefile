##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Launch program
##

SRC	=	main.c
NAME	=	giantman
LDFLAGS	=	-L./lib/ -lmy

all:	$(NAME) build

$(NAME):
	make -C lib/

build:
	gcc -Ilib/my -o $(NAME) $(SRC) $(LDFLAGS) -g3

lib:
	make -C lib/

clean:
	rm -f unit_tests *.gcda *.gcno
	make clean -C lib/

fclean:	clean
	rm -f $(NAME)

re:	fclean all
