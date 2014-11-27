/*
** char.c for char in /home/merran_g/work/c_elem/42sh
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed May 14 17:11:28 2014 Geoffrey Merran
** Last update Sun May 25 05:46:10 2014 Geoffrey Merran
*/

#include "line_editor.h"

int	rev_mode(char c)
{
  char	*rev;
  char	*rev_end;

  rev = xtgetstr("so", NULL);
  rev_end = xtgetstr("se", NULL);
  if (rev == NULL || rev_end == NULL)
    return (-1);
  my_printf("%s%c%s", rev, c, rev_end);
  return (0);
}

int	write_prompt_char(t_char *c)
{
  if (c->cursor == 1)
    {
      if (c->c == '\0')
	return (rev_mode(' '));
      else
	return (rev_mode(c->c));
    }
  else
    {
      if (c->c == '\0')
	my_putchar(' ');
      else
	my_putchar(c->c);
    }
  return (0);
}

void		add_newchar(t_char *new, t_line **line)
{
  new->cursor = 1;
  new->next = NULL;
  new->prev = NULL;
  (*line)->head = new;
  (*line)->current = new;
  (*line)->tail = new;
}

int		add_char(char c, t_line **line)
{
  t_char	*new;

  new = my_xmalloc(sizeof(*new));
  if (new == NULL)
    return (-1);
  new->c = c;
  if ((*line)->current == NULL)
    add_newchar(new, line);
  else
    {
      new->cursor = 0;
      new->next = (*line)->current;
      new->prev = (*line)->current->prev;
      if ((*line)->current->prev != NULL)
	(*line)->current->prev->next = new;
      (*line)->current->prev = new;
      if ((*line)->current == (*line)->head)
	(*line)->head = new;
    }
  (*line)->size++;
  if ((*line)->size >= (*line)->size_max)
    (*line)->size_max = (*line)->size;
  return (0);
}
