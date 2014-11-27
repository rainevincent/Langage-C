/*
** my_strd_to_wordtab.c for my_strd_to_wordtab in /home/merran_g/work/c_elem/PSU_2013_minishell1/libmy
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Dec 11 19:53:50 2013 Geoffrey Merran
** Last update Thu Apr 24 15:52:21 2014 Geoffrey Merran
*/

#include <stdlib.h>
#include "my.h"

int	seek_char(char *str, char c)
{
  int	i;

  i = -1;
  while (str[++i])
    {
      if (str[i] == c)
	return (1);
    }
  return (0);
}

int	my_countdword(char *str, char *delim)
{
  int	i;
  int	a;

  i = 0;
  a = 0;
  while (str[i] != '\0')
    {
      while (seek_char(delim, str[i]) == 1 && str[i] != '\0')
	i++;
      if (seek_char(delim, str[i]) == 0 && str[i] != '\0')
	{
	  while (seek_char(delim, str[i]) == 0 && str[i] != '\0')
	    i++;
	  a++;
	}
    }
  return (a);
}

char	**my_countdchar(char *str, char **return_tab, char *delim)
{
  int	i;
  int	a;
  int	j;

  i = 0;
  a = 0;
  j = 0;
  while (str[i] != '\0')
    {
      while (seek_char(delim, str[i]) == 1 && str[i] != '\0')
	i++;
      if (seek_char(delim, str[i]) == 0 && str[i] != '\0')
	{
	  while (seek_char(delim, str[i]) == 0 && str[i] != '\0')
	    {
	      i++;
	      a++;
	    }
	  return_tab[j] = my_xmalloc((a + 1) * sizeof(char));
	  a = 0;
	  j++;
	}
    }
  return_tab[j] = NULL;
  return (return_tab);
}

char	**my_putstr_indtab(char *str, char **return_tab, char *delim)
{
  int	i;
  int	a;
  int	j;

  a = 0;
  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      while (seek_char(delim, str[i]) == 1 && str[i] != '\0')
	i++;
      if (seek_char(delim, str[i]) == 0 && str[i] != '\0')
	{
	  while (seek_char(delim, str[i]) == 0 && str[i] != '\0')
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

char	**my_strd_to_wordtab(char *str, char *delim)
{
  int	j;
  char	**return_tab;

  if (str == NULL || str[0] == '\0')
    return (NULL);
  j = my_countdword(str, delim);
  return_tab = my_xmalloc((j + 1) * sizeof(*return_tab));
  return_tab = my_countdchar(str, return_tab, delim);
  return_tab = my_putstr_indtab(str, return_tab, delim);
  return (return_tab);
}
