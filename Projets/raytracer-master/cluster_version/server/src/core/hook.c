/*
** hook.c for hook in /home/merran_g/work/c_igraph/rtv1
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sat Mar 15 20:44:15 2014 Geoffrey Merran
** Last update Mon May 19 23:20:40 2014 Geoffrey Merran
*/

#include "core.h"

int	expose_hook(t_screen *params)
{
  mlx_put_image_to_window(params->win.mlx_ptr,
			  params->win.ptr, params->img.ptr, 0, 0);
  my_putstr("Event : Expose\n");
  return (1);
}

int	key_hook(int keycode, t_screen *params)
{
  if (keycode == ESCAPE)
    {
      mlx_destroy_window(params->win.mlx_ptr, params->win.ptr);
      exit(1);
    }
  return (1);
}
