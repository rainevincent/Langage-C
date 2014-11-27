/*
** list.c for  in /home/mediav_j/piscine/eval_expr
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Fri Oct 25 13:42:22 2013 Jeremy Mediavilla
** Last update Sat Jun  7 22:52:40 2014 Geoffrey Merran
*/

#include "core.h"

t_list		*create_list(char *str)
{
  t_list	*list;

  list = malloc(sizeof(*list));
  list->next = NULL;
  list->prev = NULL;
  list->data = str;
  return (list);
}

void		add_after(t_list *list, char *str)
{
  t_list	*ptr;

  ptr = create_list(str);
  if (list->next != NULL)
    {
      ptr->next = list->next;
      list->next->prev = ptr;
    }
  list->next = ptr;
  ptr->prev = list;
}

void		add_before(t_list *list, char *str)
{
  t_list	*ptr;

  ptr = create_list(str);
  if (list->prev != NULL)
    {
      ptr->prev = list->prev;
      list->prev->next = ptr;
    }
  list->prev = ptr;
  ptr->next = list;
}

void		remove_from_list(t_list *list)
{
  t_list	*ptr;

  ptr = list;
  if (!(ptr->prev == NULL && ptr->next == NULL))
    {
      if (ptr->prev != NULL)
	ptr->prev->next = ptr->next;
      else
	ptr->next->prev = NULL;
      if (ptr->next != NULL)
	ptr->next->prev = ptr->prev;
      else
	ptr->prev->next = NULL;
    }
  free(ptr);
}

void		add_to_end(t_list *list, char *str)
{
  while (list->next != NULL)
    list = list->next;
  add_after(list, str);
}
