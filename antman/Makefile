##
## EPITECH PROJECT, 2021
## Project Name
## File description:
## my Makefile
##

SRC	=	main.c

PLACE	=	lib/

MY	=	-L lib/

NAME	=	antman

all:	oui compile clean
	
compile:
	gcc $(SRC) $(MY) -lmy -o $(NAME) -g3

oui:
	$(MAKE) -C $(PLACE)

clean:
	rm -rf *~
