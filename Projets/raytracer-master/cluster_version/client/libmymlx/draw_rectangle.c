/*
** draw_rectangle.c for draw_rectangle in /home/merran_g/work/c_igraph/fdf
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun Dec  1 23:39:21 2013 Geoffrey Merran
** Last update Mon May 19 23:37:30 2014 Geoffrey Merran
*/

#include "my_mlx.h"

void	draw_rectangle(t_img *img, t_pos pos_rec, t_pos size_rec, int color)
{
  t_pos	rec;

  init_pos(&rec, pos_rec.x, pos_rec.y);
  while (rec.y <= pos_rec.y + size_rec.y)
    {
      rec.x = pos_rec.x;
      while (rec.x <= pos_rec.x + size_rec.x)
	{
	  my_pixel_put_to_image(rec, img->mlx_ptr, img, color);
	  rec.x++;
	}
      rec.y++;
    }
}
