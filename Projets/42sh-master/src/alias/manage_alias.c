/*
** manage_histor.c for history 42sh in /home/martel_c/rendu/42sh
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Fri May  9 15:54:07 2014 martelliere
** Last update Sat May 24 06:42:15 2014 Geoffrey Merran
*/

#include "aliasing.h"

int		display_alias(t_alias *alias, char *name)
{
  t_alist	*tmp;

  tmp = alias->list;
  while (tmp)
    {
      if (strcmp(name, tmp->name) == 0)
	{
	  printf("alias %s='%s'\n", tmp->name, tmp->content);
	  return (1);
	}
      tmp = tmp->next;
    }
  fprintf(stderr, "42sh: alias: %s: not found.\n", name);
  return (-1);
}

int		display_all_alias(t_alias *alias)
{
  t_alist	*tmp;

  tmp = alias->list;
  if (tmp == NULL)
    {
      printf("42sh: alias: no alias found.\n");
      return (0);
    }
  while (tmp)
    {
      printf("alias %s='%s'\n", tmp->name, tmp->content);
      tmp = tmp->next;
    }
  return (0);
}

int		add_alias(t_alias *alias, char *name, char *content)
{
  t_alist	*new;

  new = my_xmalloc(sizeof(*new));
  if (new == NULL)
    return (-1);
  new->name = name;
  new->content = content;
  new->next = alias->list;
  alias->list = new;
  return (0);
}
