/*
** convert.c for convert in /home/merran_g/work/c_piscine/Piscine-C-Jour_14/ex_01
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Thu Oct 24 11:03:30 2013 Geoffrey Merran
** Last update Mon Nov 11 19:33:45 2013 Geoffrey Merran
*/

#include <stdlib.h>
#include "my.h"

char    *my_convert_base(char *nbr, char *base_from, char *base_to)
{
  int   i;
  int   nb;
  char  *res;

  i = 0;
  res = malloc(sizeof(char) * 300);
  nb = my_getnbr_base(nbr, base_from);
  while (nb > 0)
    {
      res[i] = base_to[nb % my_strlen(base_to)];
      nb = nb / my_strlen(base_to);
      i = i + 1;
    }
  res[i] = '\0';
  res = my_revstr(res);
  return (res);
}
