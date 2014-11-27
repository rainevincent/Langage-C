/*
** init.c for Parser RT in /home/martel_c/rendu/RT/parser
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Mon Jun  2 14:35:58 2014 martelliere
** Last update Mon Jun  2 14:37:22 2014 martelliere
*/

#include "parser.h"

t_scene         *init_scene(t_scene *scene)
{
  scene = NULL;
  scene = my_xmalloc(sizeof(t_scene));
  scene->eye = NULL;
  scene->eye = my_xmalloc(sizeof(t_cam));
  scene->spots = NULL;
  scene->spots = my_xmalloc(sizeof(t_spot));
  scene->items = NULL;
  scene->items = my_xmalloc(sizeof(t_node));
  return (scene);
}

void            init_vec(t_vector *vec, float x, float y, float z)
{
  vec->x = x;
  vec->y = y;
  vec->z = z;
}

void            add_item(t_node **list, t_item new)
{
  t_node        *tmp;

  tmp = my_xmalloc(sizeof(*tmp));
  tmp->item.pos = new.pos;
  tmp->item.angle = new.angle;
  tmp->item.type = new.type;
  tmp->item.rayon = new.rayon;
  tmp->item.color = new.color;
  tmp->next = *list;
  *list = tmp;
}

void    init_item(t_item *new, t_vector pos, t_vector angle, t_type type)
{
  new->pos = pos;
  new->angle = angle;
  new->type = type;
}

void    init_item2(t_item *new, float rayon, t_rgb color)
{
  new->rayon = rayon;
  new->color = color;
}
