/*
** flag3.c for flag3 in /home/merran_g/work/c_elem/PSU_2018_my_printf
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Nov 12 12:43:09 2013 Geoffrey Merran
** Last update Sun Nov 17 15:39:37 2013 Geoffrey Merran
*/

#include "my_printf.h"
#include "my.h"

void	print_zero(char c)
{
  int	i;

  i = 1;
  while (c * i < 64)
    {
      my_put_nbr(0);
      i = i * 8;
    }
}

int	flag_S(va_list ap)
{
  char	*str;
  int	char_print;
  int	i;

  i = 0;
  char_print = 0;
  str = va_arg(ap, char *);
  while (str[i] != '\0')
  {
    if (my_isprintable(str[i]))
      {
	my_putchar(str[i]);
	char_print++;
      }
    else
      {
	my_putchar('\\');
	print_zero(str[i]);
	my_putuint_base(str[i], "01234567");
	char_print = char_print + 4;
      }
    i++;
  }
  return (char_print);
}

int	flag_n(va_list ap, int nb_char)
{
  int	*flag_n;

  flag_n = va_arg(ap, int *);
  *flag_n = nb_char;
  return (0);
}

int	flag_t(va_list ap)
{
  return (my_show_wordtab(va_arg(ap, char **)));
}
