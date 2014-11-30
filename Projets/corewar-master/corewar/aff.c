/*
** aff.c for aff in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 19:31:35 2014 Geoffrey Merran
** Last update Sun Apr 13 18:22:51 2014 Geoffrey Merran
*/

#include "aff.h"

void	init_window(t_win *win)
{
  xSDL_Init(SDL_INIT_VIDEO);
  xTTF_Init();
  win->screen = xSDL_SetVideoMode(SIZE_X, SIZE_Y, 32, SDL_HWSURFACE);
  xMix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
  SDL_WM_SetCaption("MABM Corewar", NULL);
  win->police = xTTF_OpenFont("/tmp/imagine_font.ttf", 20);
  win->color.r = 255;
  win->color.g = 255;
  win->color.b = 255;
  win->music = xMix_LoadMUS("/tmp/derezzed.wav");
  Mix_PlayMusic(win->music, -1);
  init_sdl_header(win);
}

Uint32		get_case_color(t_arena *arena, int address,
			       t_fighter *fighters, t_win *win)
{
  t_proc	*tmp;
  t_champ	*tmp_ch;

  tmp = fighters->procs;
  while (tmp)
    {
      if (address == tmp->pc)
	return (SDL_MapRGB(win->screen->format, 0, 255, 255));
      tmp = tmp->next;
    }
  tmp_ch = fighters->champs;
  while (tmp_ch)
    {
      if (arena->color[address] == tmp_ch->id)
	return (tmp_ch->color);
      tmp_ch = tmp_ch->next;
    }
  return (SDL_MapRGB(win->screen->format, 20, 20, 20));
}

void		reset_pos(t_win *win)
{
  SDL_Rect	*pos;

  pos = my_xmalloc(sizeof(*pos));
  pos->x = 227;
  pos->y = 30;
  pos->w = 100;
  pos->h = 25;
  SDL_FillRect(win->screen, pos, SDL_MapRGB(win->screen->format, 0, 0, 0));
  pos->x = 917;
  pos->y = 30;
  SDL_FillRect(win->screen, pos, SDL_MapRGB(win->screen->format, 0, 0, 0));
  pos->x = 180;
  pos->y = 60;
  SDL_FillRect(win->screen, pos, SDL_MapRGB(win->screen->format, 0, 0, 0));
  free(pos);
}

void		aff_window(t_win *win, t_arena *arena,
			   t_fighter *fighters, t_cycles *cycles)
{
  reset_pos(win);
  aff_nb_sdl(227, 30, cycles->current_cycle, win);
  aff_nb_sdl(917, 30, cycles->cycle_to_die, win);
  aff_nb_sdl(180, 60, get_nb_proc(fighters->procs), win);
  aff_arena(win, arena, fighters);
  SDL_Flip(win->screen);
}

void		aff_arena(t_win *win, t_arena *arena, t_fighter *fighters)
{
  int		i;
  SDL_Rect	*pos;

  i = 0;
  pos = my_xmalloc(sizeof(*pos));
  pos->x = 26;
  pos->y = 200;
  pos->w = PLOT_W;
  pos->h = PLOT_H;
  while (i < MEM_SIZE)
    {
      SDL_FillRect(win->screen, pos, get_case_color(arena, i, fighters, win));
      pos->x += pos->w + SEP_W;
      if (pos->x >= SIZE_X - 26)
	{
	  pos->x = 26;
	  pos->y += pos->h + SEP_H;
	}
      i++;
    }
  free(pos);
}
