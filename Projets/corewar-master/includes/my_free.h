/*
** my_free.h for my_free in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Mon Apr  7 10:19:47 2014 Geoffrey Merran
** Last update Wed Apr  9 22:31:58 2014 Geoffrey Merran
*/

#ifndef MY_FREE
# define MY_FREE
# include <stdlib.h>
# include "vm_corewar.h"
# include "sdl_xfunction.h"

void	free_champ(t_champ **champs);
void   	free_proc(t_proc **proc);
void   	free_battle(inst *instruction, t_win *win, t_proc **proc);

#endif /* MY_FREE */
