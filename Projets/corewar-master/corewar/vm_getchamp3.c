/*
** vm_getchamp3.c for vm_getchamp3 in /home/merran_g/work/c_elem/corewar/corewar
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun Apr 13 17:08:58 2014 Geoffrey Merran
** Last update Sun Apr 13 17:13:41 2014 Geoffrey Merran
*/

#include "vm_getchamp.h"

int		nb_champ_alive(t_champ *champ)
{
  int		i;
  t_champ	*tmp;

  i = 0;
  tmp = champ;
  while (tmp)
    {
      if (tmp->live != 0)
	i++;
      tmp = tmp->next;
    }
  return (i);
}
