/*
** get_simple_pos.c for get_pos_simple in /home/merran_g/work/c_igraph/rtv1
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sat Mar 15 21:01:53 2014 Geoffrey Merran
** Last update Mon Jun  2 15:47:30 2014 Geoffrey Merran
*/

#include "core.h"

void	translate(t_vector *eye, t_vector item)
{
  eye->x = eye->x - item.x;
  eye->y = eye->y - item.y;
  eye->z = eye->z - item.z;
}

void		rotate_x(t_vector *eye, float angle)
{
  t_vector	tmp;

  if (angle >= 0.0001 || angle <= 0.0001)
    {
      angle = conv_radian(angle);
      tmp.x = eye->x;
      tmp.y = (eye->y * cos(angle)) - (eye->z * sin(angle));
      tmp.z = (eye->y * sin(angle)) + (eye->z * cos(angle));
      eye->x = tmp.x;
      eye->y = tmp.y;
      eye->z = tmp.z;
    }
}

void		rotate_y(t_vector *eye, float angle)
{
  t_vector	tmp;

  if (angle >= 0.0001 || angle <= 0.0001)
    {
      angle = conv_radian(angle);
      tmp.x = (eye->z * sin(angle)) + (eye->x * cos(angle));
      tmp.y = eye->y;
      tmp.z = (eye->z * cos(angle)) - (eye->x * sin(angle));
      eye->x = tmp.x;
      eye->y = tmp.y;
      eye->z = tmp.z;
    }
}

void		rotate_z(t_vector *eye, float angle)
{
  t_vector	tmp;

  if (angle >= 0.0001 || angle <= 0.0001)
    {
      angle = conv_radian(angle);
      tmp.x = (eye->x * cos(angle)) - (eye->y * sin(angle));
      tmp.y = (eye->x * sin(angle)) + (eye->y * cos(angle));
      tmp.z = eye->z;
      eye->x = tmp.x;
      eye->y = tmp.y;
      eye->z = tmp.z;
    }
}

void	get_simple_pos(t_cam *eye, t_item item, t_vector *pos_3d)
{
  translate(&eye->pos, item.pos);
  rotate_all(pos_3d, item.angle);
  rotate_all(&eye->pos, item.angle);
}
