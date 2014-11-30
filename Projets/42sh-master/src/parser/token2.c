/*
** token2.c for  in /home/mediav_j/mabm/42sh/src/parser
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sun May 25 11:50:32 2014 Jeremy Mediavilla
** Last update Sun May 25 15:23:33 2014 Jeremy Mediavilla
*/

#include "parser.h"

int		check_token_succession(t_link *list, t_tree *tree)
{
  t_tree	*tmp;
  t_link	*tmp_list;

  tmp = tree;
  tmp_list = list;
  while (tmp != NULL)
    {
      if ((int)tmp_list->type == tmp->curr_type)
	{
	  if (tmp_list->next == NULL)
	    return (is_valid_end_access(tmp));
	  if (is_valid_access(tmp_list->next->type, tmp->access) == 1)
	    return (0);
	  else
	    {
	      aff_type_error((int)tmp_list->type, (int)tmp_list->next->type);
	      return (-1);
	    }
	}
      tmp = tmp->next;
    }
  return (-1);
}

int		aff_quote_err(t_link *list, char *msg)
{
  if (msg != NULL)
    fprintf(stderr, "Missing \" character in command line : \"%s\"\n\
Command ignored\n\n", msg);
  else
    fprintf(stderr, "Missin \" charachter in command line.\n\
Command ignored\n\n");
  remove_useless_links(list);
  return (-1);
}
