/*
** balise_tools.c for  in /home/mediav_j/mabm/raytracer/merge/client/src/parser/mediav_parser
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sun Jun  8 10:00:41 2014 Jeremy Mediavilla
** Last update Sun Jun  8 16:19:44 2014 Jeremy Mediavilla
*/

#include "core.h"

int		is_xml_balise(char **tab, char *balise, int i)
{
  int		len;

  len = strlen(balise);
  while (tab[i])
    {
      if (strncmp(remove_char_begin(tab[i], "\t "), balise, len) == 0)
	return (1);
      i++;
    }
  return (0);
}

char		*get_closing_balise(char *balise)
{
  int		size;
  char		*closing;
  int		i;

  size = strlen(balise) + 2;
  closing = my_xmalloc(size * sizeof(char));
  memset(closing, '\0', size);
  closing[0] = '<';
  closing[1] = '/';
  i = 2;
  while (balise[i - 1] != '\0')
    {
      closing[i] = balise[i - 1];
      i++;
    }
  return (closing);
}

int		is_valid_balise(char *str)
{
  char		*balise[6];
  int		i;

  i = 0;
  balise[0] = "<EYE>";
  balise[1] = "<SPHERE>";
  balise[2] = "<PLAN>";
  balise[3] = "<SPOT>";
  balise[4] = "<CYLINDRE>";
  balise[5] = "<CONE>";
  while (i < 6)
    {
      if (strcmp(balise[i], str) == 0)
	return (1);
      i++;
    }
  return (0);
}

void		is_closing_balise(int i, char *balise, char **conf)
{
  char		*closing;
  int		tmp;

  tmp = i;
  closing = get_closing_balise(balise);
  while (conf[i])
    {
      if (conf[i])
	{
	  if (is_valid_balise(conf[i]) == 1)
	    {
	      fprintf(stderr, "Error on line %i : you can't open a balise \
without closing the previous one\n", (i + 1));
	      exit(0);
	    }
	  if (strcmp(closing, conf[i]) == 0)
	    return ;
	}
      i++;
    }
  fprintf(stderr, "Error on line %i : Balise isn't closed\n", tmp);
  exit(0);
}

void		wrong_balise(int *i, char **conf)
{
  fprintf(stderr, "Error on line %i ! Unknown \
balise : %s\n", (*i + 1), conf[*i]);
  exit(0);
}
