/*
** xclose.c for xclose in /home/martel_c/rendu/Piscine-C-lib/my/
**
** Made by martelliere
** Login   <martel_c@pc-martel_c>
**
** Started on  Sun Dec  1 01:39:05 2013 martelliere
** Last update Tue May 13 17:49:14 2014 martelliere
*/

#include "parser.h"

void	xclose(int fd)
{
  if (close(fd) == -1)
    {
      printf("RT: can't close this file.\n");
      return ;
    }
}
