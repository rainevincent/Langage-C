/*
** my.h for my.h in /home/merran_g/work/c_piscine/Piscine-C-Jour_09
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Thu Oct 10 12:00:24 2013 Geoffrey Merran
** Last update Wed May 14 15:52:27 2014 Geoffrey Merran
*/

#ifndef MY_
# define MY_
# include "my_printf.h"

void			my_putchar(char c);
int			my_put_nbr(int nb);
int			my_isneg(int nb);
int			my_swap(int *a, int *b);
int			my_putstr(char *str);
int			my_strlen(char *str);
int			my_getnbr(char *str);
void			my_sort_int_tab(int *, int size);
int			my_power_rec(int nb, int power);
int			my_square_root(int nb);
int			my_is_prime(int nombre);
int			my_find_prime_sup(int nb);
char			*my_strcpy(char *dest, char *src);
char			*my_strncpy(char *dest, char *src, int nb);
char			*my_revstr(char *str);
char			*my_strstr(char *str);
int			my_strcmp(char *s1, char *s2);
int			my_strncmp(char *s1, char *s2, int nb);
char			*my_strupcase(char *str);
char			*my_lowcase(char *str);
char			*my_strcapitalize(char *str);
int			my_str_isalpha(char *str);
int			my_str_isnum(char *str);
int			my_str_islower(char *str);
int			my_str_isprintable(char *str);
int			my_showstr(char *str);
int			my_showmen(char *str);
char			*my_strcat(char *dest, char *src);
char			*my_strncat(char *dest, char *src, int nb);
int			my_strlcat(char *dest, char *src, int size);
char			**my_str_to_wordtab(char *str);
char			**my_strd_to_wordtab(char *str, char *delim);
int			my_show_wordtab(char **);
char			*my_convert_base(char *nbr, char *base_from, char *base_to);
int			my_putnbr_base(int nb, char *base);
int			my_getnbr_base(char *str, char *base);
char			*my_strdup(char *src);
int			my_atoi(char *str);
int			my_isprintable(char c);
int			my_put_uint(unsigned int nb);
int			my_putuint_base(unsigned int nb, char *base);
int			my_putlonguint_base(unsigned long int nb, char *base);
void			*my_xmalloc(int size);
char			*my_realloc(char *str, int size_alloc);
int			my_isdigit(char c);
int			my_isalpha(char c);
char			*my_memset(char *s, char c, int size);
int			my_strlen_tabs(char **);
char			*my_strcut(char *str, int start, int end);
char			*my_strfusion(char *dest, char *src);
void			my_puterr(char *err);
int			my_error(char *err);
char			*int_to_str(int	nb);

#endif /* MY_ */
