##
## Makefile for Makefile in /home/merran_g/work/c_igraph/raytracer/merge
## 
## Made by Geoffrey Merran
## Login   <merran_g@epitech.net>
## 
## Started on  Sun Jun  8 20:34:56 2014 Geoffrey Merran
## Last update Sun Jun  8 20:35:02 2014 Geoffrey Merran
##

SRC	=	help.c		\
		main_btn.c	\
		main_btn2.c	\
		editor_2.c	\
		editor_3.c	\
		editor_4.c	\
		main_ins.c	\
		main_ins2.c	\
		main_ins3.c	\
		push_in_file.c	\
		save.c		\
		main_window.c	\
		editor.c	\
		main.c		\

NAME	=	editor

OBJ	=	$(SRC:.c=.o)

CC	=	gcc `pkg-config --cflags --libs gtk+-2.0` -O3

RM	=	rm -f

CFLAGS	+=	 -W -Wall -Wextra -Werror -ansi -pedantic -I.

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
