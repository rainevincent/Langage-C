/*
** list.c for  in /home/mediav_j/piscine/eval_expr
**
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
**
** Started on  Fri Oct 25 13:42:22 2013 Jeremy Mediavilla
** Last update Thu May 22 23:34:14 2014 Geoffrey Merran
*/

#define _BSD_SOURCE
#include "history.h"

t_hlist		*create_hlist(char *name, char *date)
{
  t_hlist	*list;

  list = my_xmalloc(sizeof(*list));
  list->next = NULL;
  list->prev = NULL;
  list->name = strdup(name);
  list->date = strdup(date);
  return (list);
}

void		add_tailh(t_history *history, char *name, char *date)
{
  t_hlist	*ptr;

  ptr = create_hlist(name, date);
  history->tail->next = ptr;
  ptr->prev = history->tail;
  history->tail = ptr;
}
