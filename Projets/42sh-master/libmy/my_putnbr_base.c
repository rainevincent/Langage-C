/*
** my_putnbr_base.c for my_putnbr_base in /home/merran_g/work/c_elem/PSU_2018_my_printf
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Nov  6 14:37:16 2013 Geoffrey Merran
** Last update Thu Nov 14 17:39:00 2013 Geoffrey Merran
*/

#include "my.h"

int	my_putnbr_base(int nb, char *base)
{
  int	k;
  int	len;
  int	char_print;

  char_print = 0;
  len = my_strlen(base);
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  k = nb;
  if (nb > len - 1)
    {
      k = nb % len;
      char_print += my_putnbr_base(nb / len, base);
    }
  my_putchar(base[k]);
  return (char_print + 1);
}
