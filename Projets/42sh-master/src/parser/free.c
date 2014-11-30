/*
** free.c for  in /home/mediav_j/mabm/42sh
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sun May 25 18:40:33 2014 Jeremy Mediavilla
** Last update Sun May 25 18:57:41 2014 Jeremy Mediavilla
*/

#include "parser.h"

void		free_tree(t_tree *tree)
{
  t_tree	*tmp;
  t_tree	*save;

  tmp = tree;
  while (tmp != NULL)
    {
      save = tmp->next;
      free(tmp->access);
      free(tmp);
      tmp = save;
    }
}

void		free_list(t_link *list)
{
  t_link	*tmp;
  t_link	*save;

  tmp = list;
  while (tmp != NULL)
    {
      save = tmp->next;
      if (tmp->data != NULL)
	free(tmp->data);
      free(tmp);
      tmp = save;
    }
}
