/*
** my_free.c for my_free in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Mon Apr  7 10:19:02 2014 Geoffrey Merran
** Last update Sun Apr 13 17:39:52 2014 Geoffrey Merran
*/

#include "my_free.h"

void		free_champ(t_champ **champs)
{
  t_champ	*tmp;

  while (*champs)
    {
      tmp = (*champs)->next;
      free(*champs);
      *champs = tmp;
    }
}

void		free_proc(t_proc **proc)
{
  t_proc	*tmp;

  while (*proc)
    {
      tmp = (*proc)->next;
      free(*proc);
      *proc = tmp;
    }
}

void		free_battle(inst *instruction, t_win *win, t_proc **proc)
{
  free_proc(proc);
  TTF_CloseFont(win->police);
  Mix_FreeMusic(win->music);
  TTF_Quit();
  Mix_CloseAudio();
  SDL_Quit();
  free(instruction);
}
