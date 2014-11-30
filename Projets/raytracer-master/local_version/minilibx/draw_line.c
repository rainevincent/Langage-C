/*
** draw_line.c for draw_line in /home/merran_g/work/c_igraph/fdf
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun Dec  8 17:51:37 2013 Geoffrey Merran
** Last update Sun Dec  8 18:48:06 2013 Geoffrey Merran
*/

#include "mlx.h"
#include "my_mlx.h"

int	draw_cas_one(t_pos pos1, t_pos pos2, t_img *img, int color)
{
  int	x;
  int	y;
  t_pos pos_i;

  x = pos1.x;
  while (x <= pos2.x)
    {
      y = pos1.y + ((pos2.y - pos1.y) * (x - pos1.x)) / (pos2.x - pos1.x);
      init_pos(&pos_i, x, y);
      my_pixel_put_to_image(pos_i, img->mlx_ptr, img, color);
      x++;
    }
  return (1);
}

int	draw_cas_two(t_pos pos1, t_pos pos2, t_img *img, int color)
{
  int	x;
  int	y;
  t_pos	pos_i;

  x = pos1.y;
  while (x <= pos2.y)
    {
      y = pos1.x + ((pos2.x - pos1.x) * (x - pos1.y)) / (pos2.y - pos1.y);
      init_pos(&pos_i, x, y);
      my_pixel_put_to_image(pos_i, img->mlx_ptr, img, color);
      x++;
    }
  return (1);
}

int	draw_straight_x(t_pos pos1, t_pos pos2, t_img *img, int color)
{
  int	x;
  t_pos	pos_i;

  x = pos1.x;
  while (x <= pos2.x)
    {
      init_pos(&pos_i, x, pos1.y);
      my_pixel_put_to_image(pos_i, img->mlx_ptr, img, color);
      x++;
    }
  return (1);
}

int	draw_straight_y(t_pos pos1, t_pos pos2, t_img *img, int color)
{
  int	y;
  t_pos	pos_i;

  y = pos1.y;
  while (y <= pos2.y)
    {
      init_pos(&pos_i, pos1.x, y);
      my_pixel_put_to_image(pos_i, img->mlx_ptr, img, color);
      y++;
    }
  return (1);
}

void	draw_line(t_pos pos1, t_pos pos2, t_img *img, int color)
{
  if (pos1.x == pos2.x)
    draw_straight_y(pos1, pos2, img, color);
  else if (pos1.x < pos2.x)
    {
      if (pos1.y == pos2.y)
	draw_straight_x(pos1, pos2, img, color);
      else if ((pos2.x - pos1.x) >= my_abs(pos2.y - pos1.y))
      	draw_cas_one(pos1, pos2, img, color);
      else if (pos2.x < pos2.y)
      	draw_cas_two(pos1, pos2, img, color);
      else
      	draw_cas_two(pos2, pos1, img, color);
    }
  if (pos1.x > pos2.x)
    {
      if (pos1.y == pos2.y)
	draw_straight_x(pos2, pos1, img, color);
      else if ((pos1.x - pos2.x) >= my_abs(pos1.y - pos2.y))
      	draw_cas_one(pos2, pos1, img, color);
      else if (pos2.x < pos2.y)
	draw_cas_two(pos1, pos2, img, color);
      else
	draw_cas_two(pos2, pos1, img, color);
    }
}
