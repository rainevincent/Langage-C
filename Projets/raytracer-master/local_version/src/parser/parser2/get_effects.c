/*
** get_effects.c for Parser RT in /home/martel_c/rendu/RT/raytracer/src/parser/parser2
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Thu Jun  5 18:09:01 2014 martelliere
** Last update Fri Jun  6 15:08:20 2014 martelliere
*/

#include	"parser.h"

void		check_constant(t_parser *parser, float nb)
{
  if (nb < 0.0 || nb > 1.0)
    {
      printf("Error line %d: this value must be between 0 and 1 included.\n",
	     parser->line, nb);
      exit(EXIT_FAILURE);
    }
}

float		get_brill(t_parser *parser)
{
  float		brill;

  parser->line++;
  parser->n++;
  if (strcmp(strlower(parser->tab[parser->n]), "<brill>") == 0)
    {
      parser->n++;
      parser->line++;
      if (parser->tab[parser->n][0] == '<' &&
          parser->tab[parser->n][strlen(parser->tab[parser->n]) - 1] == '>')
	brill = atof(&(parser->tab[parser->n][1]));
      else
        {
          printf("Syntax error line %d.\n", parser->line);
          exit(EXIT_FAILURE);
        }
      check_constant(parser, brill);
    }
  else
    {
      printf("Syntax error line %d: \"<brill>\" missing.\n", parser->line);
      exit(EXIT_FAILURE);
    }
  return (brill);
}

float		get_opacity(t_parser *parser)
{
  float		opacity;

  parser->line++;
  parser->n++;
  if (strcmp(strlower(parser->tab[parser->n]), "<opacity>") == 0)
    {
      parser->n++;
      parser->line++;
      if (parser->tab[parser->n][0] == '<' &&
          parser->tab[parser->n][strlen(parser->tab[parser->n]) - 1] == '>')
        opacity = atof(&parser->tab[parser->n][1]);
      else
        {
          printf("Syntax error line %d.\n", parser->line);
          exit(EXIT_FAILURE);
        }
      check_constant(parser, opacity);
    }
  else
    {
      printf("Syntax error line %d: \"<opacity>\" missing.\n", parser->line);
      exit(EXIT_FAILURE);
    }
  return (opacity);
}
