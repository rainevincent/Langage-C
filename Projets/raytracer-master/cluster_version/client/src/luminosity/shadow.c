/*
** shadow.c for shadow in /home/merran_g/work/c_igraph/raytracer
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Jun  4 01:46:57 2014 Geoffrey Merran
** Last update Thu Jun  5 23:43:19 2014 Geoffrey Merran
*/

#include "core.h"

int		is_shadow(t_spot spot, t_inter inter, t_node *items)
{
  t_inter	inter_shadow;
  t_vector	l;
  t_cam		spot_dir;

  if (inter.k == 0)
    return (1);
  l.x = spot.pos.x - inter.p.x;
  l.y = spot.pos.y - inter.p.y;
  l.z = spot.pos.z - inter.p.z;
  spot_dir.pos.x = inter.p.x;
  spot_dir.pos.y = inter.p.y;
  spot_dir.pos.z = inter.p.z;
  spot_dir.distance = 100.0;
  init_vec(&spot_dir.angle, 0, 0, 0);
  inter_shadow = find_inter(spot_dir, l, items);
  if (inter_shadow.k < 1.0 && inter_shadow.k > 0.0001)
    return (1);
  return (0);
}
