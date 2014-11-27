/*
** main.c for Parser RT in /home/martel_c/rendu/RT/parser
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Tue May 13 17:52:15 2014 martelliere
** Last update Thu Jun  5 18:58:26 2014 martelliere
*/

#include "parser.h"

void		check_scene(int k)
{
  if (k == 2)
    printf("At least one light is needed by the RT.\n");
  else if (k == 1)
    printf("You must provide the eye informations.\n");
  else
    printf("Missing both eye and light informations.\n");
}

t_scene		*get_scene(char *buff)
{
  t_parser	*parser;
  t_scene	*scene;
  int		i;

  /*
  ** DEBUT DU PARSEUR
  */

  parser = my_xmalloc(sizeof(t_parser));
  scene = NULL;
  scene = init_scene(scene);
  parser->tab = my_str_to_wordtab(buff);
  parser->line = 1;
  parser->k = 0;
  parser->n = 0;
  i = 0;
  while (parser->tab[parser->n] != NULL)
    {
      parser->k = my_parser(scene, parser, i);
      parser->line++;
      parser->n++;
    }

  /*
  ** PARTIE A LAISSER POUR VERIFIER LA PRESENCE DE L'OEIL ET D'UNE LIGHT EN FONCTION DU RETOUR DE K
  */

  if (parser->k != 3)
    check_scene(parser->k);
  //return (scene);
}

int		main(int ac, char **av)
{
  char		*s;
  char		*buff;
  int		fd;

  if (ac == 2)
    {
      fd = xopen(av[1], O_RDONLY, 00644);
      buff = my_alloc_init(sizeof(char), 0);
      while ((s = get_next_line(fd)) != NULL)
	{
	  buff = my_xrealloc(buff, strlen(s) + 1);
	  strcat(buff, s);
	  xfree(s);
	}
      get_scene(buff);
      xclose(fd);
    }
  else
    printf("Usage: ./rt <file[.conf]>\n");
  return (0);
}
