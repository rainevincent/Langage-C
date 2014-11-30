/*
** my_strcat.c for my_strcat in /home/merran_g/work/c_piscine/Piscine-C-Jour_07
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Tue Oct  8 14:02:28 2013 Geoffrey Merran
** Last update Thu Nov 14 16:36:50 2013 Geoffrey Merran
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	dest_len;

  dest_len = my_strlen(dest);
  i = 0;
  while (src[i] != '\0')
    {
      dest[dest_len + i] = src[i];
      i++;
    }
  dest[dest_len + i] = '\0';
  return (dest);
}
