/*
** type2.c for type2 in /home/merran_g/work/c_elem/lem-in/lem_in
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun Apr 27 17:07:34 2014 Geoffrey Merran
** Last update Sun Apr 27 17:13:03 2014 Geoffrey Merran
*/

#include "parser.h"

int		is_access_to(char *room, char *access, t_map *map)
{
  t_room	*tmp;
  t_access	*tmp_access;

  tmp = map->head;
  while (tmp)
    {
      if (strcmp(tmp->name, room) == 0)
	{
	  tmp_access = tmp->access;
	  while (tmp_access)
	    {
	      if (strcmp(access, tmp_access->name) == 0)
		return (1);
	      tmp_access = tmp_access->next;
	    }
	}
      tmp = tmp->next;
    }
  return (0);
}
