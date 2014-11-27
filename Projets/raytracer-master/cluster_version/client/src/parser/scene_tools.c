/*
** scene_tools.c for  in /home/mediav_j/mabm/raytracer/merge/client/src/parser/mediav_parser
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sun Jun  8 10:05:27 2014 Jeremy Mediavilla
** Last update Sun Jun  8 12:32:36 2014 Jeremy Mediavilla
*/

#include "core.h"

void		reset_item(t_parser *parser)
{
  init_vec(&parser->tmp.pos, 0, 0, 0);
  init_vec(&parser->tmp.angle, 0, 0, 0);
  init_rgb(&parser->tmp.color, 0, 0, 0);
  parser->tmp.qua.a = 0;
  parser->tmp.qua.b = 0;
  parser->tmp.qua.c = 0;
  parser->tmp.type = -1;
  parser->tmp.rayon = 0;
  parser->tmp.brillance = 0;
  parser->tmp.reflexion = 0;
  parser->tmp.transparence = 0;
}

void		init_scene(t_scene **scene)
{
  *scene = my_xmalloc(sizeof(**scene));
  (*scene)->items = NULL;
  (*scene)->spots = NULL;
  (*scene)->eye = my_xmalloc(sizeof(*((*scene)->eye)));
  init_vec(&(*scene)->eye->pos, 0, 0, 0);
  init_vec(&(*scene)->eye->angle, 0, 0, 0);
  (*scene)->eye->distance = 100;
}

void		print_items(t_node *tmp)
{
  printf("Item :\n x: %f y: %f z: %f\n", 
	 tmp->item.pos.x, tmp->item.pos.y, tmp->item.pos.z);
  printf("Type : %d", tmp->item.type);
  printf("Pos :\n x: %f y: %f z: %f\n", 
	 tmp->item.angle.x, tmp->item.angle.y, tmp->item.angle.z);
  printf("r: %d g: %d b: %d\n", 
	 tmp->item.color.r, tmp->item.color.g, tmp->item.color.b);
  printf("Effects : brill %f trans %f reflex %f size %f\n", 
	 tmp->item.brillance, tmp->item.transparence,
	 tmp->item.reflexion, tmp->item.rayon);
  printf("Effect : %d\n", tmp->item.effect);
}

void		aff_the_scene(t_scene *scene)
{
  t_node	*tmp;
  t_spot	*tmpl;

  printf("Eye :\nx: %f y: %f z: %f\n",
	 scene->eye->pos.x, scene->eye->pos.y, scene->eye->pos.z);
  printf("Eye :\nx: %f y: %f z: %f\n",
	 scene->eye->angle.x, scene->eye->angle.y, scene->eye->angle.z);
  tmpl = scene->spots;
  while (tmpl)
    {
      printf("Light :\n x: %f y: %f z: %f\n", 
	     tmpl->pos.x, tmpl->pos.y, tmpl->pos.z);
      printf("r: %d g: %d b: %d\n",
	     tmpl->color.r, tmpl->color.g, tmpl->color.b);
      tmpl = tmpl->next;
    }
  tmp = scene->items;
  while (tmp)
    {
      print_items(tmp);
      tmp = tmp->next;
    }
  printf("\n");
}
