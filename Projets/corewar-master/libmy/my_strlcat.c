/*
** my_strlcat.c for my_strlcat.c in /home/merran_g/work/c_piscine/Piscine-C-Jour_07
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Tue Oct  8 20:32:28 2013 Geoffrey Merran
** Last update Thu Nov 14 17:19:13 2013 Geoffrey Merran
*/

#include "my.h"

int	my_strlcat(char *dest, char *src, int size)
{
  int	i;
  int	dest_len;
  int	src_len;

  i = 0;
  dest_len = my_strlen(dest);
  src_len = my_strlen(src);
  if (size > dest_len + src_len + 1)
    size = dest_len + src_len + 1;
  if (size < dest_len + 1)
    return (size + src_len);
  while ((size - dest_len - 1 - i) > 0)
    {
      dest[dest_len + i] = src[i];
      i++;
    }
  dest[dest_len + i] = '\0';
  return (dest_len + src_len);
}
