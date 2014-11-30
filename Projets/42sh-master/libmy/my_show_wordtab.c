/*
** my_show_wordtab.c for my_show_wordtab in /home/merran_g/work/c_piscine/Piscine-C-Jour_08
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Thu Oct 10 16:47:28 2013 Geoffrey Merran
** Last update Sat Nov 16 15:36:10 2013 Geoffrey Merran
*/

#include <stdio.h>
#include "my.h"

int	my_strlen_tabs(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

int	my_show_wordtab(char **tab)
{
  int	len;
  int	i;
  int	char_print;

  i = 0;
  char_print = 0;
  len = my_strlen_tabs(tab);
  while (i < len)
    {
      my_putstr(tab[i]);
      char_print += my_strlen(tab[i]) + 1;
      my_putchar('\n');
      i++;
    }
  return (char_print);
}
