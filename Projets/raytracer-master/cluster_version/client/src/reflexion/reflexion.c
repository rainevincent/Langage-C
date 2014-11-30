/*
** reflexion.c for reflexion in /home/merran_g/work/c_igraph/raytracer
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri Jun  6 03:23:23 2014 Geoffrey Merran
** Last update Sun Jun  8 17:37:15 2014 Geoffrey Merran
*/

#define _BSD_SOURCE
#include "core.h"

float		get_scalaire(t_vector v, t_vector w)
{
  return (v.x * w.x + v.y * w.y + v.z * w.z);
}

t_rgb		put_transparence(t_inter inter, t_scene *scene, t_vector pos_3d)
{
  t_cam		save;
  t_vector	t;
  t_inter      	color;
  float		scal;
  float		n;

  save.pos = scene->eye->pos;
  save.angle = scene->eye->pos;
  init_vec(&scene->eye->pos, inter.p.x, inter.p.y, inter.p.z);
  init_vec(&scene->eye->angle, 0, 0, 0);
  init_rgb(&color.rgb, 0, 0, 0);
  normalize_vec(&inter.n);
  normalize_vec(&pos_3d);
  n = 0.9;
  scal = get_scalaire(inter.n, pos_3d);
  scal = n * scal - sqrtf(1 + pow(n, 2) * (pow(scal, 2) - 1));
  t.x = n * pos_3d.x + scal * inter.n.x;
  t.y = n * pos_3d.y + scal * inter.n.y;
  t.z = n * pos_3d.z + scal * inter.n.z;
  color = get_pixel_color(t, scene);
  scene->eye->pos = save.pos;
  scene->eye->pos = save.angle;
  return (color.rgb);
}

t_rgb		put_reflexion(t_inter inter, t_scene *scene, t_vector pos_3d)
{
  t_cam		save;
  t_vector	r;
  t_inter      	color;
  float		scal;

  save.pos = scene->eye->pos;
  save.angle = scene->eye->pos;
  init_vec(&scene->eye->pos, inter.p.x, inter.p.y, inter.p.z);
  init_vec(&scene->eye->angle, 0, 0, 0);
  init_rgb(&color.rgb, 0, 0, 0);
  normalize_vec(&inter.n);
  normalize_vec(&pos_3d);
  scal = get_scalaire(inter.n, pos_3d);
  r.x = ((-2.0 * inter.n.x) * scal) + pos_3d.x;
  r.y = ((-2.0 * inter.n.y) * scal) + pos_3d.y;
  r.z = ((-2.0 * inter.n.z) * scal) + pos_3d.z;
  color = get_pixel_color(r, scene);
  scene->eye->pos = save.pos;
  scene->eye->pos = save.angle;
  return (color.rgb);
}
