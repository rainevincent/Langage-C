/*
** my_strlowcase.c for my_strlowcase in /home/merran_g/work/c_piscine/Piscine-C-Jour_06/ex_08
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Mon Oct  7 17:08:11 2013 Geoffrey Merran
** Last update Thu Nov 28 23:58:51 2013 Geoffrey Merran
*/

#include <stdlib.h>
#include "my.h"

char	*my_lowcase(char *str)
{
  int	i;
  char	*result;

  i = 0;
  result = my_xmalloc((my_strlen(str) + 1) * sizeof(char));
  my_memset(result, '\0', my_strlen(str) + 1);
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	{
	  result[i] = str[i] + 32;
	}
      else
	result[i] = str[i];
      i++;
    }
  return (result);
}
