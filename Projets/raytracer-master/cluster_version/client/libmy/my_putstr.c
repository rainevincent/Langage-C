/*
** my_putstr.c for my_putstr in /home/merran_g/work/c_piscine/Piscine-C-Jour_04
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu Oct  3 09:45:07 2013 Geoffrey Merran
** Last update Thu Nov 14 15:51:57 2013 Geoffrey Merran
*/

#include "my.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
