/*
** my_put_nbr.c for my_putnbr in /home/merran_g/work/c_piscine/createlib/files.c
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Mon Oct 21 20:33:49 2013 Geoffrey Merran
** Last update Thu Nov 14 15:52:25 2013 Geoffrey Merran
*/

#include "my.h"

int	my_put_nbr(int nb)
{
  int	k;
  int	char_print;

  char_print = 0;
  if (nb == -2147483648)
    {
      my_putstr("-2147483648");
      return (11);
    }
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  k = nb;
  if (nb > 9)
    {
      k = nb % 10;
      char_print += my_put_nbr(nb / 10);
    }
  my_putchar(k + 48);
  return (char_print + 1);
}
