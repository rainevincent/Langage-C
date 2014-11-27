/*
** vm_proc.h for vm_proc in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Mon Apr  7 13:27:30 2014 Geoffrey Merran
** Last update Sat Apr 12 00:55:57 2014 Geoffrey Merran
*/

#ifndef VM_PROC_
# define VM_PROC_
# include <stdlib.h>
# include "vm_corewar.h"
# include "my.h"

void   	add_proc(t_proc **proc, t_champ *champ);
t_proc	*del_proc(t_proc *proc, t_proc **start);
void	init_proc(t_proc **proc, t_champ *champ);
int    	get_nb_proc(t_proc *proc);
void   	add_proc_vm(t_proc *proc, int addr);

#endif /* VM_PROC_ */
