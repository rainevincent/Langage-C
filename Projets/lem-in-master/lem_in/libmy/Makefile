##
## MakeFile for MakeFile in /home/merran_g/rendu/Piscine-C-lib/my
## 
## Made by Geoffrey Merran
## Login   <merran_g@epitech.net>
## 
## Started on  Mon Oct 21 09:58:36 2013 Geoffrey Merran
## Last update Sun Apr 13 16:40:12 2014 Geoffrey Merran
##

RM=		rm -f

LIB=		libmy.a

INCLUDE=	my.h my_printf.h

CFLAGS=		-ansi -pedantic -W -Werror -Wextra -Wall -O3

SRC=		my_putchar.c \
		my_putstr.c \
		my_find_prime_sup.c \
		my_getnbr.c \
		my_isneg.c \
		my_is_prime.c \
		my_power_rec.c \
		my_put_nbr.c \
		my_revstr.c \
		my_show_wordtab.c \
		my_sort_int_tab.c \
		my_square_root.c \
		my_strcapitalize.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strcut.c \
		my_strfusion.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isprintable.c \
		my_str_isupper.c \
		my_strlcat.c \
		my_strlen.c \
		my_lowcase.c \
		my_strncat.c \
		my_strncmp.c \
		my_strncpy.c \
		my_strstr.c \
		my_str_to_wordtab.c \
		my_strd_to_wordtab.c \
		my_strupcase.c \
		my_swap.c \
		my_convert_base.c \
		my_putnbr_base.c \
		my_getnbr_base.c \
		my_strdup.c \
		my_atoi.c \
		my_isprintable.c \
		my_put_uint.c \
		my_putuint_base.c \
		my_putlonguint_base.c \
		my_printf.c \
		flag.c \
		flag2.c \
		flag3.c \
		xmalloc.c \
		my_memset.c \
		my_realloc.c \
		my_puterr.c \
		conv_itc.c \

OBJ=		$(SRC:.c=.o)

all:		$(LIB)

$(LIB):		$(OBJ)
	@ar rc $(LIB) $(OBJ)
	@echo "Linking the .o ..."
	ranlib $(LIB)
	cp $(INCLUDE) ../includes

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(LIB)

re:	fclean all

.PHONY: all clean fclean re
