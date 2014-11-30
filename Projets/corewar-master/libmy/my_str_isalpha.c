/*
** my_str_isalpha.c for my_str_isalpha in /home/merran_g/work/c_piscine/Piscine-C-Jour_06
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Mon Oct  7 20:58:25 2013 Geoffrey Merran
** Last update Tue Dec  3 18:22:07 2013 Geoffrey Merran
*/

#include "my.h"

int	my_str_alpha(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(my_isdigit(str[i]) || my_isalpha(str[i])))
	{
	  return (0);
	}
      i++;
    }
  return (1);
}
