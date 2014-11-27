/*
** vm_checkval.c for checkval in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu Apr 10 22:17:28 2014 Geoffrey Merran
** Last update Sun Apr 13 16:38:38 2014 Geoffrey Merran
*/

#include "vm_getparams.h"

int	is_valid_reg(char type, char value)
{
  if (type != A_REG)
    return (0);
  if (value >= 1 && value <= 16)
    return (1);
  return (0);
}

int	err_instr(char **params, int nb_args)
{
  free_params(params, nb_args);
  return (1);
}

int		oct_to_int(char *octet)
{
  t_conv	val;
  int		i;

  i = 0;
  while (i < 4)
    {
      val.octet[3 - i] = octet[i];
      i++;
    }
  return (val.integer);
}

int		get_val(char type, char *values, t_arena *arena, t_proc *proc)
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
	  addr = my_mod((proc->pc + (val.integer % IDX_MOD)), MEM_SIZE);
	  ind_val = get_value_index(&addr, arena);
	  val.integer = oct_to_int(ind_val);
	}
    }
  return (val.integer);
}

void	write_vm(t_arena *arena, int addr, t_conv reg, int id)
{
  int	i;

  i = 0;
  while (i < 4)
    {
      arena->arena[my_mod((addr + i), MEM_SIZE)] = reg.octet[3 - i];
      arena->color[my_mod((addr + i), MEM_SIZE)] = id;
      i++;
    }
}
