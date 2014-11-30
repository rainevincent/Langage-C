/*
** free.c for free in /home/merran_g/work/c_elem/lem-in/lem_in/core
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun May  4 19:00:34 2014 Geoffrey Merran
** Last update Sun May  4 19:17:00 2014 Geoffrey Merran
*/

#include "core.h"

void		free_access(t_access *access)
{
  t_access	*tmp;

  while (access != NULL)
    {
      tmp = access->next;
      free(access);
      access = tmp;
    }
}

void		free_map(t_map *map)
{
  t_room	*tmp;

  while (map->head != NULL)
    {
      tmp = map->head->next;
      free(map->head->name);
      free(map->head->access);
      free(map->head);
      map->head = tmp;
    }
}

void		free_ways(t_way *ways)
{
  t_way		*tmp;

  while (ways != NULL)
    {
      tmp = ways->next;
      free_tab(ways->path);
      free(ways);
      ways = tmp;
    }
}
