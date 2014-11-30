/*
** visu.h for Visu in /home/jobertomeu/Work/lemin/visu
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Apr 30 15:50:26 2014 Joris Bertomeu
** Last update Sun May  4 20:02:21 2014 Joris Bertomeu
*/

#ifndef VISU_H
# define VISU_H
# define _BSD_SOURCE
# define HEIGHT 768
# define WIDTH 1024

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <SDL/SDL.h>
# include <stdlib.h>
# include <SDL/SDL_ttf.h>
# include <SDL/SDL_image.h>
# include <SDL/SDL_rotozoom.h>
# include "gnl.h"

typedef struct s_elm t_elm;
struct s_elm
{
  int	x;
  int	y;
  char	*name;
  int	func;
  int	nbr_ants;
};

typedef struct s_coor t_coor;
struct s_coor
{
  int	x;
  int	y;
};

typedef struct s_ants t_ants;
struct s_ants
{
  char	*name;
  char	*box;
};

typedef struct s_system t_system;
struct s_system
{
  int		current;
  t_elm		element[512];
  SDL_Surface	*screen;
  SDL_Surface	*map;
  int		nbr;
  int		nbr_box;
  int		nbr_fourm;
  int		nbr_ants;
  t_coor	pos;
  t_ants	ants[1024];
  TTF_Font	*font;
  int		tour;
  int		func;
  int		speed;
};

void		write_nbr_tour(t_system *sys);
void		write_info(char *name_box, int x, int y, t_system *sys);
void		place_box(char *name_box, int x, int y, t_system *sys);
void		init_t_pos(t_coor *pos1, t_coor *pos2);
void		grep_coor(int i, t_coor *pos, t_system *sys);
int		sort_id(t_system *sys, char *name);
void		printe(char *str);
void		check_nbr_ants(char *str, t_system *sys);
int		sort_id_ant(t_system *sys, char *name);
void		set_color(SDL_Color *color, int r, int g, int b);
void		save_box(char *name, t_coor *pos, t_system *sys, int func);
void		init_coor(t_coor *pos);
void		do_op(t_coor *pos1, t_system *sys, int i);
void		redraw_pipe(t_system *sys);
void		write_info_all(t_system *sys);
void		parse(t_system *sys);
void		tread_line(char *str, t_system *sys);
void		decision(t_coor flag, t_coor pos, char *str, t_system *sys);
void		parse_path(char *str, t_system *sys);
void		parse_pipe(char *str, t_system *sys, int i, int j);
void		*xmalloc(int sz);
void		swapint(int *x, int *y);
void		PutPixel(SDL_Surface *surface, int x, int y, unsigned long pixel);
void		step2(t_coor *pos1, t_coor *pos2, t_coor incr, SDL_Surface *surf);
void		step1(t_coor *pos1, t_coor *pos2, t_coor incr, SDL_Surface *surf);
void		parse_decl(char *str, t_system *sys, int func, int cmptr);
void		ml(SDL_Surface* surf, t_coor *pos1, t_coor *pos2);
void		draw_line(t_coor *pos1, t_coor *pos2, t_system *sys);
void		draw_tunel(char *name1, char *name2, t_system *sys);
void		update_all(char *name, char *room, t_system *sys);
unsigned long	convert_color(int R, int G, int B);
void		ants_path(char *str, t_system *sys, int i, int j);
void		set_property_ants_all(int total, t_system *sys, char *name);
void		put_ants_room(t_system *sys, int nbr);
void		put_ants_room(t_system *sys, int nbr);
void		update_screen(t_system *sys);
void		put_ant_screen(int x, int y, t_system *sys);
void		anim_ant(int id_room_start, int id_room_end, t_system *sys);
void		del_ant_in_room(char *name, t_system *sys, char *room);
void		add_ant_in_room(char *name, char *room, t_system *sys);

#endif /* VISU_H */
