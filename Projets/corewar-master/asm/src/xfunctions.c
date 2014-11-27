/*
** xfunctions.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sat Apr 12 18:19:19 2014 Jeremy Mediavilla
** Last update Sat Apr 12 19:36:45 2014 Joris Bertomeu
*/

#include "gnl.h"
#include "assembleur.h"

void		*xmalloc(size_t size)
{
  void		*tmp;

  if ((tmp = malloc(size)) == NULL)
    {
      my_putstr("Malloc error\n");
      exit(0);
    }
  return (tmp);
}

int		xopen(const char *pathname, int flags)
{
  int		fd;

  if ((fd = open(pathname, flags)) == -1)
    {
      my_putstr("Open error\n");
      exit(0);
    }
  return (fd);
}

ssize_t		xwrite(int fd, const void *buf, size_t count)
{
  ssize_t	tmp;

  if ((tmp = write(fd, buf, count)) == -1)
    {
      my_putstr("Write error\n");
      exit(0);
    }
  return (tmp);
}
