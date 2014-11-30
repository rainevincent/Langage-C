/*
** conf.c for conf$ in /home/merran_g/work/c_elem/42sh/src/conf
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu May 15 21:05:46 2014 Geoffrey Merran
** Last update Sat May 24 21:52:18 2014 Geoffrey Merran
*/

#include "conf.h"

void	free_tab(char **t)
{
  int	i;

  if (t == NULL)
    return ;
  i = 0;
  while (t[i])
    free(t[i++]);
  free(t);
}

int	parse_conf(t_shell **shell, char **line)
{
  int	nb;

  if (strcmp(line[0], "alias") == 0)
    {
      free((*shell)->alias->path);
      (*shell)->alias->path = strdup(line[1]);
    }
  if (strcmp(line[0], "history") == 0)
    {
      free((*shell)->history->path);
      (*shell)->history->path = strdup(line[1]);
    }
  if (strcmp(line[0], "prompt") == 0)
    {
      nb = my_getnbr(line[1]);
      if (nb >= 1 && nb <= 3)
	(*shell)->prompt = nb;
    }
  return (0);
}

int	get_conf(t_shell **shell, int fd)
{
  char 	*s;
  char 	**line;

  while ((s = get_next_line(fd)) != NULL)
    {
      line = my_strd_to_wordtab(s, "=");
      if (line != NULL && my_strlen_tabs(line) == 2)
	parse_conf(shell, line);
      free_tab(line);
      free(s);
    }
  return (0);
}

int	load_conf(t_shell **shell, char *path)
{
  int	fd;

  if (access(path, F_OK) == -1)
    {
      fprintf(stderr, "42sh: conf: can't access %s\n", path);
      return (-1);
    }
  if (access(path, R_OK) == -1)
    {
      fprintf(stderr,"42sh: conf: can't read conf file. \
Check your rights.\n");
      return (-1);
    }
  if ((fd = open(path, O_RDONLY)) == -1)
    return (-1);
  return (get_conf(shell, fd));
}
