/*
** my_xmalloc.c for libmy in /home/martel_c/rendu/Piscine-C-lib/my
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Sat Oct 19 19:59:49 2013 martelliere
** Last update Tue May 13 17:48:34 2014 martelliere
*/

#include "parser.h"

void            *my_xmalloc(int size)
{
  void		*str;

  str = malloc(size);
  if (str == NULL)
    {
      printf("RT: can't perform malloc.\n");
      return (NULL);
    }
  return (str);
}
