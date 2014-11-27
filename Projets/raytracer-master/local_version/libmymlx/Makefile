##
## Makefile for MiniLibX in /home/boulon/work/c/raytraceur/minilibx
## 
## Made by Olivier Crouzet
## Login   <ol@epitech.net>
## 
## Started on  Tue Oct  5 15:56:43 2004 Olivier Crouzet
## Last update Mon May 19 23:36:19 2014 Geoffrey Merran
##


CC	= gcc

RM	= rm -rf

NAME	= libmymlx.a

INCLUDES= my_mlx.h mlx_utility.h

SRC	= change_rgb.c \
	init.c \
	mlx_utility.c \
	draw_line.c \
	draw_rectangle.c \
	my_pixel_put_to_image.c

OBJ	= $(SRC:.c=.o)
CFLAGS	+= -pedantic -ansi -W -Werror -Wall -Wextra -O3

all:	$(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Creating the libmymlx..."
	@cp $(INCLUDES) ../includes/
	@echo "Copying includes"

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
