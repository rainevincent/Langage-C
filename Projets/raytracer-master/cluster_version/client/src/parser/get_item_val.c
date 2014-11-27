/*
** get_item_val.c for  in /home/mediav_j/mabm/raytracer/merge/client/src/parser/mediav_parser
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sun Jun  8 10:04:28 2014 Jeremy Mediavilla
** Last update Sun Jun  8 16:23:10 2014 Jeremy Mediavilla
*/

#include "core.h"

void		print_rgb_error(int i)
{
  fprintf(stderr, "Error on line %i : color value must be \
between 0 and 255\n", i);
  exit(0);
}

void		get_item_pos(char **conf, int i, char *balise, t_parser *parser)
{
  t_vector	v;

  while (conf[i] && strcmp(conf[i], balise) != 0)
    i++;
  if (conf[i] && strcmp(conf[i], balise) == 0)
    i++;
  if (conf[i])
    {
      v.x = get_fcoord_pars(conf, i, "<x>");
      v.y = get_fcoord_pars(conf, i, "<y>");
      v.z = get_fcoord_pars(conf, i, "<z>");
    }
  else
    {
      fprintf(stderr, "Error with get_item_pos functions\n");
      exit(0);
    }
  if (strcmp(balise, "<POS>") == 0)
    parser->tmp.pos = v;
  if (strcmp(balise, "<ROT>") == 0)
    parser->tmp.angle = v;
}

int		get_color_rgb(int i, char **conf, char *balise)
{
  int		j;
  int		len;
  int		tmp;
  int		tmp2;

  j = 0;
  tmp = i - 1;
  len = strlen(balise);
  if (strcmp(conf[i],"<COLOR>") == 0)
    i++;
  while (j < 3)
    {
      if (conf[i] && strncmp(conf[i], balise, len) == 0)
	{
	  tmp2 = get_ibalise_value(conf[i], balise, i);
	  if (tmp2 < 0 || tmp2 > 255)
	    print_rgb_error(tmp);
	  return (tmp2);
	}
      i++;
      j++;
    }
  fprintf(stderr, "Error on line %i : Missing %s balise \
after %s\n", (tmp + 1), balise, conf[tmp]);
  exit(0);
}

void		get_effects(int i, char **conf, t_parser *parser)
{
  while (conf[i] && strcmp(conf[i], "<EFFECTS>") != 0)
    i++;
  if (conf[i + 1] != '\0')
    i++;
  parser->tmp.brillance = get_effects_val("<BRILL>", conf, i);
  parser->tmp.transparence = get_effects_val("<TRANSP>", conf, i);
  parser->tmp.reflexion = get_effects_val("<REFLEXION>", conf, i);
  parser->tmp.effect = get_type_effect_val("<EFFECT>", conf, i);
}

void		get_size_item(int i, char **conf, t_parser *parser)
{
  float		size;

  size = 0;
  while (conf[i] && strncmp(conf[i], "<SIZE>", 6) != 0)
    i++;
  if (conf[i])
    size = get_effects_val2("<SIZE>", conf, i);
  if (size < 0)
    {
      fprintf(stderr, "Error on line %i : you can't have a \
negative size\n", i);
      exit(0);
    }
  parser->tmp.rayon = size;  
}
