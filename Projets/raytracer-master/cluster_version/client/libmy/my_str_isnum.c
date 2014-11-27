/*
** my_str_isnum.c for my_str_isnum in /home/merran_g/work/c_piscine/Piscine-C-Jour_06
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Mon Oct  7 21:11:55 2013 Geoffrey Merran
** Last update Tue Dec  3 18:23:37 2013 Geoffrey Merran
*/

#include "my.h"

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  if (str[0] == '\0')
    return (0);
  while (str[i] != '\0')
    {
      if (!(my_isdigit(str[i])))
	return (0);
      i++;
    }
  return (1);
}
