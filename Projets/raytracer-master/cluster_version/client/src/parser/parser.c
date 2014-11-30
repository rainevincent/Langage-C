/*
** parser.c for  in /home/mediav_j/mabm/raytracer/merge/client/src/parser/mediav_parser
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sat Jun  7 19:15:56 2014 Jeremy Mediavilla
** Last update Sun Jun  8 11:28:14 2014 Jeremy Mediavilla
*/

#define _BSD_SOURCE
#include "core.h"

void		check_balise(int *i, char *balise, char **conf, t_parser *parser)
{
  char		*tab[6];
  void		(*which_func[6])(int *, char **, char *, t_parser *);
  int		j;

  j = 0;
  tab[0] = "<EYE>";
  tab[1] = "<SPHERE>";
  tab[2] = "<PLAN>";
  tab[3] = "<SPOT>";
  tab[4] = "<CYLINDRE>";
  tab[5] = "<CONE>";
  which_func[0] = &get_eye_info;
  which_func[1] = &get_item_info;
  which_func[2] = &get_item_info;
  which_func[3] = &get_spot_info;
  which_func[4] = &get_item_info;
  which_func[5] = &get_item_info;
  while (j < 6)
    {
      if (strcmp(tab[j], balise) == 0)
	{
	  reset_item(parser);
	  (*which_func[j])(i, conf, balise, parser);
	  j = 7;
	}
      j++;
    }
}

char		**epure_tab(char **tab, char *delim)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      tab[i] = remove_char_begin(tab[i], delim);
      i++;
    }
  return (tab);
}

t_scene		*get_scene(char *file)
{
  char		**conf;
  int		i;
  t_parser	parser;

  i = 0;
  if (strlen(file) == 0)
    {
      fprintf(stderr, "Error file is empty\n");
      exit(0);
    }
  conf = my_strd_to_wordtab(file, "\n");
  if (is_xml_balise(conf, "<EYE>", 0) != 1)
    {
      fprintf(stderr, "Error on conf file : EYE missing\n");
      exit(0);
    }
  conf = epure_tab(conf, "\t ");
  init_scene(&parser.scene);
  while (conf[i])
    {
      check_balise(&i, conf[i], conf, &parser);
      i++;
    }
  aff_the_scene(parser.scene);
  return (parser.scene);
}
