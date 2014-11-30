/*
** my_realloc.c for my_realloc in /home/merran_g/work/c_elem/CPE-2013-BSQ
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu Dec 12 13:01:25 2013 Geoffrey Merran
** Last update Thu Dec 12 13:04:27 2013 Geoffrey Merran
*/

#include "my.h"

char	*my_realloc(char *str, int size_alloc)
{
  int	size;
  char	*result;

  size = 0;
  while (str[size++] != '\0');
  result = my_xmalloc((size + size_alloc + 1) * sizeof(char));
  result = my_memset(result, '\0', (size + size_alloc + 1));
  my_strcpy(result, str);
  return (result);
}
