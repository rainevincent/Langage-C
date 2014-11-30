/*
** hyperboloide.c for hyperboloide in /home/merran_g/work/c_igraph/raytracer
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sat Jun  7 21:27:44 2014 Geoffrey Merran
** Last update Sat Jun  7 21:51:09 2014 Geoffrey Merran
*/

#include "core.h"

t_rinter	inter_hyper(t_cam eye, t_vector pos_3d, t_item hyper)
{
  float		a;
  float		b;
  float		c;
  float		delta;
  t_rinter	rinter;

  get_simple_pos(&eye, hyper, &pos_3d);
  a = (pow(pos_3d.x, 2) / hyper.qua.a) + (pow(pos_3d.y, 2) / hyper.qua.b)
    - (pow(pos_3d.z, 2) / hyper.qua.c);
  b = 2 * (((eye.pos.x * pos_3d.x) / hyper.qua.a) +
	   ((eye.pos.y * pos_3d.y) / hyper.qua.b) -
	   ((eye.pos.z * pos_3d.z) / hyper.qua.c));
  c = (pow(eye.pos.x, 2) / hyper.qua.a) + (pow(eye.pos.y, 2) / hyper.qua.b)
    - (pow(eye.pos.z, 2) / hyper.qua.c) - 1;
  delta = pow(b, 2) - (4 * a * c);
  rinter.k = get_k_from_delta(delta, a, b);
  rinter.p = get_eq_param(eye.pos, rinter.k, pos_3d);
  return (rinter);
}
