/*
** get_infos.c for  in /home/mediav_j/mabm/raytracer/merge/client/src/parser/mediav_parser
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sun Jun  8 10:02:17 2014 Jeremy Mediavilla
** Last update Sun Jun  8 16:17:42 2014 Jeremy Mediavilla
*/

#define _BSD_SOURCE
#include "core.h"

void		get_color_info(int i, char **conf, t_parser *parser)
{
  char		*closing;
  t_rgb		c;

  while (conf[i] && strcmp(conf[i], "<COLOR>") != 0)
    i++;
  if (conf[i] && conf[i + 1] != '\0')
    i++;
  if (conf[i])
    {
      closing = get_closing_balise(conf[i]);
      c.r = get_color_rgb(i, conf, "<r>");
      c.g = get_color_rgb(i, conf, "<g>");
      c.b = get_color_rgb(i, conf, "<b>");
      parser->tmp.color = c;
    }
  else
    {
      fprintf(stderr, "error on get_color_info\n");
      exit(0);
    }
  while (conf[i] && strcmp(conf[i], closing) != 0)
    (i)++;
  if (conf[i] && conf[i + 1] != '\0')
    (i)++;
}

void		get_item_info(int *i, char **conf, char *balise, t_parser *parser)
{
  char		*closing;
  char		*closing2;
  int		tmp;

  parser->tmp.type = type_val(get_item_type(balise));
  closing = get_closing_balise(conf[*i]);
  if (conf[*i + 1] != '\0')
    (*i)++;
  is_closing_balise(*i, conf[*i], conf);
  tmp = *i;
  get_effects(tmp, conf, parser);
  get_size_item(tmp, conf, parser);
  get_color_info(tmp, conf, parser);
  get_item_pos(conf, *i, conf[*i], parser);
  closing2 = get_closing_balise(conf[*i]);
  while (conf[*i] && strcmp(conf[*i], closing2) != 0)
    (*i)++;
  if (conf[*i + 1] != '\0')
    (*i)++;
  get_item_pos(conf, *i, conf[*i], parser);
  while (conf[*i] && strcmp(conf[*i], closing) != 0)
    (*i)++;
  add_item(&parser->scene->items, parser->tmp);
}

void		get_spot_info(int *i, char **conf, char *balise, t_parser *parser)
{
  char		*curr;
  char		*closing;
  t_spot	*new;

  if (conf[*i] && conf[*i + 1] != '\0')
    (*i)++;
  is_closing_balise(*i, conf[*i], conf);
  curr = strdup(conf[*i]);
  if (conf[*i] && !(strcmp(conf[*i], get_closing_balise(balise)) == 0))
    {
      get_item_pos(conf, *i, conf[*i], parser);
      closing = get_closing_balise(curr);
      while (conf[*i] && strcmp(conf[*i], closing) != 0)
	(*i)++;
      if (conf[*i] && conf[*i + 1] != '\0')
	(*i)++;
      get_color_info(*i, conf, parser);
      new = my_xmalloc(sizeof(*new));
      new->pos = parser->tmp.pos;
      new->color = parser->tmp.color;
      new->next = parser->scene->spots;
      parser->scene->spots = new;
    }
}

void		get_eye_info(int *i, char **conf, char *balise, t_parser *parser)
{
  char		*curr;
  char		*closing;

  if (conf[*i] && conf[*i + 1] != '\0')
    (*i)++;
  is_closing_balise(*i, conf[*i], conf);
  curr = strdup(conf[*i]);
  if (conf[*i] && !(strcmp(conf[*i], get_closing_balise(balise)) == 0))
    {
      get_item_pos(conf, *i, conf[*i], parser);
      closing = get_closing_balise(curr);
      while (conf[*i] && strcmp(conf[*i], closing) != 0)
	(*i)++;
      if (conf[*i] && conf[*i + 1] != '\0')
	(*i)++;
      if (conf[*i])
	{
	  get_item_pos(conf, *i, conf[*i], parser);
	  parser->scene->eye->pos = parser->tmp.pos;
	  parser->scene->eye->angle = parser->tmp.angle;
	}
      else
	my_error("Error on get_eye_info\n");
    }
}

float		get_effects_val2(char *balise, char **conf, int i)
{
  int		j;
  int		len;
  float		tmp;

  j = 0;
  len = strlen(balise);
  while (j < 3)
    {
      if (conf[i] && strncmp(conf[i], balise, len) == 0)
	{
	  tmp = get_fbalise_value_spec(conf[i], balise, i);
	  return (tmp);
	}
      j++;
      i++;
    }
  return (0);
}
