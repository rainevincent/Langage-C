/*
** tab_functions.c for  in /home/mediav_j/mabm/42sh/src/core
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Thu May  8 17:19:33 2014 Jeremy Mediavilla
** Last update Wed May 14 15:45:56 2014 Geoffrey Merran
*/

#include "core.h"

void		print_tab(char **mtab)
{
  int		i;

  i = 0;
  while (mtab[i] != NULL)
    {
      printf("%s\n", mtab[i]);
      i++;
    }
}

int		tab_size(char **mtab)
{
  int		i;

  i = 0;
  while (mtab[i] != NULL)
    i++;
  return (i);
}
