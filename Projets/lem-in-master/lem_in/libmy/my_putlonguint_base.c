/*
** my_putlonguint_base.c for my_putlonguint_base in /home/merran_g/work/c_elem/PSU_2018_my_printf
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Nov 12 16:25:25 2013 Geoffrey Merran
** Last update Sat Nov 16 14:57:36 2013 Geoffrey Merran
*/

#include "my.h"

int			my_putlonguint_base(unsigned long int nb, char *base)
{
  unsigned long int	k;
  unsigned long int	len;
  int			char_print;

  char_print = 0;
  len = my_strlen(base);
  k = nb;
  if (nb > len - 1)
    {
      k = nb % len;
      char_print += my_putlonguint_base(nb / len, base);
    }
  my_putchar(base[k]);
  return (char_print + 1);
}
