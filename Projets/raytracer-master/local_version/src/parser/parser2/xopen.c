/*
** xopen.c for xopen in /home/martel_c/rendu/Piscine-C-lib/my/
**
** Made by martelliere
** Login   <martel_c@pc-martel_c>
**
** Started on  Wed Dec  5 04:36:08 2012 martelliere
** Last update Fri May 30 09:54:41 2014 martelliere
*/

#include "parser.h"

int	xopen(const char *path, int flags, mode_t mode)
{
  int	ret;

  if ((ret = open(path, flags, mode)) == -1)
    {
      printf("RT: %s can't be opened.\n", path);
      exit(EXIT_FAILURE);
    }
  return (ret);
}
