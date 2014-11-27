/*
** gnl.c for GNL in /home/jobertomeu/Work/corewar/assembleur
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sat Apr 12 15:07:49 2014 Joris Bertomeu
** Last update Sun Apr 13 14:13:27 2014 Joris Bertomeu
*/

#include "gnl.h"
#include "assembleur.h"

static int    stock_buffer(t_var *var, char *tmp, int *save, t_system *sys)
{
  while (var->i < BUF_READ)
    {
      if (tmp[*save] == '\0')
	{
	  sys->ret_gnl[var->i] = '\0';
	  *save = 0;
	  if (var->nb_read < BUF_SIZE)
	    return (1);
	  return (0);
	}
      if (tmp[*save] == '\n')
	{
          sys->ret_gnl[var->i] = '\0';
	  if (*save + 1 >= var->nb_read)
	    *save = 0;
	  else
	    (*save)++;
          return (1);
	}
      sys->ret_gnl[var->i++] = tmp[(*save)++];
    }
  sys->ret_gnl[var->i] = '\0';
  return (1);
}

char		*get_next_line(const int fd, t_system *sys)
{
  static int	save = 0;
  static char   buff_temp[BUF_SIZE + 1];
  static int    nb_read;
  t_var		var;

  var.i = 0;
  my_memset(sys->ret_gnl, '\0', 4096);
  while (var.i < BUF_READ)
    {
      if (save == 0)
	if ((nb_read = read(fd, buff_temp, BUF_SIZE)) <= 0)
	  return (0);
      var.nb_read = nb_read;
      if (stock_buffer(&var, buff_temp, &save, sys))
	return (sys->ret_gnl);
    }
  return (sys->ret_gnl);
}
