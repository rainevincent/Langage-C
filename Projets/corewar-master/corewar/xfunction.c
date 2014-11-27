/*
** xfunction.c for xfunction in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Mar 26 13:21:27 2014 Geoffrey Merran
** Last update Mon Mar 31 19:17:55 2014 Geoffrey Merran
*/

#include "xfunction.h"

int	xopen(char *pathname, int flags, mode_t mode)
{
  int	a;

  if ((a = open(pathname, flags, mode)) == -1)
    my_error("Open error : file not found\n");
  return (a);
}

int	xread(int fd, void *buf, size_t count)
{
  int	n;

  n = read(fd, buf, count);
  if (n == -1)
    my_error("Read error\n");
  return (n);
}

void	my_error(char *str)
{
  my_puterr(str);
  exit(EXIT_FAILURE);
}
