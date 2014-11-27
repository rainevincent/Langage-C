/*
** build_line.c for build_line in /home/merran_g/work/c_elem/42sh/src/line_editor
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu May 15 19:46:48 2014 Geoffrey Merran
** Last update Sun May 25 05:12:18 2014 Geoffrey Merran
*/

#include "line_editor.h"

int		new_line_edit(t_line **line)
{
  if ((*line = my_xmalloc(sizeof(**line))) == NULL)
    return (-1);
  (*line)->head = NULL;
  (*line)->current = NULL;
  (*line)->tail = NULL;
  (*line)->size = 0;
  (*line)->size_max = 0;
  return (0);
}

void		delete_line_edit(t_line *line)
{
  t_char	*tmp;
  int		i;

  i = 0;
  line->size_max = line->size;
  while (line->head && line->head->c != '\0')
    {
      tmp = line->head->next;
      free(line->head);
      line->head = tmp;
      i++;
    }
  line->size = 1;
  if (line->head != NULL)
    {
      line->current = line->head;
      line->current->prev = NULL;
      line->tail = line->current;
      line->current->cursor = 1;
    }
}

char		*build_line(t_line *line)
{
  char		*cmd;
  t_char	*tmp2;
  t_char	*tmp;
  int		i;

  cmd = my_xmalloc(line->size * sizeof(char));
  if (cmd == NULL)
    return (NULL);
  i = 0;
  tmp = line->head;
  while (tmp)
    {
      tmp2 = tmp->next;
      cmd[i++] = tmp->c;
      free(tmp);
      tmp = tmp2;
    }
  if (cmd != NULL)
    my_printf("%s%s%s \n", line->save, PROMPT, cmd);
  free(line);
  return (cmd);
}
