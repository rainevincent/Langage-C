/*
** history.c for history 42sh in /home/martel_c/rendu/42sh
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Fri May  9 15:49:56 2014 martelliere
** Last update Wed May 28 03:08:19 2014 Geoffrey Merran
*/

#include "history.h"

void		show_history(t_history *history)
{
  t_hlist	*tmp;
  int		i;

  tmp = history->head;
  i = 1;
  while (tmp)
    {
      printf("%d %s\n", i, tmp->name);
      i++;
      tmp = tmp->next;
    }
}

int		builtin_history(t_shell *shell, char **cmd)
{
  (void) cmd;
  show_history(shell->history);
  return (0);
}

int		init_history(t_shell **shell)
{
  (*shell)->history->head = NULL;
  (*shell)->history->current = NULL;
  (*shell)->history->tail = NULL;
  (*shell)->history->size = 0;
  return (get_history((*shell)->history, *shell));
}

