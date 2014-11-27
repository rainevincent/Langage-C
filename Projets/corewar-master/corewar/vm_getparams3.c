/*
** vm_getparams3.c for vm_getparams in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri Apr 11 00:16:23 2014 Geoffrey Merran
** Last update Sun Apr 13 16:38:52 2014 Geoffrey Merran
*/

#include "vm_getparams.h"

int	get_nb_jump(char *type, int nb_args)
{
  int	i;
  int	jump;

  i = 0;
  jump = 0;
  while (i < nb_args)
    {
      if (type[i] == A_REG)
	jump += 1;
      if (type[i] == A_DIR || type[i] == A_IND)
	jump += 4;
      i++;
    }
  return (jump);
}

int		get_val_no_idx(char type, char *values, t_arena *arena, t_proc *proc)
{
  t_conv	val;
  char		*ind_val;
  int		addr;

  val.integer = 0;
  if (type == A_REG)
    {
      if (is_valid_reg(type, values[0]))
	val.integer = proc->reg[values[0] - 1];
      else
	val.integer = 0;
    }
  if (type == A_DIR || type == A_IND)
    {
      val.integer = oct_to_int(values);
      if (type == A_IND)
	{
	  addr = my_mod((proc->pc + val.integer), MEM_SIZE);
	  ind_val = get_value_index(&addr, arena);
	  val.integer = oct_to_int(ind_val);
	}
    }
  return (val.integer);
}
