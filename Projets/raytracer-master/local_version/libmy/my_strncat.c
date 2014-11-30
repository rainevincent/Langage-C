/*
** my_strncat.c for my_strncat in /home/merran_g/work/c_piscine/Piscine-C-Jour_07
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Tue Oct  8 14:31:49 2013 Geoffrey Merran
** Last update Thu Nov 14 17:37:57 2013 Geoffrey Merran
*/

#include "my.h"

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	dest_len;

  dest_len = my_strlen(dest);
  i = 0;
  while (src[i] != '\0' && i < nb)
    {
      dest[dest_len + i] = src[i];
      i++;
    }
  dest[dest_len + i] = '\0';
  return (dest);
}
