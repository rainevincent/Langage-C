/*
** move.c for  in /home/mediav_j/mabm/lem-in/lem_in
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sat May  3 17:00:36 2014 Jeremy Mediavilla
** Last update Sun May  4 19:21:04 2014 Geoffrey Merran
*/

#include "core.h"

int		move_next_room(t_map *map, t_ant *ant, int esp)
{
  t_room	*tmp;
  t_room	*cur;

  if (ant->room != 0)
    {
      cur = find_room(map, ant->way->path[ant->room]);
      tmp = find_room(map, ant->way->path[ant->room - 1]);
      if (tmp->val == 0 || tmp == map->end)
	{
	  if (cur == map->start)
	    map->start->val = map->start->val - 1;
	  else
	    cur->val = 0;
	  if (tmp == map->end)
	    map->end->val = map->end->val + 1;
	  else
	    tmp->val = ant->id;
	  ant->room--;
	  if (esp == 1)
	    printf(" ");
	  printf("P%d-%s", ant->id, tmp->name);
	  return (1);
	}
    }
  return (esp);
}

void		push_ants(t_map *map, t_anthill *anthill)
{
  t_ant		*tmp;
  int		esp;

  esp = 0;
  tmp = anthill->head;
  while (tmp)
    {
      esp = move_next_room(map, tmp, esp);
      if (tmp->room == 0)
	tmp = remove_ant(tmp, anthill);
      else
	tmp = tmp->next;
    }
  printf("\n");
}

void		create_ants(t_map *map, t_anthill *anthill, t_way *way)
{
  t_way		*tmp;
  static int   	new_ants = 1;

  if (new_ants <= map->nb_ants)
    {
      tmp = way;
      while (tmp != NULL &&
	     ((map->nb_ants - new_ants) >= tmp->size || tmp == way))
	{
	  add_ant(anthill, new_ants, tmp);
	  new_ants++;
	  tmp = tmp->next;
	}
    }
}

void		lem_in_take_a_selfie(t_map *map, t_way *way)
{
  t_anthill	*anthill;

  init_anthill(&anthill);
  while (map->end->val != map->nb_ants)
    {
      create_ants(map, anthill, way);
      push_ants(map, anthill);
    }
  free(anthill);
}
