/*
** term_fct.c<2> for term_fct in /home/merran_g/work/c_elem/42sh/src/line_editor
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed May 14 15:17:16 2014 Geoffrey Merran
** Last update Sun May 25 05:39:39 2014 Geoffrey Merran
*/

#include "line_editor.h"

int	raw_mode(struct termios *t)
{
  t->c_lflag &= ~ICANON;
  t->c_cc[VMIN] = 1;
  t->c_cc[VTIME] = 0;
  return (xtcsetattr(0, 0, t));
}

int	hide_char(struct termios *t)
{
  t->c_lflag &= ~ECHO;
  return (xtcsetattr(0, 0, t));
}

int    	change_cursor(int visibility)
{
  char 	*cursor;

  if (visibility == 1)
    cursor = xtgetstr("ve", NULL);
  else
    cursor = xtgetstr("vi", NULL);
  if (cursor == NULL)
    return (my_error("Change cursor visibility error\n"));
  my_putstr(cursor);
  return (0);
}

int	clear_term()
{
  char	*clear;

  clear = xtgetstr("cl", NULL);
  if (clear == NULL)
    return (-1);
  my_putstr(clear);
  return (0);
}
