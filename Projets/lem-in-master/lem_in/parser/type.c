/*
** type.c for type in /home/merran_g/work/c_elem/lem-in/lem_in/parser
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri Apr 25 16:00:00 2014 Geoffrey Merran
** Last update Fri May  2 19:05:28 2014 Geoffrey Merran
*/

#include "parser.h"

int	is_command(char *buffer)
{
  if (strncmp(buffer, "##", 2) == 0)
    return (1);
  return (0);
}

int	is_commentary(char *buffer)
{
  if (buffer[0] == '#')
    return (1);
  return (0);
}

int	is_valid_room_name(char *str)
{
  int	i;

  if (!my_str_isalpha(str))
    return (0);
  if (str[0] == 'P')
    {
      if (strlen(str) > 1)
	{
	  i = 0;
	  while (str[++i])
	    {
	      if (!my_isdigit(str[i]))
		return (1);
	    }
	}
      return (0);
    }
  return (1);
}

int		is_existing_room(char *new, t_room *list)
{
  t_room	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (strcmp(tmp->name, new) == 0)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

int	get_line_type(char *buffer)
{
  if (is_command(buffer))
    return (COMMAND_TYPE);
  if (is_commentary(buffer))
    return (COMMENTARY_TYPE);
  return (OTHER_TYPE);
}
