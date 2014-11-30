/*
** my_strcut.c for my_strcut in /home/merran_g/work/c_elem/CPE-2013-BSQ
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Dec  3 23:33:27 2013 Geoffrey Merran
** Last update Sun Apr 13 16:41:59 2014 Geoffrey Merran
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcut(char *str, int start, int end)
{
  char	*res;
  int	i;

  i = start - 1;
  res = NULL;
  if (str != NULL && start < end)
    {
      res = my_xmalloc((my_strlen(str) * (end - start + 2)) * sizeof(char));
      while (++i < end)
	res[i - start] = str[i];
      res[i - start] = '\0';
    }
  return (res);
}
