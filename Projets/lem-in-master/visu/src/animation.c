/*
** animation.c for visu in /home/jobertomeu/Work/lemin/visu
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun May  4 12:26:13 2014 Joris Bertomeu
** Last update Sun May  4 19:57:01 2014 Joris Bertomeu
*/

#include "visu.h"

void		update_screen(t_system *sys)
{
  SDL_Rect	pos;

  pos.x = 0;
  pos.y = 0;
  SDL_FillRect(sys->screen, NULL, convert_color(0, 0, 0));
  SDL_BlitSurface(sys->map, NULL, sys->screen, &pos);
  write_nbr_tour(sys);
  write_info_all(sys);
}

void		put_ant_screen(int x, int y, t_system *sys)
{
  SDL_Rect	pos;
  SDL_Surface	*ant;
  SDL_Surface	*tmp;

  pos.x = x;
  pos.y = y;
  tmp = IMG_Load("img/ant.png");
  ant = rotozoomSurface(tmp, -45, 0.5, 1);
  SDL_BlitSurface(ant, NULL, sys->screen, &pos);
  SDL_Flip(sys->screen);
  free(tmp);
  free(ant);
}

void	anim_ant(int id_room_start, int id_room_end, t_system *sys)
{
  update_screen(sys);
  put_ant_screen(sys->element[id_room_start].x,
		 sys->element[id_room_start].y, sys);
  usleep(sys->speed);
  update_screen(sys);
  put_ant_screen(((sys->element[id_room_start].x) +
		  (sys->element[id_room_end].x)) / 2 ,
		 (sys->element[id_room_start].y +
		  sys->element[id_room_end].y) / 2 - 20, sys);
  usleep(sys->speed);
  update_screen(sys);
  put_ant_screen(sys->element[id_room_end].x,
		 sys->element[id_room_end].y, sys);
  usleep(sys->speed);
  update_screen(sys);
  SDL_Flip(sys->screen);
}

void	del_ant_in_room(char *name, t_system *sys, char *room)
{
  int	id;
  int	id_room;
  int	id_room_target;

  id = sort_id_ant(sys, name);
  id_room_target = sort_id(sys, room);
  id_room = sort_id(sys, sys->ants[id].box);
  sys->element[id_room].nbr_ants -= 1;
  printf("Ant named %s leaves %s room ( it stay %d ant(s) )\n",
  	 sys->ants[id].name, sys->element[id_room].name,
  	 sys->element[id_room].nbr_ants);
  anim_ant(id_room, id_room_target, sys);
}

void	add_ant_in_room(char *name, char *room, t_system *sys)
{
  int	id;
  int	id_room;

  id_room = sort_id(sys, room);
  id = sort_id_ant(sys, name);
  sprintf(sys->ants[id].box, "%s", room);
  sys->element[id_room].nbr_ants += 1;
  printf("Ant named %s goes to %s room ( There is %d ant(s) in this room )\n\n",
  	 sys->ants[id].name, sys->element[id_room].name,
  	 sys->element[id_room].nbr_ants);
  update_screen(sys);
  SDL_Flip(sys->screen);
}
