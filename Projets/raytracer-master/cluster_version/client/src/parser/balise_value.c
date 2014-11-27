/*
** balise_value.c for  in /home/mediav_j/mabm/raytracer/merge/client/src/parser/mediav_parser
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sun Jun  8 10:01:30 2014 Jeremy Mediavilla
** Last update Sun Jun  8 12:21:30 2014 Jeremy Mediavilla
*/

#include "core.h"

int		get_ibalise_value(char *line, char *balise, int j)
{
  int		len;
  int		size;
  char		*final;
  int		i;

  i = 0;
  len = strlen(balise);
  size = 2 * len + 2;
  final = my_xmalloc(size * sizeof(char));
  memset(final, '\0', size);
  while (line[len] && line[len + 0] != '<')
    {
      if (!((line[len] >= '0' && line[len] <= '9') ||
	    line[len] == '-'))
	{
	  fprintf(stderr, "Error on line %i : wrong number \
in %s balise\n", (j + 1), balise);
	  exit(0);
	}
      final[i] = line[len];
      i++;
      len++;
    }
  return (atoi(final));
}

float		get_fbalise_value(char *line, char *balise,  int j)
{
  int		len;
  int		size;
  char		*final;
  int		i;

  i = 0;
  len = strlen(balise);
  size = 2 * len + 2;
  final = my_xmalloc(size * sizeof(char));
  memset(final, '\0', size);
  while (line[len] && line[len + 0] != '<')
    {
      if (!((line[len] >= '0' && line[len] <= '9') ||
	    line[len] == '-'))
	{
	  fprintf(stderr, "Error on line %i : wrong number \
in %s balise\n", (j + 1), balise);
	  exit(0);
	}
      final[i] = line[len];
      i++;
      len++;
    }
  return (atof(final));
}

float		get_fcoord_pars(char **conf, int i, char *balise)
{
  int		j;
  int		len;
  int		tmp;

  j = 0;
  tmp = i - 1;
  len = strlen(balise);
  while (j < 3)
    {
      if (conf[i] && strncmp(conf[i], balise, len) == 0)
	return (get_fbalise_value(conf[i], balise, i));
      i++;
      j++;
    }
  fprintf(stderr, "Error on line %i : Missing %s balise \
after %s\n", (tmp + 1), balise, conf[tmp]);
  exit(0);
}

float		get_fbalise_value_spec(char *line, char *balise, int j)
{
  int		len;
  int		size;
  char		*final;
  int		i;

  i = 0;
  len = strlen(balise);
  size = 2 * len + 2;
  final = my_xmalloc(size * sizeof(char));
  memset(final, '\0', size);
  while (line[len] && line[len + 0] != '<')
    {
      if (!(line[len] >= '0' && line[len] <= '9') && line[len] != '.')
	{
	  fprintf(stderr, "Error on line %i : wrong number \
in %s balise\n", (j + 1), balise);
	  exit(0);
	}
      final[i] = line[len];
      i++;
      len++;
    }
  return (atof(final));
}

float		get_effects_val(char *balise, char **conf, int i)
{
  int		j;
  int		len;
  float		tmp;

  j = 0;
  len = strlen(balise);
  while (j < 3)
    {
      if (strncmp(conf[i], balise, len) == 0)
	{
	  tmp = get_fbalise_value_spec(conf[i], balise, i);
	  if (tmp < 0 || tmp > 1)
	    {
	      fprintf(stderr, "Error on line %i : value must be \
between 0 and 1\n", (i + 1));
	    }
	  return (tmp);
	}
      j++;
      i++;
    }
  return (0);
}
