/*
** write_f.c for visu in /home/jobertomeu/Work/lemin/visu
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun May  4 12:22:10 2014 Joris Bertomeu
** Last update Sun May  4 20:00:27 2014 Joris Bertomeu
*/

#include "visu.h"

void		write_nbr_tour(t_system *sys)
{
  SDL_Rect	pos;
  SDL_Surface	*txt;
  char		final[4096];
  SDL_Color	color;

  sprintf(final, "Tour : %d", sys->tour);
  set_color(&color, 0, 255, 255);
  txt = TTF_RenderText_Blended(sys->font, final, color);
  pos.x = 10;
  pos.y = 10;
  SDL_BlitSurface(txt, NULL, sys->screen, &pos);
  free(txt);
}

void		write_info(char *name_box, int x, int y, t_system *sys)
{
  SDL_Rect	pos;
  SDL_Surface	*txt;
  char		final[4096];
  int		id;
  SDL_Color	color;

  id = sort_id(sys, name_box);
  set_color(&color, 255, 0, 0);
  if (sys->element[id].func == 1)
    sprintf(final, "[%s] %d ants - START", name_box,
  	    sys->element[id].nbr_ants);
  else if (sys->element[id].func == 2)
    sprintf(final, "[%s] %d ants - END", name_box, sys->element[id].nbr_ants);
  else
    sprintf(final, "[%s] %d ants", name_box, sys->element[id].nbr_ants);
  txt = TTF_RenderText_Blended(sys->font, final, color);
  pos.x = x;
  pos.y = y - 30;
  SDL_BlitSurface(txt, NULL, sys->screen, &pos);
  free(txt);
}

void		place_box(char *name_box, int x, int y, t_system *sys)
{
  SDL_Rect	pos;
  SDL_Surface	*box;

  pos.x = x;
  pos.y = y;
  sys->nbr = 0;
  write_info(name_box, x, y, sys);
  box = IMG_Load("img/house.png");
  SDL_BlitSurface(box, NULL, sys->map, &pos);
  free(box);
}

void	init_t_pos(t_coor *pos1, t_coor *pos2)
{
  init_coor(pos1);
  init_coor(pos2);
}

void	grep_coor(int i, t_coor *pos, t_system *sys)
{
  pos->x = sys->element[i].x;
  pos->y = sys->element[i].y;
}
