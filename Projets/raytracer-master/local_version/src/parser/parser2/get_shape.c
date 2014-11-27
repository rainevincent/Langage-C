/*
** get_shape.c for Parser RT in /home/martel_c/rendu/RT/parser
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Mon Jun  2 14:16:00 2014 martelliere
** Last update Fri Jun  6 18:02:04 2014 Geoffrey Merran
*/

#include "parser.h"

float           get_size(t_parser *parser)
{
  float         size;

  parser->line++;
  parser->n++;
  if (strcmp(strlower(parser->tab[parser->n]), "<size>") == 0)
    {
      parser->n++;
      parser->line++;
      if (parser->tab[parser->n][0] == '<' &&
          parser->tab[parser->n][strlen(parser->tab[parser->n]) - 1] == '>')
        size = atof(&parser->tab[parser->n][1]);
      else
        {
          printf("Syntax error line %d.\n", parser->line);
          exit(EXIT_FAILURE);
        }
    }
  else
    {
      printf("Syntax error line %d: \"<size>\" missing.\n", parser->line);
      exit(EXIT_FAILURE);
    }
  return (size);
}

void    get_plan(t_scene *scene, t_parser *parser)
{
  t_item        new;

  new.pos = get_vector(parser, "<pos>");
  new.color = get_color(parser);
  new.angle = get_vector(parser, "<rot>");
  new.type = PLANE;
  new.rayon = get_size(parser);
  new.brillance = get_brill(parser);
  new.transparence = get_opacity(parser);
  add_item(&(scene->items), new);
}

void    get_sphere(t_scene *scene, t_parser *parser)
{
  t_item        new;

  new.pos = get_vector(parser, "<pos>");
  new.color = get_color(parser);
  new.angle = get_vector(parser, "<rot>");
  new.type = SPHERE;
  new.rayon = get_size(parser);
  new.brillance = get_brill(parser);
  new.transparence = get_opacity(parser);
  add_item(&(scene->items), new);
}

void    get_cone(t_scene *scene, t_parser *parser)
{
  t_item        new;

  new.pos = get_vector(parser, "<pos>");
  new.color = get_color(parser);
  new.angle = get_vector(parser, "<rot>");
  new.type = CONE;
  new.rayon = get_size(parser);
  new.brillance = get_brill(parser);
  new.transparence = get_opacity(parser);
  add_item(&(scene->items), new);
}

void    get_cylindre(t_scene *scene, t_parser *parser)
{
  t_item        new;

  new.pos = get_vector(parser, "<pos>");
  new.color = get_color(parser);
  new.angle = get_vector(parser, "<rot>");
  new.type = CYLINDER;
  new.rayon = get_size(parser);
  new.brillance = get_brill(parser);
  new.transparence = get_opacity(parser);
  add_item(&(scene->items), new);
}
