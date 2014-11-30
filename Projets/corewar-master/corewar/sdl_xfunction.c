/*
** sdl_xfunction.c for sdl_xfunction in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 17:31:44 2014 Geoffrey Merran
** Last update Sun Apr 13 17:26:50 2014 Geoffrey Merran
*/

#include "sdl_xfunction.h"

void	xSDL_Init(Uint32 flags)
{
  if (SDL_Init(flags) == -1)
    my_error("SDL error : init fail\n");
}

void	xTTF_Init()
{
  if (TTF_Init() == -1)
    my_error("SDL TTf error : init fail\n");
}

SDL_Surface	*xSDL_SetVideoMode(int width, int height, int bpp, Uint32 flags)
{
  SDL_Surface	*screen;

  if ((screen = SDL_SetVideoMode(width, height, bpp, flags)) == NULL)
    my_error("SDL error : Setvideomode fail\n");
  return (screen);
}

TTF_Font	*xTTF_OpenFont(char *path, int size)
{
  TTF_Font	*police;

  police = TTF_OpenFont(path, size);
  if (police == NULL)
    my_error("SDL TTf error : couldn't load font\n");
  return (police);
}

void		xMix_OpenAudio(int frequency, Uint16 format,
			       int channels, int chunksize)
{
  if (Mix_OpenAudio(frequency, format, channels, chunksize) == -1)
    my_error("SDL Mixer error : init fail\n");
}
