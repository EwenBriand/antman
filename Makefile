##
## EPITECH PROJECT, 2021
## Project Name
## File description:
## my Makefile
##

PLACEA	=	./antman/

PLACEG	=	./giantman/ 

MY	=	-L lib/

NAME	=	make

all:	compilea compileg clean
	
clean:
	rm -rf *~

compilea:
	$(MAKE) -C $(PLACEA)

compileg:
	$(MAKE) -C $(PLACEG)
