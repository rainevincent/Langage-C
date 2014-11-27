##
## Makefile for  in /home/mediav_j/mabm/42sh
## 
## Made by Jeremy Mediavilla
## Login   <mediav_j@epitech.net>
## 
## Started on  Wed May 28 14:45:17 2014 Jeremy Mediavilla
## Last update Wed May 28 14:45:18 2014 Jeremy Mediavilla
##

CC		=	gcc

RM		=	rm -f

NAME		=	42sh

IFLAGS		=	./includes/

CFLAGS		+=	-W -Wextra -Wall -I$(IFLAGS) -I./mysql/include

D_CORE		=	src/core/
D_ENV		=	src/env/
D_BUILTIN	=	src/builtin/
D_HISTORY	=	src/history/
D_LINE_EDITOR	=	src/line_editor/
D_CONF		=	src/conf/
D_FREE		=	src/free/
D_ONLINE	=	src/online/
D_ALIAS		=	src/alias/
D_PARSER	=	src/parser/
D_JOBCONTROL	=	src/jobcontrol/

SRC		=	$(D_CORE)main.c				\
			$(D_CORE)prompt.c			\
			$(D_CORE)execution_without_fork.c	\
			$(D_CORE)gnl.c				\
			$(D_CORE)exec_fct.c			\
			$(D_CORE)tab_functions.c		\
			$(D_BUILTIN)env.c			\
			$(D_BUILTIN)builtin.c			\
			$(D_BUILTIN)do_cd.c			\
			$(D_BUILTIN)cd_fct.c			\
			$(D_BUILTIN)cd_fct_bis.c		\
			$(D_BUILTIN)my_exit.c			\
			$(D_BUILTIN)get_true_pwd.c		\
			$(D_BUILTIN)my_echo.c			\
			$(D_BUILTIN)echo_fct.c			\
			$(D_CORE)list.c				\
			$(D_CORE)init.c				\
			$(D_LINE_EDITOR)line_editor.c		\
			$(D_LINE_EDITOR)xfunction.c		\
			$(D_LINE_EDITOR)term_fct.c		\
			$(D_LINE_EDITOR)char.c			\
			$(D_LINE_EDITOR)char2.c			\
			$(D_LINE_EDITOR)parser_line_editor.c	\
			$(D_LINE_EDITOR)build_line.c		\
			$(D_LINE_EDITOR)history_interaction.c	\
			$(D_LINE_EDITOR)bind_keys.c		\
			$(D_LINE_EDITOR)bind_keys2.c		\
			$(D_HISTORY)histo_list.c		\
			$(D_HISTORY)history.c			\
			$(D_HISTORY)manage_history.c		\
			$(D_HISTORY)my_alloc_init.c		\
			$(D_HISTORY)xfunction.c			\
			$(D_ALIAS)aliasing.c			\
			$(D_ALIAS)load_alias.c			\
			$(D_ALIAS)manage_alias.c		\
			$(D_CONF)conf.c				\
			$(D_CONF)default.c			\
			$(D_FREE)free_shell.c			\
			$(D_ONLINE)online.c			\
			$(D_ONLINE)mysql_1.c			\
			$(D_ONLINE)mysql_2.c			\
			$(D_ONLINE)mysql_3.c			\
			$(D_ONLINE)mysql_4.c			\
			$(D_PARSER)type.c			\
			$(D_PARSER)tree.c			\
			$(D_PARSER)token.c			\
			$(D_PARSER)token2.c			\
			$(D_PARSER)remove.c			\
			$(D_PARSER)parser_tools.c		\
			$(D_PARSER)parser_tools2.c		\
			$(D_PARSER)parser.c			\
			$(D_PARSER)list2.c			\
			$(D_PARSER)access.c			\
			$(D_PARSER)free.c			\
			$(D_PARSER)get_cmd.c			\
			$(D_PARSER)get_dollar.c			\
			$(D_JOBCONTROL)jobcontrol.c		\

OBJ		=	$(SRC:.c=.o)

LIB		=	./libmy/
L_NAME		=	-lmy -lncurses -lmysqlclient

all		:	libs $(NAME)

$(NAME)		:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) `mysql_config --libs`  $(L_NAME) -L$(LIB)

libs		:
			make -C $(LIB)

clean		:
			(cd $(LIB); make clean)
			$(RM) $(OBJ)

fclean		:	clean
			(cd $(LIB); make fclean)
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re libs
