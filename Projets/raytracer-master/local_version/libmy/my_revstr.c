/*
** my_revstr.c for my_revstr in /home/merran_g/work/c_piscine/Piscine-C-Jour_06/ex_03
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Mon Oct  7 10:27:43 2013 Geoffrey Merran
** Last update Thu Nov 14 15:52:38 2013 Geoffrey Merran
*/

#include "my.h"

char	my_swap_bis(char *a, char *b)
{
  char	swap;

  swap = *a;
  *a = *b;
  *b = swap;
  return (0);
}

char	*my_revstr(char *str)
{
  int	size_str;
  int	i;
  char	*ptr_a;
  char	*ptr_b;

  i = 0;
  size_str = my_strlen(str);
  while (i < (size_str - i))
    {
      ptr_a = &str[i];
      ptr_b = &str[size_str - i - 1];
      my_swap_bis(ptr_a, ptr_b);
      i++;
    }
  return (str);
}
