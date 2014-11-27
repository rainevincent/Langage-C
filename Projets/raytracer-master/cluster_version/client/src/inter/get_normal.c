/*
** get_normal.c for get_normal in /home/merran_g/work/c_igraph/raytracer/src/inter
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Mon Jun  2 16:10:25 2014 Geoffrey Merran
** Last update Sat Jun  7 22:13:58 2014 Geoffrey Merran
*/

#include "core.h"

t_vector	get_normal(t_inter inter, t_cam *eye)
{
  t_vector	n;

  if (inter.item.type == SPHERE)
    init_vec(&n, inter.p.x, inter.p.y, inter.p.z);
  if (inter.item.type == PLANE)
    init_vec(&n, 0.0, 0.0, 100.0);
  if (inter.item.type == CYLINDER)
    init_vec(&n, inter.p.x, inter.p.y, 0);
  if (inter.item.type == CONE)
    {
      n.x = inter.p.x;
      n.y = inter.p.y;
      n.z = (-(conv_radian(inter.item.rayon))) * inter.p.z;
    }
  if (inter.item.type == HYPER)
    {
      n.x = eye->pos.x / inter.item.qua.a;
      n.y = eye->pos.y / inter.item.qua.b;
      n.z = - eye->pos.z / inter.item.qua.c;
    }
  return (n);
}
