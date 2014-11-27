/*
** room.c for room in /home/merran_g/work/c_elem/lem-in/lem_in/parser
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri Apr 25 20:09:30 2014 Geoffrey Merran
** Last update Fri May  2 17:12:54 2014 Jeremy Mediavilla
*/

#define _BSD_SOURCE
#include "parser.h"

void		add_room(char **tab, t_map *map)
{
  t_room	*new;

  new = my_xmalloc(sizeof(*new));
  new->val = -1;
  new->name = strdup(tab[0]);
  new->access = NULL;
  new->next = NULL;
  if (map->tail == NULL)
    {
      new->prev = NULL;
      map->head = new;
      map->tail = new;
    }
  else
    {
      map->tail->next = new;
      new->prev = map->tail;
      map->tail = new;
    }
  map->nb_room++;
}

void		add_access(char *name, t_access **access)
{
  t_access	*new;

  new = my_xmalloc(sizeof(*new));
  new->name = strdup(name);
  new->next = *access;
  *access = new;
}

int		give_access(char *room, char *access, t_map *map)
{
  t_room	*tmp;

  tmp = map->head;
  while ((strcmp(tmp->name, room) != 0) && tmp != NULL)
    tmp = tmp->next;
  if (tmp == NULL)
    return (0);
  add_access(access, &(tmp->access));
  return (1);
}
