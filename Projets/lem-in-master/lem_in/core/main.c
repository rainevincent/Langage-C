/*
** main.c for main in /home/merran_g/work/c_elem/lem-in
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun May  4 15:13:29 2014 Geoffrey Merran
** Last update Sun May  4 19:17:51 2014 Geoffrey Merran
*/

#include "main.h"

void		reinit_map_vals(t_map *map)
{
  t_room	*tmp;

  tmp = map->head;
  while (tmp != NULL)
    {
      tmp->val = 0;
      tmp = tmp->next;
    }
  map->start->val = map->nb_ants;
}

void		lem_in()
{
  t_map		*map;
  t_path	*path;

  map = parse_lemin();
  path = find_ways(map);
  reinit_map_vals(map);
  lem_in_take_a_selfie(map, path->way);
  free_map(map);
  free_access(path->access);
  free_ways(path->way);
}

int	main(int ac, char **av)
{
  (void) av;
  if (ac == 1)
    lem_in();
  else
    printf(VM_USAGE);
  return (EXIT_SUCCESS);
}
