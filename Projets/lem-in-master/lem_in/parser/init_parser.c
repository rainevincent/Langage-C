/*
** init_parser.c for init_parser in /home/merran_g/work/c_elem/lem-in/lem_in
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu Apr 24 10:48:21 2014 Geoffrey Merran
** Last update Sat May  3 17:53:06 2014 Jeremy Mediavilla
*/

#include "parser.h"

void	init_map(t_map **map)
{
  (*map) = my_xmalloc(sizeof(**map));
  (*map)->nb_ants = 0;
  (*map)->nb_room = 0;
  (*map)->start = NULL;
  (*map)->end = NULL;
  (*map)->head = NULL;
  (*map)->tail = NULL;
}

void	is_valid_map(t_map *map)
{
  if (map->head == NULL)
    my_error("Map error : no room found\n");
  if (map->start == NULL)
    my_error("Map error : no start found\n");
  if (map->end == NULL)
    my_error("Map error : no end found\n");
  if (map->start == map->end)
    my_error("Map error : starting room is end room\n");
}
