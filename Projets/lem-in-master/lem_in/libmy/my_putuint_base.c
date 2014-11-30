/*
** my_putuint_base.c for my_putuint_base in /home/merran_g/work/c_elem/PSU_2018_my_printf
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu Nov  7 16:40:23 2013 Geoffrey Merran
** Last update Sat Nov 16 14:57:22 2013 Geoffrey Merran
*/

#include "my.h"

int		my_putuint_base(unsigned int nb, char *base)
{
  unsigned int	k;
  unsigned int	len;
  int	char_print;

  char_print = 0;
  len = my_strlen(base);
  k = nb;
  if (nb > len - 1)
    {
      k = nb % len;
      char_print += my_putuint_base(nb / len, base);
    }
  my_putchar(base[k]);
  return (char_print + 1);
}
