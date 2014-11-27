/*
** tree.c for  in /home/mediav_j/mabm/42sh/src/parser
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May 21 15:41:53 2014 Jeremy Mediavilla
** Last update Sun May 25 14:47:10 2014 Jeremy Mediavilla
*/

#include "parser.h"

t_tree		*init_tree(int type, int *access)
{
  t_tree	*tree;

  if ((tree = my_xmalloc(sizeof(*tree))) == NULL)
    return (NULL);
  tree->next = NULL;
  tree->prev = NULL;
  tree->curr_type = type;
  tree->access = access;
  return (tree);
}

void		add_tree_after(t_tree *tree, int type, int *access)
{
  t_tree	*ptr;

  ptr = init_tree(type, access);
  if (tree->next != NULL)
    {
      ptr->next = tree->next;
      tree->next->prev = ptr;
    }
  tree->next = ptr;
  ptr->prev = tree;
}

void		remove_tree(t_tree *tree)
{
  if (!(tree->prev == NULL && tree->next == NULL))
    {
      if (tree->prev != NULL)
	tree->prev->next = tree->next;
      else
	tree->next->prev = NULL;
      if (tree->next != NULL)
	tree->next->prev = tree->prev;
      else
	tree->prev->next = NULL;
    }
  free(tree);
}

void		add_to_tree_end(t_tree *tree, int type, int *access)
{
  while (tree->next != NULL)
    tree = tree->next;
  add_tree_after(tree, type, access);
}
