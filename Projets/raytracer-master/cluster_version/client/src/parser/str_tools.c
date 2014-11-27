/*
** str_tools.c for  in /home/mediav_j/mabm/raytracer/merge/client/src/parser/mediav_parser
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sun Jun  8 09:59:58 2014 Jeremy Mediavilla
** Last update Sun Jun  8 11:58:09 2014 Jeremy Mediavilla
*/

#include "core.h"

int		is_char_from_str(char c, char *delim)
{
  int		i;

  i = 0;
  while (delim[i])
    {
      if (c == delim[i])
	return (1);
      i++;
    }
  return (0);
}

int		nbr_char_begin(char *str, char *delim)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (is_char_from_str(str[i], delim) != 1)
	return (i);
      i++;
    }
  return (i);
}

char		*remove_char_begin(char *str, char *delim)
{
  int		i;
  int	        size;
  char		*final;
  int		j;

  i = 0;
  j = 0;
  size = strlen(str) - nbr_char_begin(str, delim);
  if (size <= 0)
    {
      fprintf(stderr, "Error on conf file : There is an empty line\n");
      exit(0);
    }
  final = my_xmalloc((size + 1) * sizeof(char));
  memset(final, '\0', (size + 1));
  while (is_char_from_str(str[i], delim) == 1)
    i++;
  while (str[i])
    {
      final[j] = str[i];
      i++;
      j++;
    }
  return (final);
}

char		*get_item_type(char *balise)
{
  int		len;
  char		*final;
  int		i;
  int		j;

  i = 1;
  j = 0;
  len = strlen(balise);
  final = my_xmalloc(len * sizeof(char ));
  memset(final, '\0', len);
  while (balise[i] && balise[i] != '>')
    {
      final[j] = balise[i]; 
      i++;
      j++;
    }
  return (final);
}

int		type_val(char *type)
{
  if (strcmp(type, "SPHERE") == 0)
    return (SPHERE);
  if (strcmp(type, "PLAN") == 0)
    return (PLANE);
  if (strcmp(type, "CONE") == 0)
    return (CONE);
  if (strcmp(type, "CYLINDRE") == 0)
    return (CYLINDER);
  return (-1);
}
