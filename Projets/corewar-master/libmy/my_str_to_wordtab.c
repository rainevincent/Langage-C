/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/merran_g/work/c_piscine/Piscine-C-Jour_08
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Thu Oct 10 12:37:32 2013 Geoffrey Merran
** Last update Wed Dec 11 17:24:49 2013 Geoffrey Merran
*/

#include <stdlib.h>
#include "my.h"

int	my_isalphanum(char str)
{
  if (my_isdigit(str) || my_isalpha(str))
    return (1);
  return (0);
}

int	my_countword(char *str)
{
  int	i;
  int	a;

  i = 0;
  a = 0;
  while (str[i] != '\0')
    {
      while (!(my_isalphanum(str[i])) && str[i] != '\0')
	i++;
      if (my_isalphanum(str[i]))
	{
	  while (my_isalphanum(str[i]))
	    i++;
	  a++;
	}
    }
  return (a);
}

char	**my_countchar(char *str, char **return_tab)
{
  int	i;
  int	a;
  int	j;

  i = 0;
  a = 0;
  j = 0;
  while (str[i] != '\0')
    {
      while (!(my_isalphanum(str[i])) && str[i] != '\0')
	i++;
      if (my_isalphanum(str[i]))
	{
	  while (my_isalphanum(str[i]))
	    {
	      i++;
	      a++;
	    }
	  return_tab[j] = my_xmalloc((a + 1) * sizeof(*(return_tab[j])));
	  a = 0;
	  j++;
	}
    }
  return_tab[j] = NULL;
  return (return_tab);
}

char	**my_putstr_intab(char *str, char **return_tab)
{
  int	i;
  int	a;
  int	j;

  a = 0;
  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      while (!(my_isalphanum(str[i])) && str[i] != '\0')
	i++;
      if (my_isalphanum(str[i]))
	{
	  while (my_isalphanum(str[i]))
	    {
	      return_tab[j][a] = str[i];
	      a++;
	      i++;
	    }
	  return_tab[j][a] = '\0';
	  a = 0;
	  j++;
	}
    }
  return (return_tab);
}

char	**my_str_to_wordtab(char *str)
{
  int	j;
  char	**return_tab;

  j = my_countword(str);
  if (str[0] == '\0')
    return (NULL);
  return_tab = my_xmalloc((j + 1) * sizeof(*return_tab));
  return_tab = my_countchar(str, return_tab);
  return_tab = my_putstr_intab(str, return_tab);
  return (return_tab);
}
