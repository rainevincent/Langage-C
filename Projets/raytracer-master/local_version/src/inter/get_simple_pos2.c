/*
** get_simple_pos2.c for get_simple_pos in /home/merran_g/work/c_igraph/rtv1
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun Mar 16 19:39:44 2014 Geoffrey Merran
** Last update Mon May 19 23:21:08 2014 Geoffrey Merran
*/

#include "core.h"

void	rotate_all(t_vector *pos, t_vector angle)
{
  rotate_x(pos, angle.x);
  rotate_y(pos, angle.y);
  rotate_z(pos, angle.z);
}
