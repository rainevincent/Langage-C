/*
** bind_keys.c for bind in /home/merran_g/work/c_elem/42sh
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun May 25 05:28:13 2014 Geoffrey Merran
** Last update Sun May 25 05:54:26 2014 Geoffrey Merran
*/

#include "line_editor.h"

void	bind_begin_line(t_line **line)
{
  (*line)->current->cursor = 0;
  (*line)->current = (*line)->head;
  (*line)->current->cursor = 1;
}

void	bind_end_line(t_line **line)
{
  (*line)->current->cursor = 0;
  (*line)->current = (*line)->tail;
  (*line)->current->cursor = 1;
}

void	bind_clear_term()
{
  char	*home_pos;
  char	*pos;

  home_pos = xtgetstr("ho", NULL);
  pos = xtgetstr("sc", NULL);
  if (home_pos != NULL && pos != NULL)
    {
      my_putstr(home_pos);
      my_putstr(pos);
      clear_term();
    }
}

void		bind_suppr_to_end(t_line **line)
{
  t_char	*tmp;
  t_char	*save;

  tmp = (*line)->current;
  while (tmp != NULL && tmp->c != '\0')
    {
      save = tmp->next;
      delete_char(tmp, line);
      tmp = save;
    }
  bind_end_line(line);
}
