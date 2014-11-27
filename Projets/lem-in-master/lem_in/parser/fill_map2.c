/*
** fill_map2.c for fill_map2 in /home/merran_g/work/c_elem/lem-in/lem_in/parser
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun Apr 27 13:51:20 2014 Geoffrey Merran
** Last update Sun Apr 27 13:52:25 2014 Geoffrey Merran
*/

#include "parser.h"

void	get_start(int step, t_map *map)
{
  if (map->start != NULL)
    my_error("Invalid start : already one\n");
  if (step != 2)
    my_error("Invalid syntax : check how to build a map\n");
  if (map->tail == NULL)
    my_error("Invalid room (intern problem) : not found in list\n");
  map->start = map->tail;
}

void	get_end(int step, t_map *map)
{
  if (map->end != NULL)
    my_error("Invalid end : already one\n");
  if (step != 2)
    my_error("Invalid syntax : check how to build a map\n");
  if (map->tail == NULL)
    my_error("Invalid room (intern problem) : not found in list\n");
  map->end = map->tail;
}
