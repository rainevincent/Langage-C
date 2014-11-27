/*
** xfunction.c for xfunction in /home/merran_g/work/c_igraph/wolf3d
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri Jan 10 23:59:39 2014 Geoffrey Merran
** Last update Mon May 19 23:28:02 2014 Geoffrey Merran
*/

#include "core.h"

mlxptr		xmlx_init()
{
  mlxptr	init;

  init = mlx_init();
  if (init == NULL)
    {
      my_printf("mlx_init error. Hint : Check if your env is not NULL\n");
      exit(1);
    }
  return (init);
}
