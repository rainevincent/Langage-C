/*
** path.c for  in /home/mediav_j/mabm/lem-in/lem_in
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Fri May  2 16:06:34 2014 Jeremy Mediavilla
** Last update Sat May  3 16:12:30 2014 Jeremy Mediavilla
*/

#define _BSD_SOURCE
#include "core.h"

void		remove_last_access(t_access **access)
{
  t_access	*tmp;

  if (access != NULL)
    {
      tmp = (*access)->next;
      free((*access)->name);
      free(*access);
      *access = tmp;
    }
}

void		fill_path(char ***path, t_access *access)
{
  t_access	*tmp;
  int		i;

  i = 0;
  tmp = access;
  while (tmp != NULL)
    {
      (*path)[i] = strdup(tmp->name);
      i++;
      tmp = tmp->next;
    }
  (*path)[i] = NULL;
}

void		put_in_path(t_way **ways, t_way *new)
{
  t_way		*tmp;
  int		sort;

  tmp = *ways;
  sort = 0;
  while (sort == 0 && tmp != NULL)
    {
      if (new->size <= tmp->size)
	sort = 1;
      tmp = tmp->next;
    }
  new->next = *ways;
  if (*ways != NULL)
    {
      new->prev = (*ways)->prev;
      (*ways)->prev = new;
    }
  else
    new->prev = NULL;
  if (new->prev == NULL)
    *ways = new;
}

void		get_path(t_path *path, int size_path)
{
  t_way		*new;

  new = my_xmalloc(sizeof(*new));
  new->path = my_xmalloc((size_path + 1) * sizeof(char *));
  new->size = size_path;
  fill_path(&new->path, path->access);
  put_in_path(&path->way, new);
}
