/*
** get_spot.c for Parser RT in /home/martel_c/rendu/RT/parser
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Fri May 30 14:08:01 2014 martelliere
** Last update Thu Jun  5 18:39:56 2014 martelliere
*/

#include "parser.h"

int             get_compo(t_parser *parser, int nb)
{
  if (parser->tab[parser->n][3] == '<' &&
      parser->tab[parser->n][strlen(parser->tab[parser->n]) - 1] == '>')
    {
      nb = atof(&parser->tab[parser->n][4]);
      if (nb < 0 || nb > 255)
	{
	  printf("The color composant must be between 0 and 255 line %d.\n",
		 parser->line);
	  exit(EXIT_FAILURE);
	}
    }
  else
    {
      printf("Syntax error line %d.\n", parser->line);
      exit(EXIT_FAILURE);
    }
  return (nb);
}

int             get_rgb(t_parser *parser, char *id)
{
  int           nb;

  parser->line++;
  parser->n++;
  nb = 0;
  if (strncmp(strlower(parser->tab[parser->n]), id, 3) == 0)
    nb = get_compo(parser, nb);
  else
    {
      printf("Syntax error line %d: %s missing.\n", parser->line, id);
      exit(EXIT_FAILURE);
    }
  return (nb);
}

t_rgb           get_color(t_parser *parser)
{
  t_rgb         color;

  parser->line++;
  parser->n++;
  if (strcmp(strlower(parser->tab[parser->n]), "<col>") == 0)
    {
      color.r = get_rgb(parser, "<r>");
      color.g = get_rgb(parser, "<g>");
      color.b = get_rgb(parser, "<b>");
    }
  else
    {
      printf("Syntax error line %d: \"<col>\" missing.\n", parser->line);
      exit(EXIT_FAILURE);
    }
  return (color);
}

void    get_spot(t_scene *scene, t_parser *parser)
{
  scene->spots->pos = get_vector(parser, "<pos>");
  scene->spots->color = get_color(parser);
}
