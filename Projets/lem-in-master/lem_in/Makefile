##
## Makefile for Makefile in /home/merran_g/work/c_elem/lem-in/lem_in
## 
## Made by Geoffrey Merran
## Login   <merran_g@epitech.net>
## 
## Started on  Tue Apr 22 14:21:02 2014 Geoffrey Merran
## Last update Sun May  4 19:07:45 2014 Geoffrey Merran
##

CC		= cc

RM		= rm -f

CFLAGS		+= -W -Wall -Wextra -pedantic -ansi -g3 -I$(INCLUDES)
INCLUDES	= ./includes/

NAME		= lem_in

CORE_FOL	= core/
PARSER_FOL	= parser/

SRC_CORE	= $(CORE_FOL)/main.c	\
		$(CORE_FOL)/ways.c	\
		$(CORE_FOL)/path.c	\
		$(CORE_FOL)/debug.c	\
		$(CORE_FOL)/move.c	\
		$(CORE_FOL)/ants.c	\
		$(CORE_FOL)/free.c	\

SRC_PARSER	= $(PARSER_FOL)/parser.c \
		$(PARSER_FOL)/init_parser.c \
		$(PARSER_FOL)/gnl.c \
		$(PARSER_FOL)/fill_map.c \
		$(PARSER_FOL)/fill_map2.c \
		$(PARSER_FOL)/type.c \
		$(PARSER_FOL)/type2.c \
		$(PARSER_FOL)/error.c \
		$(PARSER_FOL)/room.c \
		$(PARSER_FOL)/free.c


OBJ_CORE	= $(SRC_CORE:.c=.o)
OBJ_PARSER	= $(SRC_PARSER:.c=.o)

LIB		= ./libmy/
L_NAME		= -lmy

all:		libs $(NAME)

$(NAME):	$(OBJ_CORE) $(OBJ_PARSER)
	$(CC) -o $(NAME) $(OBJ_CORE) $(OBJ_PARSER) $(L_NAME) -L$(LIB)

libs:
	make -C $(LIB)

clean:
	(cd $(LIB); make clean)
	$(RM) $(OBJ_PARSER)
	$(RM) $(OBJ_CORE)

fclean:		clean
	(cd $(LIB); make fclean)
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
