/*
** get_cmd.c for getcmd in /home/merran_g/work/c_elem/42sh
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed May 28 02:35:51 2014 Geoffrey Merran
** Last update Wed May 28 02:35:57 2014 Geoffrey Merran
*/

#include "parser.h"

char		**get_cmd(t_link *start)
{
  char		**cmd;
  int		i;
  t_link	*tmp;

  tmp = start;
  i = 0;
  while (tmp && tmp->type == 0)
    {
      i++;
      tmp = tmp->next;
    }
  if (i == 0)
    return (NULL);
  cmd = my_xmalloc((i + 1) * sizeof(char *));
  tmp = start;
  i = 0;
  while (tmp && tmp->type == 0)
    {
      cmd[i++] = strdup(tmp->data);
      tmp = tmp->next;
    }
  cmd[i] = NULL;
  return (cmd);
}
