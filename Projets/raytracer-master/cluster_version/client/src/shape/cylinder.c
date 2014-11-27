/*
** cylinder.c for cylinder in /home/merran_g/work/c_igraph/rtv1
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun Mar 16 05:15:07 2014 Geoffrey Merran
** Last update Mon May 19 23:22:59 2014 Geoffrey Merran
*/

#include "core.h"

t_rinter	inter_cylinder(t_cam eye, t_vector pos_3d, t_item cylinder)
{
  float		a;
  float		b;
  float		c;
  float		delta;
  t_rinter	rinter;

  get_simple_pos(&eye, cylinder, &pos_3d);
  a = pow(pos_3d.x, 2) + pow(pos_3d.y, 2);
  b = 2.000 * ((eye.pos.x * pos_3d.x) + (eye.pos.y * pos_3d.y));
  c = pow(eye.pos.x, 2) + pow(eye.pos.y, 2) - pow(cylinder.rayon, 2);
  delta = pow(b, 2) - (4 * a * c);
  rinter.k = get_k_from_delta(delta, a, b);
  rinter.p = get_eq_param(eye.pos, rinter.k, pos_3d);
  return (rinter);
}
