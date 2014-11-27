##
## Makefile for ascenceurs in /home/rainev/Desktop/Exia/Prosit/Project/ascenseur
## 
## Made by rainev
## Login   <vincent.raine@viacesi.fr>
## 
## Started on  Sat Nov 15 09:44:51 2014 rainev
## Last update Sat Nov 15 11:03:04 2014 rainev
##

NAME	=	ascenceurs

SRC	=	src/main.c	\
		src/action.c

CC	=	cc

LDFLAGS	+=

CFLAGS	+=	-I./include -W -Werror -pedantic -ansi -g -g3

RM	=	rm -f

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ) /src/*~ /src/*# /src/*.c~

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
