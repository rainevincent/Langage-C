/*
** remove.c for  in /home/mediav_j/mabm/42sh/src/parser
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sun May 25 11:35:54 2014 Jeremy Mediavilla
** Last update Sun May 25 11:36:39 2014 Jeremy Mediavilla
*/

#include "parser.h"

void		remove_useless_links(t_link *list)
{
  t_link	*tmp;

  tmp = NULL;
  while (list->next != NULL)
    list = list->next;
  while (list->prev != NULL && list->type != END)
    {
      tmp = list->prev;
      remove_link(list);
      list = tmp;
    }
}

void		remove_link_custom(t_link **current, t_link **list)
{
  t_link	*tmp;

  if ((*current)->next != NULL)
    (*current)->next->prev = (*current)->prev;
  if ((*current)->prev != NULL)
    (*current)->prev->next = (*current)->next;
  else
    *list = (*current)->next;
  tmp = (*current)->next;
  free((*current));
  (*current) = NULL;
  (*current) = tmp;
}

void		remove_unvalid_links(t_link **curr)
{
  t_link	*tmp;

  tmp = *curr;
  while (tmp->prev != NULL && tmp->prev->type != END && tmp->type != END)
    tmp = tmp->prev;
  while (tmp != NULL && tmp->type != END)
    {
      tmp->type = -2;
      if (tmp != NULL)
      	tmp = tmp->next;
    }
  *curr = tmp;
}

void		remove_old_links(t_link **current, t_link **list)
{
  t_link	*tmp;

  tmp = *current;
  while (tmp != NULL)
    {
      if (tmp->type == END && tmp->prev->type == END)
	remove_link_custom(&tmp, list);
      if (tmp != NULL && (int)tmp->type == -2)
	{
	  remove_link_custom(&tmp, list);
	  if (tmp != NULL && tmp->prev != NULL)
	    tmp = tmp->prev;
	}
      if (tmp != NULL)
	tmp = tmp->next;
    }
}
