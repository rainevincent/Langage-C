/*
** luminosity.c for luminosity in /home/merran_g/work/c_igraph/rtv1
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun Mar 16 23:18:21 2014 Geoffrey Merran
** Last update Sun Jun  8 07:54:10 2014 Geoffrey Merran
*/

#define _BSD_SOURCE
#include "core.h"

void		get_correct_color(int *c)
{
  if (*c < 0)
    *c = 0;
  if (*c > 255)
    *c = 255;
}

void		get_lumi_color(t_inter *inter, float cos_a, t_spot spot)
{
  inter->rgb.r = ((float) inter->item.color.r * cos_a) *
    ((float) spot.color.r / 255.0);
  inter->rgb.g = ((float) inter->item.color.g * cos_a) *
    ((float) spot.color.g / 255.0);
  inter->rgb.b = ((float) inter->item.color.b * cos_a) *
    ((float) spot.color.b / 255.0);
  inter->rgb.r = ((float) inter->rgb.r +
		  (inter->item.brillance * (float) spot.color.r * cos_a));
  inter->rgb.g = ((float) inter->rgb.g +
		  (inter->item.brillance * (float) spot.color.g * cos_a));
  inter->rgb.b = ((float) inter->rgb.b +
		  (inter->item.brillance * (float) spot.color.b * cos_a));
  get_correct_color(&inter->rgb.r);
  get_correct_color(&inter->rgb.g);
  get_correct_color(&inter->rgb.b);
}

void		apply_damier(t_inter *inter)
{
  float		x;
  float		y;

  x = inter->p.x;
  y = inter->p.y;
  if (inter->p.x < 0)
    x -= 50;
  if (inter->p.y < 0)
    y -= 50;
  if ((my_abs((int) x % 100) >= 50) &&
      (my_abs((int) y % 100) >= 50))
    {
      inter->item.color.r = 0;
      inter->item.color.g = 0;
      inter->item.color.b = 0;
      	}
  if ((my_abs((int) x % 100) < 50) &&
	  (my_abs((int) y % 100) < 50))
    {
      inter->item.color.r = 0;
      inter->item.color.g = 0;
      	  inter->item.color.b = 0;
    }
}

void		apply_pertubation(t_inter *inter)
{
  float		n;

  if (inter->item.effect == DAMIER)
    apply_damier(inter);
  if (inter->item.effect == VAGUE)
    {
      n = sqrtf(pow(inter->n.x, 2) + pow(inter->n.y, 2) +
		pow(inter->n.z, 2));
      inter->n.y = inter->n.y + (cos(inter->p.y / 10.0) * (n / 10.0));
    }
}

t_rgb		luminosity(t_spot spot, t_inter inter)
{
  t_vector	l;
  float		cos_a;

  l.x = spot.pos.x - inter.p.x;
  l.y = spot.pos.y - inter.p.y;
  l.z = spot.pos.z - inter.p.z;
  normalize_vec(&l);
  normalize_vec(&inter.n);
  cos_a = ((inter.n.x * l.x) + (inter.n.y * l.y)
  	   + (inter.n.z * l.z));
  if (cos_a < 0.00001)
    cos_a = 0;
  get_lumi_color(&inter, cos_a, spot);
  return (inter.rgb);
}

