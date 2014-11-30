/*
** history_interaction.c for history_interaction in /home/merran_g/work/c_elem/42sh/src/line_editor
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri May 23 00:44:06 2014 Geoffrey Merran
** Last update Sat May 24 20:06:20 2014 Geoffrey Merran
*/

#include "line_editor.h"

int	load_history_line(t_hlist *hline, t_line **line)
{
  int	i;

  i = 0;
  while (hline->name[i])
    {
      if (add_char(hline->name[i++], line) == -1)
	return (-1);
    }
  return (0);
}

int	move_history_up(t_line **line, t_shell *shell)
{
  if (shell->history->current == NULL && shell->history->tail != NULL)
    {
      delete_line_edit(*line);
      shell->history->current = shell->history->tail;
      return (load_history_line(shell->history->tail, line));
    }
  else
    {
      if (shell->history->current != NULL &&
	  shell->history->current->prev != NULL)
	{
	  delete_line_edit(*line);
	  shell->history->current = shell->history->current->prev;
	  return (load_history_line(shell->history->current, line));
	}
    }
  return (0);
}

int	move_history_down(t_line **line, t_shell *shell)
{
  if (shell->history->current != NULL)
    {
      delete_line_edit(*line);
      if (shell->history->current->next != NULL)
	{
	  shell->history->current = shell->history->current->next;
	  return (load_history_line(shell->history->current, line));
	}
      else
	shell->history->current = NULL;
    }
  return (0);
}

int	move_history(int way, t_line **line, t_shell *shell)
{
  if (way == UP)
    return (move_history_up(line, shell));
  else if (way == DOWN)
    return (move_history_down(line, shell));
  return (0);
}
