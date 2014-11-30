/*
** cone.c for cone in /home/merran_g/work/c_igraph/rtv1
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun Mar 16 05:44:34 2014 Geoffrey Merran
** Last update Thu Jun  5 21:42:03 2014 Geoffrey Merran
*/

#include "core.h"

t_rinter	inter_cone(t_cam eye, t_vector pos_3d, t_item cone)
{
  float		a;
  float		b;
  float		c;
  float		r;
  float		delta;
  t_rinter	rinter;

  get_simple_pos(&eye, cone, &pos_3d);
  r = conv_radian(cone.rayon);
  a = pow(pos_3d.x, 2)
    + pow(pos_3d.y, 2)
    - (pow(pos_3d.z, 2) * (pow(tan(r), 2)));
  b = (2.0 * (eye.pos.x * pos_3d.x))
    + (2.0 * (eye.pos.y * pos_3d.y))
    - (2.0 * ((eye.pos.z * pos_3d.z) * (pow(tan(r), 2))));
  c = pow(eye.pos.x, 2)
    + pow(eye.pos.y, 2)
    - (pow(eye.pos.z, 2) * pow(tan(r), 2));
  delta = pow(b, 2) - ((float) 4.0 * a * c);
  rinter.k = get_k_from_delta(delta, a, b);
  rinter.p = get_eq_param(eye.pos, rinter.k, pos_3d);
  return (rinter);
}
