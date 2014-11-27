##
## Makefile for Makefile in /home/merran_g/work/c_igraph/raytracer
## 
## Made by Geoffrey Merran
## Login   <merran_g@epitech.net>
## 
## Started on  Tue Jun  3 17:03:02 2014 Geoffrey Merran
## Last update Sun Jun  8 16:50:12 2014 Geoffrey Merran
##

RM		= rm -f

CC		= cc
CFLAGS		+= -Wextra -Wall -W -pedantic -ansi -g3 -I$(I_PATH)

I_PATH		= ./includes/

NAME		= raytracer

OBJ		= $(SRC:.c=.o)

LIBS		= -lmy -lmymlx -lmlx -lXext -lX11

LIB		= libmy/
LIBMYX		= libmymlx/
LIBX11		= /usr/lib64/X11
LIBXEXT		= /usr/lib64

D_CORE		= src/core/
D_INTER		= src/inter/
D_PARSER	= src/parser/
D_SHAPE		= src/shape/
D_LUM		= src/luminosity/
D_REFL		= src/reflexion/
D_TMP		= src/kekette/

SRC		= $(D_CORE)main.c			\
		$(D_CORE)calc_img.c			\
		$(D_CORE)hook.c				\
		$(D_INTER)get_simple_pos.c 		\
		$(D_INTER)get_simple_pos2.c		\
		$(D_INTER)find_inter.c			\
		$(D_INTER)get_normal.c			\
		$(D_PARSER)items.c 			\
		$(D_PARSER)list.c 			\
		$(D_PARSER)read_inf.c 			\
		$(D_SHAPE)sphere.c			\
		$(D_SHAPE)plan.c 			\
		$(D_SHAPE)cylinder.c 			\
		$(D_SHAPE)cone.c			\
		$(D_SHAPE)hyperboloide.c		\
		$(D_LUM)luminosity.c 			\
		$(D_LUM)shadow.c 			\
		$(D_REFL)reflexion.c			\
		$(D_CORE)xfunction.c			\

all:	libs $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) -L$(LIB) -L$(LIBMYX) -L$(LIBX11) -L$(LIBXEXT) -lm

libs:
	make -C $(LIB)
	make -C $(LIBMYX)

clean:
	(cd $(LIB); make clean)
	(cd $(LIBMYX); make clean)
	$(RM) $(OBJ)

fclean:		clean
	(cd $(LIB); make fclean)
	(cd $(LIBMYX); make clean)
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all libs clean fclean re
