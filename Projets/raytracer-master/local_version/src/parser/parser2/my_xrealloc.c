/*
** my_xrealloc.c for libmy in /home/martel_c/rendu/Piscine-C-lib/my
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Sat Nov 30 22:45:08 2013 martelliere
** Last update Mon Jun  2 13:21:04 2014 martelliere
*/

#include "parser.h"

void            *my_xrealloc(char *str, int size)
{
  char          *new_str;

  if (str == NULL)
    exit(EXIT_FAILURE);
  if (size == 0)
    return (str);
  new_str = my_xmalloc((strlen(str) + size + 1) * sizeof(char));
  *new_str = '\0';
  my_strcat(new_str, str);
  free(str);
  return (new_str);
}
