/*
** calc_img.c for calc_img in /home/merran_g/work/c_igraph/raytracer
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu Jun  5 23:49:52 2014 Geoffrey Merran
** Last update Sun Jun  8 17:27:32 2014 Geoffrey Merran
*/

#include "core.h"

int		get_nb_spots(t_spot *spots)
{
  t_spot	*tmp;
  int		i;

  i = 0;
  tmp = spots;
  while (tmp)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

t_rgb		put_spots(t_inter inter, t_scene *scene)
{
  float		nb_spots;
  t_spot	*tmp;
  t_rgb 	color;
  t_rgb		save;

  nb_spots = (float) get_nb_spots(scene->spots);
  tmp = scene->spots;
  init_rgb(&color, 0, 0, 0);
  while (tmp)
    {
      if (is_shadow(*tmp, inter, scene->items))
      	init_rgb(&save, 0, 0, 0);
      else
        save = luminosity(*tmp, inter);
      color.r = color.r + save.r;
      color.g = color.g + save.g;
      color.b = color.b + save.b;
      tmp = tmp->next;
    }
  color.r = color.r / nb_spots;
  color.g = color.g / nb_spots;
  color.b = color.b / nb_spots;
  return (color);
}

t_inter		get_pixel_color(t_vector pos_3d, t_scene *scene)
{
  t_inter      	inter;

  inter = find_inter(*scene->eye, pos_3d, scene->items);
  if (inter.k == 0)
    return (inter);
  inter.p = get_eq_param(scene->eye->pos, inter.k, pos_3d);
  inter.n = get_normal(inter, scene->eye);
  apply_pertubation(&inter);
  rotate_all(&inter.n, inter.item.angle);
  inter.rgb = put_spots(inter, scene);
  return (inter);
}

void		apply_coeff(t_rgb *color, t_rgb save, float coeff)
{
  (*color).r = (save.r * coeff) +
    ((*color).r * (1.0 - coeff));
  (*color).g = (save.g * coeff) +
    ((*color).g * (1.0 - coeff));
  (*color).b = (save.b * coeff) +
    ((*color).b * (1.0 - coeff));
}

unsigned int   	calc_image(t_pos pos, t_scene *scene)
{
  t_vector	pos_3d;
  t_inter 	inter;
  t_rgb		color;
  t_rgb		save;

  pos_3d.x = scene->eye->distance;
  pos_3d.y = (WIN_X / 2.000) - (float) pos.x;
  pos_3d.z = (WIN_Y / 2.000) - (float) pos.y;
  inter = get_pixel_color(pos_3d, scene);
  color = inter.rgb;
  if (inter.k == 0)
    return (change_rgb(0, 0, 0));
  save = put_reflexion(inter, scene, pos_3d);
  apply_coeff(&color, save, inter.item.reflexion);
  save = put_transparence(inter, scene, pos_3d);
  apply_coeff(&color, save, inter.item.reflexion);
  return (change_rgb(color.r, color.g, color.b));
}
