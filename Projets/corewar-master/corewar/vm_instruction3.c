/*
** vm_instruction3.c for vm_instruction3 in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 14:29:40 2014 Geoffrey Merran
** Last update Sat Apr 12 23:02:58 2014 Geoffrey Merran
*/

#include "vm_instruction.h"

int		ldi(t_proc *proc, t_arena *arena)
{
  char		**params;
  int		jump;
  int		addr;
  t_conv	val;
  int		j;

  params = get_params(op_tab[9].nbr_args, arena, increase_pc(proc->pc, 1));
  if (!is_valid_reg(params[TYPE_P][2], params[3][0])
      || is_valid_reg(params[TYPE_P][1], params[2][0])
      || is_valid_reg(params[TYPE_P][0], params[1][0]))
    return (err_instr(params, op_tab[3].nbr_args));
  addr = get_val(params[TYPE_P][0], params[1], arena, proc);
  addr += get_val(params[TYPE_P][1], params[2], arena, proc);
  addr = my_mod(((addr % IDX_MOD) + proc->pc), MEM_SIZE);
  j = -1;
  while (++j < 4)
    val.octet[3 - j] = arena->arena[(addr + j) % MEM_SIZE];
  proc->reg[params[3][0] - 1] = val.integer;
  jump = 2 + get_nb_jump(params[TYPE_P], op_tab[9].nbr_args);
  free_params(params, op_tab[9].nbr_args);
  proc->carry = 1;
  proc->cycle_dodo = op_tab[9].nbr_cycles;
  return (jump);
}

int		sti(t_proc *proc, t_arena *arena)
{
  char		**params;
  t_conv	reg;
  int		addr;
  int		jump;

  params = get_params(op_tab[10].nbr_args, arena, increase_pc(proc->pc, 1));
  if (!is_valid_reg(params[TYPE_P][0], params[1][0]))
    return (err_instr(params, op_tab[10].nbr_args));
  reg.integer = proc->reg[params[1][0] - 1];
  addr = get_val(params[TYPE_P][1], params[2], arena, proc);
  addr += get_val(params[TYPE_P][2], params[3], arena, proc);
  write_vm(arena, my_mod(((addr % IDX_MOD) + proc->pc), MEM_SIZE),
	   reg, proc->id);
  jump = 2 + get_nb_jump(params[TYPE_P], op_tab[10].nbr_args);
  free_params(params, op_tab[10].nbr_args);
  proc->cycle_dodo = op_tab[10].nbr_cycles;
  return (jump);
}

int		vm_fork(t_proc *proc, t_arena *arena)
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
  addr = my_mod((proc->pc + (val.integer % IDX_MOD)), MEM_SIZE);
  add_proc_vm(proc, addr);
  proc->cycle_dodo = op_tab[11].nbr_cycles;
  return (5);
}

int		lld(t_proc *proc, t_arena *arena)
{
  char		**params;
  int		val;
  int		jump;

  params = get_params(op_tab[12].nbr_args, arena, increase_pc(proc->pc, 1));
  if (!is_valid_reg(params[TYPE_P][1], params[2][0]))
    return (err_instr(params, op_tab[12].nbr_args));
  val = get_val_no_idx(params[TYPE_P][0], params[1], arena, proc);
  proc->reg[params[2][0] - 1] = val;
  jump = 2 + get_nb_jump(params[TYPE_P], op_tab[12].nbr_args);
  free_params(params, op_tab[12].nbr_args);
  proc->carry = 1;
  proc->cycle_dodo = op_tab[12].nbr_cycles;
  return (jump);
}

int		lldi(t_proc *proc, t_arena *arena)
{
  char		**params;
  int		jump;
  int		addr;
  t_conv	val;
  int		j;

  params = get_params(op_tab[13].nbr_args, arena, increase_pc(proc->pc, 1));
  if (!is_valid_reg(params[TYPE_P][2], params[3][0])
      || is_valid_reg(params[TYPE_P][1], params[2][0])
      || is_valid_reg(params[TYPE_P][0], params[1][0]))
    return (err_instr(params, op_tab[13].nbr_args));
  addr = get_val(params[TYPE_P][0], params[1], arena, proc);
  addr += get_val(params[TYPE_P][1], params[2], arena, proc);
  addr = my_mod((addr + proc->pc), MEM_SIZE);
  j = -1;
  while (++j < 4)
    val.octet[3 - j] = arena->arena[(addr + j) % MEM_SIZE];
  proc->reg[params[3][0] - 1] = val.integer;
  jump = 2 + get_nb_jump(params[TYPE_P], op_tab[13].nbr_args);
  free_params(params, op_tab[13].nbr_args);
  proc->carry = 1;
  proc->cycle_dodo = op_tab[13].nbr_cycles;
  return (jump);
}
