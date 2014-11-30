/*
** line_editor.c for main in /home/merran_g/work/c_elem/42sh/src/line_editor
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed May 14 15:13:23 2014 Geoffrey Merran
** Last update Wed May 28 00:54:33 2014 Geoffrey Merran
*/

#define _BSD_SOURCE
#include "line_editor.h"

int	init_term(struct termios *t, struct termios *t_save)
{
  if (xtcgetattr(0, t) == -1)
    return (-1);
  if (xtcgetattr(0, t_save) == -1)
    return (-1);
  if (raw_mode(t) == -1)
    return (-1);
  if (hide_char(t) == -1)
    return (-1);
  if (xtcsetattr(0, 0, t) == -1)
    return (-1);
  if (change_cursor(0) == -1)
    return (-1);
  return (0);
}

char	*reset_term(char *cmd, struct termios *t_save, t_shell *shell)
{
  shell->history->current = NULL;
  if (xtcsetattr(0, 0, t_save) == -1)
    return (NULL);
  if (change_cursor(1) == -1)
    return (NULL);
  return (cmd);
}

int	init_line_editor(struct termios *t, struct termios *t_save, t_line **line)
{
  char	*pos;

  if (init_term(t, t_save) == -1)
    return (-1);
  if ((pos = xtgetstr("sc", NULL)) == NULL)
    return (-1);
  my_putstr(pos);
  if (new_line_edit(line) == -1)
    return (-1);
  if (((*line)->save = xtgetstr("rc", NULL)) == NULL)
    return (-1);
  if (add_char('\0', line) == -1)
    return (-1);
  return (0);
}

int		show_edit_line(t_line *line)
{
  t_char	*tmp;
  int		i;

  my_printf("%s%s", line->save, PROMPT);
  tmp = line->head;
  i = 0;
  while (tmp)
    {
      if (write_prompt_char(tmp) == -1)
	return (-1);
      tmp = tmp->next;
      i++;
    }
  i--;
  while (++i < line->size_max)
    my_putchar(' ');
  return (0);
}

char			*line_editor(t_shell *shell)
{
  char			buffer[BUFFER_SIZE];
  t_line		*line;
  struct termios	t;
  struct termios	t_save;

  if (init_line_editor(&t, &t_save, &line) == -1)
    return (NULL);
  bzero(buffer, BUFFER_SIZE);
  while (buffer[0] != '\n' && buffer[0] != 4)
    {
      bzero(buffer, BUFFER_SIZE);
      if (show_edit_line(line) == -1)
	return (NULL);
      if (read(0, buffer, BUFFER_SIZE - 1) <= 0)
	return (NULL);
      if (parser_line_editor(buffer, &line, shell) == -1)
	return (NULL);
    }
  return (reset_term(build_line(line), &t_save, shell));
}
