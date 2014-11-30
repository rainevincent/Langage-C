/*
** ants.c for ants in /home/merran_g/work/c_elem/lem-in/lem_in/core
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri May  2 20:01:46 2014 Geoffrey Merran
** Last update Sun May  4 18:57:09 2014 Geoffrey Merran
*/

#include "core.h"

void		init_anthill(t_anthill **anthill)
{
  *anthill = my_xmalloc(sizeof(**anthill));
  (*anthill)->head = NULL;
  (*anthill)->tail = NULL;
  (*anthill)->nb_ants = 0;
}

void		add_ant(t_anthill *anthill, int id, t_way *way)
{
  t_ant		*new;

  new = my_xmalloc(sizeof(*new));
  new->id = id;
  new->way = way;
  new->room = way->size - 1;
  new->next = NULL;
  if (anthill->tail == NULL)
    {
      new->prev = NULL;
      anthill->head = new;
      anthill->tail = new;
    }
  else
    {
      anthill->tail->next = new;
      new->prev = anthill->tail;
      anthill->tail = new;
    }
  anthill->nb_ants++;
}

t_ant		*remove_ant(t_ant *ant, t_anthill *anthill)
{
  t_ant		*tmp;

  if (ant->prev != NULL)
    ant->prev->next = ant->next;
  if (ant->next != NULL)
    ant->next->prev = ant->prev;
  if (ant == anthill->head && ant == anthill->tail)
    {
      anthill->head = NULL;
      anthill->tail = NULL;
      free(ant);
      return (NULL);
    }
  else
    {
      if (anthill->head == ant)
	anthill->head = ant->next;
      if (anthill->tail == ant)
	anthill->tail = ant->prev;
      tmp = ant->next;
      free(ant);
      return (tmp);
    }
}
