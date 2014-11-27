/*
** list2.c for  in /home/mediav_j/mabm/42sh/src/parser
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May 14 11:55:35 2014 Jeremy Mediavilla
** Last update Sun May 25 18:03:21 2014 Jeremy Mediavilla
*/

#include "parser.h"

t_link		*init_list(char *str, t_type i)
{
  t_link	*link;

  if ((link = my_xmalloc(sizeof(*link))) == NULL)
    return (NULL);
  link->next = NULL;
  link->prev = NULL;
  link->data = str;
  link->type = i;
  return (link);
}

void		add_link_after(t_link *link, char *str, t_type i)
{
  t_link	*ptr;

  ptr = init_list(str, i);
  if (link->next != NULL)
    {
      ptr->next = link->next;
      link->next->prev = ptr;
    }
  link->next = ptr;
  ptr->prev = link;
}

void		add_link_before(t_link *link, char *str, t_type i)
{
  t_link	*ptr;

  ptr = init_list(str, i);
  if (link->prev != NULL)
    {
      ptr->prev = link->prev;
      link->prev->next = ptr;
    }
  link->prev = ptr;
  ptr->next = link;
}

void		remove_link(t_link *link)
{
  if (!(link->prev == NULL && link->next == NULL))
    {
      if (link->prev != NULL)
	link->prev->next = link->next;
      else
	link->next->prev = NULL;
      if (link->next != NULL)
	link->next->prev = link->prev;
      else
	link->prev->next = NULL;
    }
  free(link);
}

void		link_to_end(t_link *link, char *str, t_type i)
{
  while (link->next != NULL)
    link = link->next;
  add_link_after(link, str, i);
}
