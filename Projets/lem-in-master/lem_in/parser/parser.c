/*
** parser.c for parser in /home/merran_g/work/c_elem/lem-in/lem_in/parser
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr 22 14:57:57 2014 Geoffrey Merran
** Last update Sun Apr 27 14:02:08 2014 Geoffrey Merran
*/

#include "parser.h"

int	parse_command(char *buffer, int *step)
{
  printf("%s\n", buffer);
  (void) step;
  if (strcmp(buffer, "##start") == 0)
    return (1);
  if (strcmp(buffer, "##end") == 0)
    return (2);
  return (0);
}

void	parse_data2(char *buffer, int *step, t_map *map)
{
  char	**tab2;

  tab2 = my_strd_to_wordtab(buffer, "-");
  if (tab2 == NULL)
    my_error("Empty line : check how to build a map\n");
  if (my_strlen_tabs(tab2) == 1)
    get_nb_ants(tab2, step, map);
  else if (my_strlen_tabs(tab2) == 2)
    {
      get_access(tab2, step, map);
      printf("%s\n", buffer);
    }
  else
    {
      fprintf(stderr, "Invalid line : %s\n", buffer);
      exit(EXIT_FAILURE);
    }
  free_tab(tab2);
}

void	parse_data(char *buffer, int *step, t_map *map)
{
  char	**tab;

  tab = my_strd_to_wordtab(buffer, " \t");
  if (tab == NULL)
    my_error("Invalid/Empty line : check how to build a map\n");
  if (my_strlen_tabs(tab) == 1)
    parse_data2(tab[0], step, map);
  else if (my_strlen_tabs(tab) == 3)
    {
      get_room(tab, step, map);
      printf("%s\n", buffer);
    }
  else
    {
      fprintf(stderr, "Invalid line : %s\n", buffer);
      exit(EXIT_FAILURE);
    }
  free_tab(tab);
}

int	parse_type(t_info info, char *buffer, int *step, t_map *map)
{
  if (info.type == COMMENTARY_TYPE)
    printf("%s\n", buffer);
  else if (info.type == COMMAND_TYPE)
    return (parse_command(buffer, step));
  else
    parse_data(buffer, step, map);
  return (info.command);
}

t_map		*parse_lemin()
{
  t_map		*map;
  char		*buffer;
  int		step;
  t_info	info;

  init_map(&map);
  step = 0;
  info.command = 0;
  while ((buffer = get_next_line(0)) != NULL)
    {
      info.type = get_line_type(buffer);
      info.command = parse_type(info, buffer, &step, map);
      info.command = get_command(info.command, step, map);
      free(buffer);
    }
  is_valid_map(map);
  return (map);
}
