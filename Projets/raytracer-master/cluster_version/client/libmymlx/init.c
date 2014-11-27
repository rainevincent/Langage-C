/*
** init.c for init.c in /home/merran_g/work/c_igraph/fdf
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun Dec  1 19:23:39 2013 Geoffrey Merran
** Last update Mon May 19 23:37:50 2014 Geoffrey Merran
*/

#include "my_mlx.h"

void	init_pos(t_pos *pos, int x, int y)
{
  pos->x = x;
  pos->y = y;
}

void	init_vec(t_vector *vec, float x, float y, float z)
{
  vec->x = x;
  vec->y = y;
  vec->z = z;
}

void	init_window(mlxptr init, t_window *win, t_pos size, char *title)
{
  win->mlx_ptr = init;
  win->ptr = mlx_new_window(init, size.x, size.y, title);
  win->size = size;
}

void	init_img(t_img *i, t_window win, t_pos size)
{
  i->ptr = mlx_new_image(win.mlx_ptr, size.x, size.y);
  i->data = mlx_get_data_addr(i->ptr, &i->bbp, &i->s_line, &i->endian);
  i->size = size;
  i->mlx_ptr = win.mlx_ptr;
}

void	init_screen(t_screen *s, t_window win, t_img img)
{
  s->win = win;
  s->img = img;
}
