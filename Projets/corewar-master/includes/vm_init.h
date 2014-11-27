/*
** vm_init.h for vm_init in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri Mar 28 16:04:33 2014 Geoffrey Merran
** Last update Tue Apr  8 23:18:26 2014 Geoffrey Merran
*/

#ifndef VM_INIT_
# define VM_INIT_
# include <stdlib.h>
# include "vm_corewar.h"
# include "xfunction.h"
# include "vm_getchamp.h"
# include "my.h"

void   	init_id(t_champ **champs);
int    	is_id_possible(t_champ *champs, int id);
void	init_cycle(t_cycles *cycles);
void	init_arena(t_arena *arena);
void   	init_addr(t_champ **champs);

#endif /* VM_INIT_ */
