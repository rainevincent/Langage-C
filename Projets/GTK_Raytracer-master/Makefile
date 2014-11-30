##
## Makefile for raytracer in /home/raine_v/Projets/C/Tek1/rendu_tmp/MUL/MUL_2013_rtracer/gtk
## 
## Made by Vincent Raine
## Login   <raine_v@epitech.net>
## 
## Started on  Wed Jun  4 23:33:46 2014 Vincent Raine
## Last update Fri Jun  6 13:03:21 2014 Vincent Raine
##

D_SRC		=	./src

SRC	=	$(D_SRC)/barreoutils.c	\
		$(D_SRC)/callback.c	\
		$(D_SRC)/menu.c		\
		$(D_SRC)/raccourcis.c	\
		$(D_SRC)/main.c		\
		$(D_SRC)/error.c

NAME		=	interface_raytracer

CC		=	cc

CFLAGS		+=	-Wall -W  -pedantic -ansi -g3

CFLAGS		+=	-Iinclude  `pkg-config --cflags --libs gtk+-2.0`

LDFLAGS 	+=      -L/usr/lib64/X11 -lXext -lX11

RM		=	rm -f

OBJ		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
			$(RM) $(OBJ) src/*.c~ includes/*.h~ Makefile~

fclean:			clean
			$(RM) $(NAME)

re:			clean fclean all

.PHONY:			all clean fclean re
