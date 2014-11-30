/*
** my_isneg.c for my_isneg in /home/merran_g/work/c_piscine/Piscine-C-Jour_03
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Oct  2 11:04:58 2013 Geoffrey Merran
** Last update Sat Nov 30 09:32:35 2013 Geoffrey Merran
*/

#include "my.h"

int	my_isneg(int n)
{
  if (n < 0)
    my_putchar('N');
  else
    my_putchar('P');
  return 0;
}
