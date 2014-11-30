##
## Makefile for  in /home/ades_n/Workspace/raytracer/merge/client
## 
## Made by nicolas ades
## Login   <ades_n@epitech.net>
## 
## Started on  Sun Jun  8 00:57:30 2014 nicolas ades
## Last update Sun Jun  8 20:33:30 2014 Geoffrey Merran
##

RM		= rm -f

CC		= cc
CFLAGS		+= -Wextra -Wall -W -pedantic -ansi -O3 -I$(I_PATH)

I_PATH		= ./includes/

NAME		= clientrt

OBJ		= $(SRC:.c=.o)

LIBS		= -L./minilibx -lmy -lmymlx -lmlx -lXext -lX11 -lpthread

LIB		= libmy/
LIBMYX		= libmymlx/
LIBX11		= /usr/lib64/X11
LIBXEXT		= /usr/lib64

D_CORE		= src/core/
D_INTER		= src/inter/
D_SHAPE		= src/shape/
D_LUM		= src/luminosity/
D_REFL		= src/reflexion/
D_TMP		= src/clt_color/
D_DIAVME	= src/parser/

SRC		= $(D_CORE)main.c			\
		$(D_CORE)calc_img.c			\
		$(D_CORE)hook.c				\
		$(D_CORE)libclient.c			\
		$(D_CORE)utility.c			\
		$(D_CORE)communication.c			\
		$(D_CORE)thread.c			\
		$(D_INTER)get_simple_pos.c 		\
		$(D_INTER)get_simple_pos2.c		\
		$(D_INTER)find_inter.c			\
		$(D_INTER)get_normal.c			\
		$(D_DIAVME)list.c			\
		$(D_DIAVME)read_inf.c			\
		$(D_SHAPE)sphere.c			\
		$(D_SHAPE)plan.c 			\
		$(D_SHAPE)cylinder.c 			\
		$(D_SHAPE)cone.c			\
		$(D_SHAPE)hyperboloide.c		\
		$(D_LUM)luminosity.c 			\
		$(D_LUM)shadow.c 			\
		$(D_REFL)reflexion.c			\
		$(D_CORE)xfunction.c			\
		$(D_TMP)stock_color.c			\
		$(D_DIAVME)parser.c			\
		$(D_DIAVME)items.c			\
		$(D_DIAVME)balise_tools.c		\
		$(D_DIAVME)balise_value.c		\
		$(D_DIAVME)get_infos.c			\
		$(D_DIAVME)get_item_val.c		\
		$(D_DIAVME)scene_tools.c		\
		$(D_DIAVME)str_tools.c			\

all:	libs $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) -L$(LIB) -L$(LIBMYX) -L$(LIBX11) -L$(LIBXEXT) -lm -g3

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
