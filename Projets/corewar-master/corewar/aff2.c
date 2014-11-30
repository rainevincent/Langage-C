/*
** aff2.c for aff in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Apr  9 18:30:36 2014 Geoffrey Merran
** Last update Sat Apr 12 01:41:05 2014 Geoffrey Merran
*/

#include "aff.h"

void		init_sdl_header(t_win *win)
{
  aff_text_sdl(26, 30, "Current Cycle : ", win);
  aff_text_sdl(750, 30, "Cycle to die : ", win);
  aff_text_sdl(26, 60, "Processus : ", win);
}

void		init_color(t_win *win, t_champ *champ)
{
  t_champ	*tmp;
  int		c;
  Uint32	color[4];

  color[0] = SDL_MapRGB(win->screen->format, 255, 0, 0);
  color[1] = SDL_MapRGB(win->screen->format, 0, 0, 255);
  color[2] = SDL_MapRGB(win->screen->format, 0, 255, 0);
  color[3] = SDL_MapRGB(win->screen->format, 205, 173, 0);
  c = 0;
  tmp = champ;
  while (tmp)
    {
      tmp->color = color[c++];
      tmp = tmp->next;
    }
}

void		aff_nb_sdl(int x, int y, int nb, t_win *win)
{
  SDL_Surface	*text;
  SDL_Rect	pos;
  char		*t;

  pos.x = x;
  pos.y = y;
  t = int_to_str(nb);
  text = TTF_RenderText_Solid(win->police, t, win->color);
  SDL_BlitSurface(text, NULL, win->screen, &pos);
  SDL_FreeSurface(text);
  free(t);
}

void		aff_text_sdl(int x, int y, char *str, t_win *win)
{
  SDL_Surface	*text;
  SDL_Rect	pos;

  pos.x = x;
  pos.y = y;
  text = TTF_RenderText_Solid(win->police, str, win->color);
  SDL_BlitSurface(text, NULL, win->screen, &pos);
  SDL_FreeSurface(text);
}

void		aff_champions(t_win *win, t_champ *champs)
{
  t_champ	*tmp;
  int		y;

  y = 30;
  tmp = champs;
  while (tmp)
    {
      aff_color_champ(420, y - 3, win, tmp);
      aff_text_sdl(450, y, tmp->header.prog_name, win);
      if (tmp->id < 10 && tmp->id >= 0)
	aff_nb_sdl(423, y, tmp->id, win);
      tmp = tmp->next;
      y = y + 30;
    }
}
