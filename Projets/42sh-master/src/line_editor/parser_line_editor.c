/*
** parser_line_editor.c for parser_line_editor in /home/merran_g/work/c_elem/42sh/src/line_editor
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed May 14 18:05:01 2014 Geoffrey Merran
** Last update Tue May 27 12:42:38 2014 Geoffrey Merran
*/

#include "line_editor.h"

void	move_cursor(int direction, t_line **line)
{
  if (direction == RIGHT)
    {
      if ((*line)->current->next != NULL)
	{
	  (*line)->current->cursor = 0;
	  (*line)->current = (*line)->current->next;
	  (*line)->current->cursor = 1;
	}
    }
  else
    {
      if ((*line)->current->prev != NULL)
	{
	  (*line)->current->cursor = 0;
	  (*line)->current = (*line)->current->prev;
	  (*line)->current->cursor = 1;
	}
    }
}

int	parse_arrow(char *buffer, t_line **line, int size, t_shell *shell)
{
  if (size == 3)
    {
      if (buffer[0] == 27 && buffer[1] == '[' && buffer[2] == 'A')
	return (move_history(UP, line, shell));
      else if (buffer[0] == 27 && buffer[1] == '[' && buffer[2] == 'B')
	return (move_history(DOWN, line, shell));
      if (buffer[0] == 27 && buffer[1] == '[' && buffer[2] == 'C')
	move_cursor(RIGHT, line);
      else if (buffer[0] == 27 && buffer[1] == '[' && buffer[2] == 'D')
	move_cursor(LEFT, line);
    }
  return (0);
}

void	parse_delete(char *buffer, t_line **line, int size)
{
  if (size == 1 && buffer[0] == 127)
    {
      if ((*line)->current->prev != NULL && (*line)->current->prev->c != '\0')
        delete_char((*line)->current->prev, line);
    }
  if (size == 4 && buffer[0] == 27 && buffer[1] == '['
      && buffer[2] == '3' && buffer[3] == '~')
    {
      if ((*line)->current != NULL && (*line)->current->c != '\0')
        delete_char((*line)->current, line);
    }
}

void	parse_bind(char *buffer, t_line **line, int size)
{
  if (size == 1)
    {
      if (buffer[0] == 1)
	bind_begin_line(line);
      if (buffer[0] == 5)
	bind_end_line(line);
      if (buffer[0] == 12)
	bind_clear_term();
      if (buffer[0] == 11)
	bind_suppr_to_end(line);
      if (buffer[0] == 20)
	bind_swap_char(line);
    }
  if (size == 6)
    {
      if (buffer[0] == 27 && strcmp(&buffer[1], "[1;5D"))
	bind_move_next_word(line);
      if (buffer[0] == 27 && strcmp(&buffer[1], "[1;5C"))
	bind_move_prev_word(line);
    }
}

int	parser_line_editor(char *buffer, t_line **line, t_shell *shell)
{
  int	size;

  size = strlen(buffer);
  if (my_isprintable(buffer[0]) && size == 1)
    return (add_char(buffer[0], line));
  if (parse_arrow(buffer, line, size, shell) == -1)
    return (-1);
  parse_delete(buffer, line, size);
  parse_bind(buffer, line, size);
  if (size == 1 && buffer[0] == 4)
    shell->end = 1;
  return (0);
}
