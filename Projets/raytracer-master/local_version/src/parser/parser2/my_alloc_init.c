/*
** my_alloc_init.c for libmy in //home/martel_c/rendu/Piscine-C-lib/my
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Thu Nov 14 12:52:56 2013 martelliere
** Last update Tue May 13 17:48:57 2014 martelliere
*/

#include "parser.h"

void    *my_alloc_init(int size, char c)
{
  int   i;
  char  *tab;

  i = 0;
  tab = my_xmalloc(size);
  while (i < size)
    {
      tab[i] = c;
      i = i + 1;
    }
  tab[size - 1] = '\0';
  return (tab);
}
