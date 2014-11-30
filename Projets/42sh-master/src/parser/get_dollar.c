/*
** get_dollar.c for  in /home/mediav_j/mabm/42sh/src/parser
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May 28 03:52:29 2014 Jeremy Mediavilla
** Last update Wed May 28 14:40:07 2014 Jeremy Mediavilla
*/

#include "parser.h"
#include "core.h"

void		get_dollar_bitch(t_link **list, t_list *env)
{
  t_link	*tmp;
  t_link	*save;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->type == DOLL && tmp->next != NULL)
	{
	  if (tmp->next->type == WORD)
	    if (is_in_env(env, tmp->next->data) == 1)
	      {
		save = tmp->next;
		remove_link(tmp);
		tmp = save;
		tmp->data = check_env_var(env, strcat(tmp->data, "="),
					  (strlen(tmp->data) + 1));
	      }
	}
	tmp = tmp->next;
    }
}
