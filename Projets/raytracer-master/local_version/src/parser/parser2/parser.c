/*
** parser.c for parser RT in /home/martel_c/rendu/RT/parser
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Tue May 13 17:52:03 2014 martelliere
** Last update Mon Jun  2 15:04:37 2014 martelliere
*/

#include "parser.h"

char	*strlower(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	str[i] = str[i] + 32;
      i++;
    }
  return (str);
}

void	init_functab(char **otab, ptr *which_object)
{
  otab[0] = "<plan>";
  otab[1] = "<spot>";
  otab[2] = "<eye>";
  otab[3] = "<sphere>";
  otab[4] = "<cone>";
  otab[5] = "<cylindre>";
  which_object[0] = &get_plan;
  which_object[1] = &get_spot;
  which_object[2] = &get_eye;
  which_object[3] = &get_sphere;
  which_object[4] = &get_cone;
  which_object[5] = &get_cylindre;
}

int	my_parser(t_scene *scene, t_parser *parser, int i)
{
  char	*otab[6];
  ptr	which_object[6];

  init_functab(otab, which_object);
  i = 0;
  while (i < 5)
    {
      if (strcmp(otab[i], strlower(parser->tab[parser->n])) == 0)
	{
	  if ((i == 1 || i == 2) && parser->k != 3)
	    parser->k = parser->k + i;
	  (*which_object[i++])(scene, parser);
	  i = 6;
	}
      i++;
    }
  if (i == 6)
    {
      printf("%s: unknown object line %d.\n", parser->tab[0], parser->line);
      exit(EXIT_FAILURE);
    }
  return (parser->k);
}
