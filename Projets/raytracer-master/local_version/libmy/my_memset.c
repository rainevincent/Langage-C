/*
** my_memset.c for my_memset.c in /home/merran_g/work/c_elem/CPE_2013_getnextline
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Mon Nov 25 22:54:24 2013 Geoffrey Merran
** Last update Fri Mar 28 16:25:34 2014 Geoffrey Merran
*/

#include "my.h"

char	*my_memset(char *s, char c, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      s[i] = c;
      i++;
    }
  return (s);
}
