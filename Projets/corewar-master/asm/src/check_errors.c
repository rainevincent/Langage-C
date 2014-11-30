/*
** check_errors.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Mon Apr  7 15:16:14 2014 Jeremy Mediavilla
** Last update Sun Apr 13 12:42:10 2014 Joris Bertomeu
*/

#include "assembleur.h"
#include "gnl.h"

void	init_pofe(void (*which_check[16])(t_system *sys, int *values))
{
  which_check[0] = &live_check_err;
  which_check[1] = &ld_check_err;
  which_check[2] = &st_check_err;
  which_check[3] = &add_check_err;
  which_check[4] = &sub_check_err;
  which_check[5] = &and_check_err;
  which_check[6] = &or_check_err;
  which_check[7] = &xor_check_err;
  which_check[8] = &zjmp_check_err;
  which_check[9] = &ldi_check_err;
  which_check[10] = &sti_check_err;
  which_check[11] = &fork_check_err;
  which_check[12] = &lld_check_err;
  which_check[13] = &lldi_check_err;
  which_check[14] = &lfork_check_err;
  which_check[15] = &aff_check_err;
}

void		check_inst_error(int *values, t_system *sys)
{
  void		(*which_check[16])(t_system *sys, int *values);
  char		*tab;
  int		j;

  tab = init_tab_char();
  init_pofe(which_check);
  j = 0;
  while (j < 16)
    {
      if ((sys->ins.c_save - 1) == tab[j])
	{
	  (*which_check[j + 1])(sys, values);
	  j = 16;
	}
      j++;
    }
  free(tab);
}
