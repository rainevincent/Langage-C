/*
** get_eye.c for Parser RT in /home/martel_c/rendu/RT/raytracer/src/parser/parser2
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Thu Jun  5 18:41:17 2014 martelliere
** Last update Thu Jun  5 18:58:03 2014 martelliere
*/

#include	"parser.h"

float		get_coord(t_parser *parser, float pos)
{
  if (parser->tab[parser->n][3] == '<' &&
      parser->tab[parser->n][strlen(parser->tab[parser->n]) - 1] == '>')
    pos = atof(&parser->tab[parser->n][4]);
  else
    {
      printf("Syntax error line %d.\n", parser->line);
      exit(EXIT_FAILURE);
    }
  return (pos);
}

float		get_pos(t_parser *parser, char *id)
{
  float		pos;

  parser->line++;
  parser->n++;
  pos = 0;
  if (strncmp(strlower(parser->tab[parser->n]), id, 3) == 0)
    pos = get_coord(parser, pos);
  else
    {
      printf("Syntax error line %d: %s missing.\n", parser->line, id);
      exit(EXIT_FAILURE);
    }
  return (pos);
}

t_vector	get_vector(t_parser *parser, char *id)
{
  t_vector	vector;

  parser->line++;
  parser->n++;
  if (strcmp(strlower(parser->tab[parser->n]), id) == 0)
    {
      vector.x = get_pos(parser, "<x>");
      vector.y = get_pos(parser, "<y>");
      vector.z = get_pos(parser, "<z>");
    }
  else
    {
      printf("Syntax error line %d: %s missing.\n", parser->line, id);
      exit(EXIT_FAILURE);
    }
  return (vector);
}

void    get_eye(t_scene *scene, t_parser *parser)
{
  scene->eye->pos = get_vector(parser, "<pos>");
  scene->eye->angle = get_vector(parser, "<rot>");
}
