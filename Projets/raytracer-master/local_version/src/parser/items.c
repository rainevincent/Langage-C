/*
** items.c for items in /home/merran_g/work/c_igraph/rtv1
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun Mar 16 01:54:50 2014 Geoffrey Merran
** Last update Sun Jun  8 20:29:50 2014 Geoffrey Merran
*/

#include "parser.h"

void		add_item(t_node **list, t_item new)
{
  t_node	*tmp;

  tmp = my_xmalloc(sizeof(*tmp));
  tmp->item.pos = new.pos;
  tmp->item.angle = new.angle;
  tmp->item.qua = new.qua;
  tmp->item.type = new.type;
  tmp->item.rayon = new.rayon;
  tmp->item.color = new.color;
  tmp->item.transparence = new.transparence;
  tmp->item.brillance = new.brillance;
  tmp->item.reflexion = new.reflexion;
  tmp->item.effect = new.effect;
  tmp->next = *list;
  *list = tmp;
}

void	init_item(t_item *new, t_vector pos, t_vector angle, t_type type)
{
  new->pos = pos;
  new->angle = angle;
  new->type = type;
}

void	init_item2(t_item *new, float rayon, t_rgb color, float brillance, float reflexion)
{
  new->rayon = rayon;
  new->color = color;
  new->brillance = brillance;
  new->reflexion = reflexion;
}

void	init_rgb(t_rgb *color, int r, int g, int b)
{
  color->r = r;
  color->g = g;
  color->b = b;
}

void		add_spot(t_spot **spots, t_vector pos, t_rgb color)
{
  t_spot	*new;

  new = my_xmalloc(sizeof(*new));
  new->pos = pos;
  new->color = color;
  new->next = *spots;
  *spots = new;
}

t_spot		*get_spots()
{
  t_spot	*spots;
  t_vector	n_pos;
  t_rgb		n_color;

  spots = NULL;
  /* init_vec(&n_pos, -220, -150, 0); */
  /* init_rgb(&n_color, 255, 255, 255); */
  /* add_spot(&spots, n_pos, n_color); */
  init_vec(&n_pos, -560, 0, 60);
  init_rgb(&n_color, 255, 255, 255);
  add_spot(&spots, n_pos, n_color);
  init_vec(&n_pos, -600, 0, 0);
  init_rgb(&n_color, 255, 255, 255);
  add_spot(&spots, n_pos, n_color);
  /* init_vec(&n_pos, 0, 0, 190); */
  /* init_rgb(&n_color, 142, 4, 2); */
  /* add_spot(&spots, n_pos, n_color); */
  /* init_vec(&n_pos, 300, -150, 0); */
  /* init_rgb(&n_color, 255, 255, 255); */
  /* add_spot(&spots, n_pos, n_color); */
  return (spots);
}

t_node		*get_items()
{
  t_node	*items;
  t_vector	n_pos;
  t_vector	n_angle;
  t_rgb		n_color;
  t_item	new;

  items = NULL;
  new.qua.a = 0;
  new.qua.b = 0;
  new.qua.c = 0;
  new.effect = NONE;
  new.transparence = 0;
  /* init_vec(&n_pos, -500, 0, -100); */
  /* init_vec(&n_angle, 0, 0, 0); */
  /* init_rgb(&n_color, 48, 223, 0); */
  /* init_item(&new, n_pos, n_angle, SPHERE); */
  /* init_item2(&new, 50.0, n_color, 0, 0); */
  /* add_item(&items, new); */
  new.effect = DAMIER;
  init_vec(&n_pos, 0, 0, -200);
  init_vec(&n_angle, 0, 0, 0);
  init_rgb(&n_color, 200, 181, 119);
  init_item(&new, n_pos, n_angle, PLANE);
  init_item2(&new, 0, n_color, 0.5, 0);
  add_item(&items, new);
  new.effect = NONE;
  init_vec(&n_pos, -210, 0, 0);
  init_vec(&n_angle, 0, -90, 0);
  init_rgb(&n_color, 200, 181, 119);
  init_item(&new, n_pos, n_angle, PLANE);
  init_item2(&new, 0, n_color, 0.5, 0);
  add_item(&items, new);
  init_vec(&n_pos, 0, 0, 200);
  init_vec(&n_angle, 180, 0, 0);
  init_rgb(&n_color, 150, 131, 69);
  init_item(&new, n_pos, n_angle, PLANE);
  init_item2(&new, 0, n_color, 0.5, 0);
  add_item(&items, new);
  init_vec(&n_pos, 0, 200, 0);
  init_vec(&n_angle, 90, 0, 0);
  init_rgb(&n_color, 111, 130, 23);
  init_item(&new, n_pos, n_angle, PLANE);
  init_item2(&new, 0, n_color, 0.5, 0.2);
  add_item(&items, new);
  init_vec(&n_pos, 0, -200, 0);
  init_vec(&n_angle, -90, 0, 0);
  init_rgb(&n_color, 72, 4, 1);
  init_item(&new, n_pos, n_angle, PLANE);
  init_item2(&new, 0, n_color, 0.5, 0.2);
  add_item(&items, new);
  /* new.effect = NONE; */
  /* new.transparence = 0; */
  init_vec(&n_pos, -500, 0, 0);
  init_vec(&n_angle, 0, 0, 0);
  init_rgb(&n_color, 208, 130, 45);
  init_item(&new, n_pos, n_angle, SPHERE);
  init_item2(&new, 50.0, n_color, 0.6, 0.5);
  add_item(&items, new);
  return (items);
}
