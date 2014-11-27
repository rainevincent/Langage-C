/*
** my_pixel_put_to_image.c for my_pixel_put_to_image in /home/merran_g/work/c_igraph/fdf
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Mon Dec  2 14:56:00 2013 Geoffrey Merran
** Last update Mon Dec  2 14:59:24 2013 Geoffrey Merran
*/

#include "mlx.h"
#include "my_mlx.h"

void		my_pixel_put_to_image(t_pos pixel, mlxptr m_ptr, t_img *img, int color)
{
  int		pos_addr;
  unsigned int	mlx_color;
  int		i;

  i = -1;
  mlx_color = mlx_get_color_value(m_ptr, color);
  pos_addr = pixel.x * (img->bbp / 8) + img->s_line * pixel.y;
  while (++i < (img->bbp / 8))
    img->data[pos_addr + i] = mlx_color >> i * 8;
}
