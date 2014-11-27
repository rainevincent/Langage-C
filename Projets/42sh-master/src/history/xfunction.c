/*
** xfunction.c for xfunction in /home/merran_g/work/c_elem/42sh/src/history
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu May 22 11:27:13 2014 Geoffrey Merran
** Last update Thu May 22 11:29:18 2014 Geoffrey Merran
*/

#include "history.h"

void	xclose(int fd)
{
  if (close(fd) == -1)
    {
      fprintf(stderr, "42sh: couldn't close this file.\n");
      return ;
    }
}

int	xopen(const char *path, int flags, mode_t mode)
{
  int	ret;

  if ((ret = open(path, flags, mode)) == -1)
    {
      fprintf(stderr, "42sh: %s can't be opened.\n", path);
      return (-1);
    }
  return (ret);
}

