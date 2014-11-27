/*
** vm_instruction4.c for vm_instruction4.c in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 14:31:16 2014 Geoffrey Merran
** Last update Sun Apr 13 16:30:06 2014 Geoffrey Merran
*/

#include "vm_instruction.h"

int		lfork(t_proc *proc, t_arena *arena)
{
  t_conv	val;
  int		i;
  int		j;
  int		addr;

  i = increase_pc(proc->pc, 1);
  j = 0;
  while (j < 4)
    {
      val.octet[3 - j] = arena->arena[i];
      i = increase_pc(i, 1);
      j++;
    }
  addr = my_mod((proc->pc + val.integer), MEM_SIZE);
  add_proc_vm(proc, addr);
  proc->cycle_dodo = op_tab[14].nbr_cycles;
  return (5);
}

int		aff(t_proc *proc, t_arena *arena)
{
  char		**params;
  int		reg;

  params = get_params(op_tab[15].nbr_args, arena, increase_pc(proc->pc, 1));
  if (!is_valid_reg(params[TYPE_P][0], params[1][0]))
    return (err_instr(params, op_tab[15].nbr_args));
  reg = proc->reg[params[1][0] - 1];
  my_printf("%c\n", my_mod(reg, 256));
  free_params(params, op_tab[15].nbr_args);
  proc->cycle_dodo = op_tab[15].nbr_cycles;
  return (1);
}

void		live_champ(t_proc *proc, t_champ **champ)
{
  t_champ	*tmp;

  tmp = *champ;
  while (tmp != NULL)
    {
      if (proc->alive == tmp->id)
	{
	  my_printf("Player %s is alive\n", tmp->header.prog_name);
	  tmp->live = 1;
	}
      tmp = tmp->next;
    }
}
