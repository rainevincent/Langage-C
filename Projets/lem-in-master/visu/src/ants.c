/*
** ants.c for visu in /home/jobertomeu/Work/lemin/visu
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun May  4 12:26:52 2014 Joris Bertomeu
** Last update Sun May  4 19:58:15 2014 Joris Bertomeu
*/

#include "visu.h"

void	update_all(char *name, char *room, t_system *sys)
{
  del_ant_in_room(name, sys, room);
  add_ant_in_room(name, room, sys);
  update_screen(sys);
}

void	ants_path(char *str, t_system *sys, int i, int j)
{
  char	name[4096];
  char	room[4096];

  while (str[i])
    {
      j = 0;
      if (str[i] == 'P')
	{
	  i++;
	  while (str[i] != '-')
	    name[j++] = str[i++];
	  name[j] = 0;
	  if (str[i] == '-')
	    {
	      i++;
	      j = 0;
	      while (str[i] != ' ' && str[i])
		room[j++] = str[i++];
	      room[j] = 0;
	    }
	  update_all(name, room, sys);
	}
      i++;
    }
  sys->tour++;
}

void	set_property_ants_all(int total, t_system *sys, char *name)
{
  int	i;

  i = 0;
  while (i < total)
    {
      sys->ants[i].name = xmalloc(512 * sizeof(char));
      sprintf(sys->ants[i].name, "%d", i + 1);
      sys->ants[i].box = xmalloc(512 * sizeof(char));
      sprintf(sys->ants[i].box, "%s", name);
      i++;
    }
}

void	put_ants_room(t_system *sys, int nbr)
{
  int	i;

  i = 0;
  while (i < 512)
    {
      if (sys->element[i].name != NULL)
	{
	  if (sys->element[i].nbr_ants == nbr)
	    {
	      set_property_ants_all(sys->element[i].nbr_ants, sys,
				    sys->element[i].name);
	    }
	}
      i++;
    }
}
