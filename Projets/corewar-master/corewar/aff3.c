/*
** aff3.c for aff3 in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Apr  9 23:02:55 2014 Geoffrey Merran
** Last update Sun Apr 13 20:16:35 2014 Geoffrey Merran
*/

#include "aff.h"

void		aff_color_champ(int x, int y, t_win *win, t_champ *champ)
{
  SDL_Rect	*pos;

  pos = my_xmalloc(sizeof(*pos));
  pos->x = x;
  pos->y = y;
  pos->w = 20;
  pos->h = 20;
  SDL_FillRect(win->screen, pos, champ->color);
  free(pos);
}

void		clean_arena(t_win *win)
{
  SDL_Rect	*pos;

  pos = my_xmalloc(sizeof(*pos));
  pos->x = 0;
  pos->y = 200;
  pos->w = SIZE_X;
  pos->h = 520;
  SDL_FillRect(win->screen, pos, SDL_MapRGB(win->screen->format, 0, 0, 0));
  free(pos);
}

void		wait_enter()
{
  int		end;
  SDL_Event	event;

  end = 1;
  while (end)
    {
      SDL_WaitEvent(&event);
      if (event.key.keysym.sym == SDLK_ESCAPE)
	end = 0;
    }
}

void		aff_who(t_champ *tmp, int win_c, int y, t_win *win)
{
  aff_text_sdl(520, y, "Player n'", win);
  aff_nb_sdl(640, y, tmp->id, win);
  if (win_c == 1)
    aff_text_sdl(670, y, "won !", win);
  else
    aff_text_sdl(670, y, "is alive !", win);
}

void		aff_winner(t_champ *champ, t_win *win)
{
  t_champ	*tmp;
  int		win_c;
  int		y;

  clean_arena(win);
  win_c = nb_champ_alive(champ);
  tmp = champ;
  y = 360;
  while (tmp)
    {
      if (tmp->live != 0)
	aff_who(tmp, win_c, y, win);
      y = y + 30;
      tmp = tmp->next;
    }
  if (win_c == 0)
    aff_text_sdl(520, y, "Nobody is alive", win);
  SDL_Flip(win->screen);
  wait_enter();
}
