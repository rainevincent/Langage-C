/*
** parser_tools2.c for  in /home/mediav_j/mabm/42sh/src/parser
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sun May 25 11:51:54 2014 Jeremy Mediavilla
** Last update Sun May 25 15:13:39 2014 Jeremy Mediavilla
*/

#include "parser.h"

char		*get_invalid_cmd_final(int j, int *tmp, char *cmd, int i)
{
  char		*final;
  int		len;

  len = i - *tmp + 2;
  if ((final = my_xmalloc(len * sizeof(char))) == NULL)
    return (NULL);
  memset(final, '\0', len);
  if (cmd[*tmp] == ';')
    (*tmp)++;
  while (*tmp <= i)
    {
      final[j] = cmd[*tmp];
      (*tmp)++;
      j++;
    }
  return (final);
}

char		*get_invalid_cmd(char *cmd, int i, int *test, char c)
{
  int		j;
  char		*final;
  int		tmp;

  j = 0;
  while (i > 0 && cmd[i] != c)
    i--;
  while (i > 0 && cmd[i] != ';')
    i--;
  tmp = i;
  i++;
  while (cmd[i] && cmd[i] != ';')
    i++;
  if ((final = get_invalid_cmd_final(j, &tmp, cmd, i)) == NULL)
    return (NULL);
  *test = tmp - 1;
  return (final);
}

int		is_valid_access(t_type type, int *access)
{
  int		i;

  i = 0;
  while (access[i] != -1)
    {
      if ((int)type == access[i])
	return (1);
      i++;
    }
  return (-1);
}

int		is_valid_end_access(t_tree *tree)
{
  int		i;

  i = 1;
  while (tree->access[i] != -1)
    {
      if (tree->access[i] == 19)
	return (0);
      i++;
    }
  aff_type_error(tree->curr_type, 19);
  return (-1);
}
