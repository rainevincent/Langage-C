/*
** plan.c for plan in /home/merran_g/work/c_igraph/rtv1
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun Mar 16 03:51:59 2014 Geoffrey Merran
** Last update Mon May 19 23:23:05 2014 Geoffrey Merran
*/

#include "core.h"

t_rinter	inter_plan(t_cam eye, t_vector pos_3d, t_item plan)
{
  t_rinter	rinter;

  get_simple_pos(&eye, plan, &pos_3d);
  rinter.k = 0;
  if (pos_3d.z <= 0.00001 && pos_3d.z >= -0.00001)
    return (rinter);
  rinter.k = (eye.pos.z / pos_3d.z) * -1.0f;
  rinter.p = get_eq_param(eye.pos, rinter.k, pos_3d);
  if (rinter.k < 0.00001)
    {
      rinter.k = 0;
      return (rinter);
    }
  return (rinter);
}
