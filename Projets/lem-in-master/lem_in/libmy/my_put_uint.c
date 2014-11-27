/*
** my_put_uint.c for my_put_uint in /home/merran_g/work/c_elem/PSU_2018_my_printf
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Nov  6 16:44:46 2013 Geoffrey Merran
** Last update Thu Nov 14 17:40:52 2013 Geoffrey Merran
*/

#include "my.h"

int		my_put_uint(unsigned int nb)
{
  unsigned int	k;
  int		char_print;

  char_print = 0;
  k = nb;
  if (nb > 9)
    {
      k = nb % 10;
      char_print += my_put_uint(nb / 10);
    }
  my_putchar(k + 48);
  return (char_print + 1);
}
