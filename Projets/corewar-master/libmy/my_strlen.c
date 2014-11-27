/*
** my_strlen.c for my_strlen in /home/merran_g/work/c_piscine/Piscine-C-Jour_04
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu Oct  3 10:52:10 2013 Geoffrey Merran
** Last update Thu Nov 14 16:48:04 2013 Geoffrey Merran
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	 i;

  i = 0;
  while (*str != '\0')
    {
      str++;
      i++;
    }
  return (i);
}
