/*
** my_strdup.c for my_strdup in /home/merran_g/work/c_piscine/Piscine-C-Jour_08
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Oct  9 09:50:03 2013 Geoffrey Merran
** Last update Mon Feb 10 16:50:15 2014 Geoffrey Merran
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  char	*cpy;

  if (src[0] != '\0')
    {
      cpy = my_xmalloc((my_strlen(src) + 1) * sizeof(char));
      my_strcpy(cpy, src);
    }
  else
    return (NULL);
  return (cpy);
}
