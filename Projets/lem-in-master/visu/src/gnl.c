/*
** gnl.c for gnl in /home/jobertomeu/Work/lemin/visu
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Mon Apr 21 19:12:30 2014 Joris Bertomeu
** Last update Sun May  4 20:02:44 2014 Joris Bertomeu
*/

#include "visu.h"
#include "gnl.h"

void	*xmalloc(int sz)
{
  void		*p;

  if (!(p = malloc(sz)))
    exit(0);
  return (p);
}

static int    stock_buffer(t_var *var, char *tmp, int *save)
{
  while (var->i < BUF_READ)
    {
      if (tmp[*save] == '\0')
	{
	  var->buffer[var->i] = '\0';
	  *save = 0;
	  if (var->nb_read < BUF_SIZE)
	    return (1);
	  return (0);
	}
      if (tmp[*save] == '\n')
	{
          var->buffer[var->i] = '\0';
	  if (*save + 1 >= var->nb_read)
	    *save = 0;
	  else
	    (*save)++;
          return (1);
	}
      var->buffer[var->i++] = tmp[(*save)++];
    }
  var->buffer[var->i] = '\0';
  return (1);
}

char		*get_next_line(const int fd)
{
  static int	save = 0;
  static char   buff_temp[BUF_SIZE + 1];
  static int    nb_read;
  t_var		var;

  var.i = 0;
  var.buffer = xmalloc(BUF_READ + 1);
  memset(var.buffer, 0, BUF_READ + 1);
  while (var.i < BUF_READ)
    {
      if (save == 0)
	if ((nb_read = read(fd, buff_temp, BUF_SIZE)) <= 0)
	  return (0);
      var.nb_read = nb_read;
      if (stock_buffer(&var, buff_temp, &save))
	return (var.buffer);
    }
  return (var.buffer);
}
