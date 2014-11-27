##
## Makefile for Makefile in /home/merran_g/work/c_igraph/raytracer/merge/server
## 
## Made by Geoffrey Merran
## Login   <merran_g@epitech.net>
## 
## Started on  Sun Jun  8 16:50:21 2014 Geoffrey Merran
## Last update Sun Jun  8 20:34:25 2014 Geoffrey Merran
##

RM		= rm -f

CC		= cc `pkg-config --libs --cflags gtk+-2.0`

CFLAGS		+= -Wextra -Wall -W -pedantic -ansi -I$(I_PATH)

I_PATH		= ./includes/

NAME		= rt

OBJ		= $(SRC:.c=.o)

D_CORE		= src/core/
D_FUNC		= src/func/
D_GUI		= src/gui/

SRC		= 	$(D_CORE)main.c				\
			$(D_CORE)list.c				\
			$(D_CORE)server_1.c			\
			$(D_CORE)server_2.c			\
			$(D_CORE)server_3.c			\
			$(D_CORE)server_4.c			\
			$(D_CORE)server_5.c			\
			$(D_CORE)server_6.c			\
			$(D_CORE)server_7.c			\
			$(D_CORE)server_8.c			\
			$(D_CORE)server_9.c			\
			$(D_CORE)server_10.c			\
			$(D_CORE)read_inf.c			\
			$(D_FUNC)get_next_line.c		\
			$(D_FUNC)my_alloc_init.c		\
			$(D_FUNC)xmalloc.c			\
			$(D_GUI)gui.c				\
			$(D_GUI)gui_2.c				\
			$(D_GUI)gui_3.c				\
			$(D_GUI)gui_4.c				\
			$(D_GUI)gui_5.c				\
			$(D_GUI)gui_6.c				\
			$(D_GUI)gui_7.c				\
			$(D_GUI)gui_8.c				\
			$(D_GUI)gui_9.c				\

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lX11

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
