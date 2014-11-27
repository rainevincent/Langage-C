/*
** draw_rectangle.c for draw_rectangle in /home/merran_g/work/c_igraph/fdf
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun Dec  1 23:39:21 2013 Geoffrey Merran
** Last update Sun Dec  1 23:41:05 2013 Geoffrey Merran
*/

#include "my_mlx.h"
#include "mlx.h"

void	draw_rectangle(t_window win, t_pos pos_rec, t_pos size_rec, int color)
{
  t_pos	rec;

  init_pos(&rec, pos_rec.x, pos_rec.y);
  while (rec.y <= pos_rec.y + size_rec.y)
    {
      rec.x = pos_rec.x;
      while(rec.x <= pos_rec.x + size_rec.x)
	{
	  mlx_pixel_put(win.mlx_ptr, win.ptr, rec.x, rec.y, color);
	  rec.x++;
	}
      rec.y++;
    }
}
