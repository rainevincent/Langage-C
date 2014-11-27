/*
** exclamation.c for 42sh in /home/martel_c/rendu/42sh/pwd
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Tue May 27 13:39:33 2014 martelliere
** Last update Tue May 27 13:53:33 2014 martelliere
*/

void		find_cmd(t_shell *shell, char *str)
{
  t_history	*tmp;

  tmp = shell->history->tail;
  while (tmp != NULL)
    {
      if (tmp->cmd != NULL)
	{
	  if (strncmp(str, tmp->cmd, strlen(str)) == 0)
	    return (tmp->cmd);
	}
      tmp = tmp->prev;
    }
  printf("history: !%s: can't find a cmd beginning by that string.\n",
	 str);
  return (NULL);
}

void		find_number(t_shell *shell, char *nb)
{
  int		i;
  t_history	*tmp;

  i = 0;
  tmp = shell->history->tail;
  while (i < nb)
    tmp = tmp->prev;
  if (tmp != NULL && tmp->cmd != NULL)
    return (tmp->cmd);
  else
    {
      printf("history: can't access the %dth command.\n", nb);
      return (NULL);
    }
}
