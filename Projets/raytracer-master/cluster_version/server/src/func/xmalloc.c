/*
** xmalloc.c for xmalloc.c in /home/merran_g/work/c_elem/Bistro
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun Nov 10 14:28:36 2013 Geoffrey Merran
** Last update Sun Jun  8 03:09:49 2014 Joris Bertomeu
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void	*my_xmalloc(int size)
{
  void	*m;

  m = malloc(size);
  if (m == NULL)
    {
      fprintf(stderr, "malloc error couldnt alloc\n");
      exit(1);
    }
  return (m);
}
