/*
** sdl_xfunction.h for sdl_xfunction in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 17:30:00 2014 Geoffrey Merran
** Last update Sun Apr 13 17:35:24 2014 Geoffrey Merran
*/

#ifndef SDL_XFUNCTION_
# define SDL_XFUNCTION_
# include <SDL/SDL.h>
# include <SDL/SDL_ttf.h>
# include <SDL/SDL_mixer.h>
# include "xfunction.h"

typedef struct	s_win
{
  SDL_Surface	*screen;
  TTF_Font	*police;
  SDL_Color	color;
  Mix_Music	*music;
}		t_win;

void		xSDL_Init(Uint32 flags);
void		xTTF_Init();
void		xMix_OpenAudio(int frequency, Uint16 format,
			       int channels, int chunksize);
TTF_Font	*xTTF_OpenFont(char *path, int size);
Mix_Music	*xMix_LoadMUS(char *path);
SDL_Surface	*xSDL_SetVideoMode(int width, int height, int bpp, Uint32 flags);

#endif /* SDL_XFUNCTION_ */
