/*
** init.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:07:56 2014 Jeremy Mediavilla
** Last update Sun Apr 13 15:06:40 2014 Jeremy Mediavilla
*/

#include "assembleur.h"
#include "gnl.h"

char		**init_tab()
{
  char		**tab;

  tab = xmalloc(17 * sizeof(char *));
  tab[0] = "st";
  tab[1] = "and";
  tab[2] = "ld";
  tab[3] = "live";
  tab[4] = "zjmp";
  tab[5] = "sti";
  tab[6] = "add";
  tab[7] = "sub";
  tab[8] = "or";
  tab[9] = "xor";
  tab[10] = "ldi";
  tab[11] = "fork";
  tab[12] = "lld";
  tab[13] = "lldi";
  tab[14] = "lfork";
  tab[15] = "aff";
  tab[16] = NULL;
  return (tab);
}

void	init_start(t_system *system)
{
  system->f_c = 0;
  system->f_n = 0;
  system->wm = 0;
  system->cl = 0;
  system->col = 0;
  system->ins.c = 0;
  system->ins.i = 0;
  system->ins.ibase = 0;
  system->ins.ret_chck = 0;
  system->ins.cmptr = 0;
  system->name_file = xmalloc(256 * sizeof(*system->name));
  system->ret_gnl = xmalloc(4096 * sizeof(char));
}
