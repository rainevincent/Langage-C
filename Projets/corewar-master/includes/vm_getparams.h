/*
** vm_getparams.h for vm_getparams in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu Apr 10 01:14:27 2014 Geoffrey Merran
** Last update Sat Apr 12 21:30:25 2014 Geoffrey Merran
*/

#ifndef VM_GETPARAMS_
# define VM_GETPARAMS_
# include <stdlib.h>
# include "vm_corewar.h"
# include "vm_arena.h"
# include "my.h"
# include "my_printf.h"

char	**get_params(int nb_args, t_arena *arena, int address);
int    	oct_to_int(char *octet);
void	free_params(char **params, int nb_args);
int    	get_val(char type, char *values, t_arena *arena, t_proc *proc);
int    	get_val_no_idx(char type, char *values, t_arena *arena, t_proc *proc);
char	*get_value_index(int *address, t_arena *arena);
void	write_vm(t_arena *arena, int addr, t_conv reg, int id);
int	get_nb_jump(char *type, int nb_args);
int	is_valid_reg(char type, char value);
int	err_instr(char **params, int nb_args);

#endif /* VM_GETPARAMS_ */
