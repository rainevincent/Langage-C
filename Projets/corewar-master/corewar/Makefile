##
## Makefile for Makefile in /home/merran_g/work/c_elem/corewar
## 
## Made by Geoffrey Merran
## Login   <merran_g@epitech.net>
## 
## Started on  Sun Apr 13 17:16:20 2014 Geoffrey Merran
## Last update Mon Apr 14 16:33:23 2014 Nicolas Ades
##

RM	= rm -f

CC	= cc

CFLAGS	+= -Wextra -Wall -W -pedantic -O3 -ansi -I$(I_PATH)
I_PATH	= ../includes/

NAME	= corewar

FONT	= imagine_font.ttf
MUSIC	= derezzed.wav

OBJ	= $(SRC:.c=.o)

LIB	= ../libmy/

SRC	= main.c  \
	vm_pars.c \
	vm_init.c \
	vm_getchamp.c vm_getchamp2.c vm_getchamp3.c \
	vm_arena.c vm_arena2.c vm_arena3.c \
	vm_instruction.c \
	vm_instruction2.c \
	vm_instruction3.c \
	vm_instruction4.c \
	vm_getparams.c \
	vm_getparams2.c \
	vm_getparams3.c \
	vm_proc.c \
	aff.c aff2.c aff3.c \
	op.c \
	my_free.c \
	xfunction.c \
	sdl_xfunction.c sdl_xfunction2.c \

all:		libs $(NAME)

$(NAME):	$(OBJ)
	cp police/$(FONT) /tmp/
	cp music/$(MUSIC) /tmp/
	$(CC) -o $(NAME) $(OBJ) -lmy -L$(LIB) -lSDL -lSDL_ttf -lSDL_mixer

libs:
	make -C $(LIB)

clean:
	(cd $(LIB); make clean)
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)
	$(RM) /tmp/$(FONT)
	$(RM) /tmp/$(MUSIC)
	(cd $(LIB); make fclean)

re:		fclean all

.PHONY:		all clean fclean re
