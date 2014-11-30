/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/martel_c/rendu/Piscine-C-Jour_08
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Thu Oct 10 18:46:29 2013 martelliere
** Last update Thu Jun  5 19:20:37 2014 martelliere
*/

#include "parser.h"

int	char_is_alphanum(char c)
{
  if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
      (c >= 'A' && c <= 'Z') || c == '.' || c == '<' || c == '>' || c == '-' || c == ',')
    {
      return (0);
    }
  return (1);
}

int	count_words(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 1;
  while (str[i])
    {
      if (char_is_alphanum(str[i]) == 1)
	{
	  count = count + 1;
	}
      i = i + 1;
    }
  return (count);
}

int	strlen_custom(char *str, int i)
{
  int	c;

  c = 0;
  while (str[i] && char_is_alphanum(str[i]) == 0)
    {
      c = c + 1;
      i = i + 1;
    }
  return (c);
}

int	get_first_alphanum(char *str, int i)
{
  while (str[i] && char_is_alphanum(str[i]) == 1)
    {
      i = i + 1;
    }
  return (i);
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	j;
  int	k;
  char	**tab;

  i = 0;
  j = 0;
  tab = my_alloc_init((count_words(str) + 3) * sizeof(char *), 0);
  while (str[i])
    {
      i = get_first_alphanum(str, i);
      tab[j] = my_alloc_init((strlen_custom(str, i) + 3) * sizeof(char), 0);
      k = 0;
      while (str[i] && char_is_alphanum(str[i]) == 0)
	{
	  tab[j][k] = str[i];
	  k = k + 1;
	  i = i + 1;
	}
      tab[j++][k] = '\0';
    }
  tab[j] = NULL;
  return (tab);
}
