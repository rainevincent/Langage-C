/*
** token.c for  in /home/mediav_j/mabm/42sh/src/parser
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sun May 25 11:42:26 2014 Jeremy Mediavilla
** Last update Sun May 25 19:00:14 2014 Jeremy Mediavilla
*/

#include "parser.h"

int		check_word_token(t_link *list, char *cmd, int *i)
{
  int		tmp;
  char		*token;

  tmp = *i;
  while (cmd[*i + 1] != '\0' && is_valid_char(cmd[*i + 1], ALPHA_NUM) == 1)
    (*i)++;
  if ((token = my_xmalloc((*i + 2) * sizeof(char))) == NULL)
    return (-1);
  memset(token, '\0', (*i + 2));
  *i = tmp;
  tmp = 0;
  while (cmd[*i + 1] != '\0' && is_valid_char(cmd[*i + 1], ALPHA_NUM) == 1)
    {
      token[tmp] = cmd[*i];
      tmp++;
      (*i)++;
    }
  token[tmp] = cmd[*i];
  (*i)++;
  link_to_end(list, token, WORD);
  return (0);
}

int		check_spec_token(char *cmd, int *i, t_link *list)
{
  char		*tmp;
  int		j;

  tmp = "           | > < &";
  j = 11;
  while (j <= AND)
    {
      if (tmp[j] == ' ')
	j++;
      if (tmp[j] == cmd[*i])
	{
	  if (is_double_char(cmd, i) == 1)
	    {
	      link_to_end(list, "\0", (j + 1));
	      return (1);
	    }
	  else
	    {
	      link_to_end(list, "\0", j);
	      return (1);
	    }
	}
      j++;
    }
  return (0);
}

void		check_token2(t_link *list, int *j, char *cmd, int *i)
{
  char		*tmp;

  tmp = ";$!?*@()[]";
  while (*j <= C_HOOK)
    {
      if (*j == 4)
	(*j)++;
      if (cmd[*i] == tmp[*j])
	{
	  link_to_end(list, "\0", (*j + 1));
	  (*i)++;
	  *j = 41;
	}
      (*j)++;
    }
}

int		check_token(char *cmd, int *i, t_link *list)
{
  int		j;

  j = 0;
  if (cmd[*i] == '\"')
    {
      if (check_double_quotes(cmd, i, list, '\"') == -2)
	return (-1);
      (*i)++;
      return (0);
    }
  check_token2(list, &j, cmd, i);
  if (j != 42)
    if (check_spec_token(cmd, i, list) != 1)
      if (check_word_token(list, cmd, i) == -1)
	return (-1);
  return (0);
}

int		check_double_quotes(char *cmd, int *i, t_link *list, char c)
{
  int		tmp;
  char		*long_word;

  if (check_is_char_s(cmd, i, c, ';') == 0)
    return (aff_quote_err(list, get_invalid_cmd(cmd, *i, i, c)));
  (*i)++;
  tmp = *i;
  while (cmd[*i] != c)
    (*i)++;
  if ((long_word = my_xmalloc((*i + 1) * sizeof(char))) == NULL)
    return (-2);
  memset(long_word, '\0', (*i + 1));
  *i = tmp;
  tmp = 0;
  while (cmd[*i] != c)
    {
      long_word[tmp] = cmd[*i];
      (*i)++;
      tmp++;
    }
  link_to_end(list, long_word, WORD);
  return (0);
}
