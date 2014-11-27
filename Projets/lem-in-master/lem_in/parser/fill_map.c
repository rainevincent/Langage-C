/*
** fill_map.c for fillmap in /home/merran_g/work/c_elem/lem-in/lem_in/parser
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri Apr 25 16:01:08 2014 Geoffrey Merran
** Last update Sun May  4 18:01:26 2014 Geoffrey Merran
*/

#include "parser.h"

void	get_nb_ants(char **tab, int *step, t_map *map)
{
  if (!my_str_isnum(tab[0]))
    {
      fprintf(stderr, "Non decimal value non-allowed : %s\n", tab[0]);
      exit(EXIT_FAILURE);
    }
  else
    {
      if (*step != 0)
	my_error("Invalid syntax : check how to build a map\n");
      map->nb_ants = atoi(tab[0]);
      if (map->nb_ants < 0)
	my_error("Invalid ants : negative value\n");
      *step = 1;
      printf("%s\n", tab[0]);
    }
}

void	get_room(char **tab, int *step, t_map *map)
{
  if (is_valid_room_name(tab[0]))
    {
      if (my_str_isnum(tab[1]) && my_str_isnum(tab[2]))
	{
	  if (!is_existing_room(tab[0], map->head))
	    {
	      if (*step == 1 || *step == 2)
		{
		  add_room(tab, map);
		  *step = 2;
		}
	      else
		my_error("Invalid syntax : check how to build a map\n");
	    }
	  else
	    my_error("Invalid room name : room already added\n");
	}
      else
	my_error("Invalid position : only decimal number allowed\n");
    }
  else
    my_error("Invalid room name (only alphanumeric and not P[number]\n");
}

void	get_access(char **tab, int *step, t_map *map)
{
  if (*step == 2 || *step == 3)
    {
      if (is_existing_room(tab[0], map->head) &&
	  is_existing_room(tab[1], map->head))
	{
	  if (strcmp(tab[0], tab[1]) == 0)
	    my_puterr("Warning : Room has a circular access -> ");
	  else if (is_access_to(tab[0], tab[1], map) ||
	      is_access_to(tab[1], tab[0], map))
	    my_puterr("Warning : Rooms already to access eachothers -> ");
	  else
	    {
	      give_access(tab[0], tab[1], map);
	      give_access(tab[1], tab[0], map);
	    }
	}
      else
	my_error("Invalid rooms names : they don't exist\n");
      *step = 3;
    }
  else
    my_error("Invalid syntax : check how to build a map\n");
}

int	get_command(int command, int step, t_map *map)
{
  if (command == 1)
    return (3);
  if (command == 2)
    return (4);
  if (command == 3)
    get_start(step, map);
  if (command == 4)
    get_end(step, map);
  return (0);
}
