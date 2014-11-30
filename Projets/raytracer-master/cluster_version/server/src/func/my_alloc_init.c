/*
** my_alloc_init.c for libmy in //home/martel_c/rendu/Piscine-C-lib/my
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Thu Nov 14 12:52:56 2013 martelliere
** Last update Sat Jun  7 21:25:25 2014 Joris Bertomeu
*/

#include "parser.h"

void    *my_alloc_init(int size, char c)
{
  int   i;
  char  *tab;

  i = 0;
  tab = malloc(size);
  while (i < size)
    {
      tab[i] = c;
      i = i + 1;
    }
  tab[size - 1] = '\0';
  return (tab);
}

