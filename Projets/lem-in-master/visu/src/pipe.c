/*
** pipe.c for visu in /home/jobertomeu/Work/lemin/visu
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun May  4 12:25:43 2014 Joris Bertomeu
** Last update Sun May  4 16:09:06 2014 Jeremy Mediavilla
*/

#include "visu.h"

void		do_op(t_coor *pos1, t_system *sys, int i)
{
  int		j;
  t_coor	*pos2;

  j = 0;
  pos2 = xmalloc(sizeof(*pos2));
  while (j < 512)
    {
      if (sys->element[j].name != NULL)
	{
	  if (strcmp(sys->element[i].name, sys->element[j].name) != 0)
	    {
	      pos2->x = sys->element[j].x;
	      pos2->y = sys->element[j].y;
	      draw_line(pos1, pos2, sys);
	    }
	}
      j++;
    }
  free(pos2);
}

void	redraw_pipe(t_system *sys)
{
  int		i;
  t_coor	*pos1;

  pos1 = xmalloc(sizeof(*pos1));
  i = 0;
  while (i < 512)
    {
      if (sys->element[i].name != NULL)
	{
	  pos1->x = sys->element[i].x;
	  pos1->y = sys->element[i].y;
	  do_op(pos1, sys, i);
	}
      i++;
    }
  free(pos1);
}

void	write_info_all(t_system *sys)
{
  int	i;

  i = 0;
  while (i < 512)
    {
      if (sys->element[i].name != NULL)
	write_info(sys->element[i].name, sys->element[i].x,
		   sys->element[i].y, sys);
      i++;
    }
}
