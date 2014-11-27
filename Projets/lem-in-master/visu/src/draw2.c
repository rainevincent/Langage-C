/*
** draw2.c for visu in /home/jobertomeu/Work/lemin/visu
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun May  4 12:24:32 2014 Joris Bertomeu
** Last update Sun May  4 16:07:57 2014 Jeremy Mediavilla
*/

#include "visu.h"

void	check_nbr_box(t_system *sys)
{
  if (sys->nbr_box >= 511)
    {
      exit (0);
      printf("Error : Number maximum of box must be inferior at 512\n");
    }
  else
    sys->nbr_box++;
}

void		parse_decl(char *str, t_system *sys, int func, int cmptr)
{
  char		name[4096];
  t_coor	*pos;
  t_coor	*pos2;

  pos = xmalloc(sizeof(t_coor));
  pos2 = xmalloc(sizeof(t_coor));
  init_t_pos(pos, pos2);
  while (str[pos2->x])
    {
      if (str[pos2->x] == ' ')
    	cmptr++;
      else if (str[pos2->x] >= '0' && str[pos2->x] <= '9')
    	if (cmptr == 1)
    	  pos->x = pos->x * 10 + (str[pos2->x] - '0');
    	else if (cmptr == 2)
    	  pos->y = pos->y * 10 + (str[pos2->x] - '0');
    	else
    	  name[pos2->y++] = str[pos2->x];
      else
	name[pos2->y++] = str[pos2->x];
      pos2->x++;
    }
  name[pos2->y] = 0;
  check_nbr_box(sys);
  save_box(name, pos, sys, func);
}

void		ml(SDL_Surface* surf, t_coor *pos1, t_coor *pos2)
{
  int		Dx;
  int		Dy;
  t_coor	incr;

  Dx = abs(pos2->x - pos1->x);
  Dy = abs(pos2->y - pos1->y);
  if (pos1->x < pos2->x)
    incr.x = 1;
  else
    incr.x = -1;
  if (pos1->y < pos2->y)
    incr.y = 1;
  else
    incr.y = -1;
  if (Dx > Dy)
    step1(pos1, pos2, incr, surf);
  else
    step2(pos1, pos2, incr, surf);
}

void	draw_line(t_coor *pos1, t_coor *pos2, t_system *sys)
{
  ml(sys->map, pos1, pos2);
}

void	draw_tunel(char *name1, char *name2, t_system *sys)
{
  int		i;
  t_coor	*pos1;
  t_coor	*pos2;

  pos1 = xmalloc(sizeof(t_coor));
  init_coor(pos1);
  pos2 = xmalloc(sizeof(t_coor));
  init_coor(pos2);
  i = 0;
  while (i < 512)
    {
      if (sys->element[i].name != NULL)
      	{
      	  if (strcmp(sys->element[i].name, name1) == 0)
	    grep_coor(i, pos1, sys);
      	  else if (strcmp(sys->element[i].name, name2) == 0)
      	    grep_coor(i, pos2, sys);
      	}
      i++;
    }
  draw_line(pos1, pos2, sys);
  place_box(name1, pos1->x, pos1->y, sys);
  place_box(name2, pos2->x, pos2->y, sys);
  free(pos1);
  free(pos2);
}
