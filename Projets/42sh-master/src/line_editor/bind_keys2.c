/*
** bind_keys2.c for bind_keys2 in /home/merran_g/work/c_elem/42sh
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun May 25 06:03:55 2014 Geoffrey Merran
** Last update Tue May 27 13:48:46 2014 Geoffrey Merran
*/

#include "line_editor.h"

void		bind_move_next_word(t_line **line)
{
  t_char	*tmp;

  tmp = (*line)->current;
  while (tmp && tmp->c != '\0' && tmp->c != ' ')
    tmp = tmp->next;
  while (tmp->c == ' ')
    tmp = tmp->next;
  (*line)->current->cursor = 0;
  (*line)->current = tmp;
  (*line)->current->cursor = 1;
}

void		bind_move_prev_word(t_line **line)
{
  t_char	*tmp;

  tmp = (*line)->current;
  while (tmp && tmp->prev != NULL && tmp->c != ' ')
    tmp = tmp->prev;
  while (tmp->c == ' ')
    tmp = tmp->prev;
  (*line)->current->cursor = 0;
  (*line)->current = tmp;
  (*line)->current->cursor = 1;
}

void		bind_swap_char(t_line **line)
{
  t_char	*tmp;

  tmp = (*line)->current;
  if (tmp == (*line)->head)
    return ;
  if (tmp == (*line)->tail && (*line)->size >= 3)
    {
      if ((*line)->size == 3)
	(*line)->head = (*line)->head->next;
      swap_char(tmp->prev->prev, tmp->prev);
    }
  else if ((*line)->size >= 3)
    {
      if (tmp == (*line)->head->next)
	(*line)->head = tmp;
      swap_char(tmp->prev, tmp);
      (*line)->current = tmp->next->next;
      tmp->cursor = 0;
      (*line)->current->cursor = 1;
    }
}
