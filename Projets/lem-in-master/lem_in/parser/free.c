/*
** free.c for free in /home/merran_g/work/c_elem/lem-in/lem_in
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri Apr 25 21:13:14 2014 Geoffrey Merran
** Last update Fri Apr 25 21:14:02 2014 Geoffrey Merran
*/

#include "parser.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
