/*
** debug.c for debug in /home/merran_g/work/c_elem/lem-in/lem_in
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri May  2 18:37:13 2014 Geoffrey Merran
** Last update Fri May  2 18:39:45 2014 Geoffrey Merran
*/

#include "debug.h"

void		aff_map(t_map *map)
{
  t_room	*tmp;

  tmp = map->head;
  printf("\n== AFFICHAGE MAP (DEBUG) ==\n\n");
  while (tmp != NULL)
    {
      printf("-> Salle %s", tmp->name);
      if (map->start == tmp)
	printf(" -- ENTRANCE");
      if (map->end == tmp)
	printf(" -- OUTSIDE");
      printf("\n");
      aff_access(tmp->access);
      tmp = tmp->next;
    }
}

void		aff_access(t_access *access)
{
  t_access	*tmp;

  tmp = access;
  while (tmp != NULL)
    {
      printf("--> Access to %s\n", tmp->name);
      tmp = tmp->next;
    }
}

void		aff_way(t_way *way)
{
  t_way		*tmp;

  tmp = way;
  while (tmp != NULL)
    {
      my_printf("Path size : %d : %t\n", tmp->size, tmp->path);
      tmp = tmp->next;
    }
}

void		aff_path(t_access *path)
{
  t_access	*tmp;

  tmp = path;
  printf("\nPath :\n");
  while (tmp != NULL)
    {
      printf("%p - %s\n", (void *) tmp, tmp->name);
      tmp = tmp->next;
    }
  my_putchar('\n');
}

void		aff_tiret(int val)
{
  int		i;

  i = -1;
  while (++i < val)
    {
      my_putchar('|');
      if ((i + 1) != val)
	my_putchar(' ');
    }
  my_putstr("__");
}
