/*
** my_free_wordtab.c for libmy in /home/martel_c/rendu/Piscine-C-lib/my
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Wed Dec 18 16:38:27 2013 martelliere
** Last update Fri May 30 11:58:08 2014 martelliere
*/

#include "parser.h"

void    my_free_wordtab(char **tab)
{
  int   i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (tab[i] == NULL)
	exit(EXIT_FAILURE);
      free(tab[i]);
      i++;
    }
  if (tab == NULL)
    exit(EXIT_FAILURE);
  free(tab);
}
