/*
** parser_tools.c for  in /home/mediav_j/mabm/42sh/src/parser
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sun May 25 11:46:00 2014 Jeremy Mediavilla
** Last update Sun May 25 11:49:02 2014 Jeremy Mediavilla
*/

#include "parser.h"

void		aff_my_list(t_link *list)
{
  int		i;

  i = 0;
  while (list->prev != NULL)
    list = list->prev;
  while (list != NULL)
    {
      if (list->data != NULL)
	printf("[%s] : %i\n", list->data, list->type);
      else
      	printf("NULL : %i\n", list->type);
      list = list->next;
      i++;
    }
  printf("%i maillons\n", i);
}

int		is_valid_char(char c, char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (c == str[i])
	return (1);
      i++;
    }
  return (0);
}

int		is_double_char(char *cmd, int *i)
{
  if (cmd[*i] != '\0' && cmd[*i] == cmd[*i + 1])
    {
      *i += 2;
      return (1);
    }
  (*i)++;
  return (0);
}

int		check_is_char_s(char *cmd, int *i, char c, char delim)
{
  int		tmp;

  tmp = *i;
  (*i)++;
  while (cmd[*i] && cmd[*i] != delim)
    {
      if (cmd[*i] == c)
	{
	  *i = tmp;
	  return (1);
	}
      (*i)++;
    }
  return (0);
}

int		is_equal_nbr_char(char *cmd, int *i, t_special *info)
{
  int		cpt1;
  int		cpt2;
  int		end;
  int		start;

  cpt1 = 0;
  cpt2 = 0;
  end = *i;
  start = *i;
  while (start > 0 && cmd[start] != ';')
    start--;
  start++;
  while (cmd[end] && cmd[end] != ';')
    end++;
  while (start < end)
    {
      if (cmd[start] == info->open)
      cpt1++;
      if (cmd[start] == info->close)
      cpt2++;
      start++;
    }
  return (cpt1 - cpt2);
}
