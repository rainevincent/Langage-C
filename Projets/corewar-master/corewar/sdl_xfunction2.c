/*
** sdl_xfunction2.c for sdl_function in /home/merran_g/work/c_elem/corewar/corewar
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun Apr 13 17:35:38 2014 Geoffrey Merran
** Last update Sun Apr 13 18:18:52 2014 Geoffrey Merran
*/

#include "sdl_xfunction.h"

Mix_Music	*xMix_LoadMUS(char *path)
{
  Mix_Music	*music;

  music = Mix_LoadMUS(path);
  if (music == NULL)
    my_error(Mix_GetError());
  return (music);
}
