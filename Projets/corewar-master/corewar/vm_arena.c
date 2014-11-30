/*
** vm_arena.c for  in /home/nicolas/Workspace/Corewar/vm
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Tue Apr  8 11:57:41 2014 Nicolas Ades
** Last update Mon Apr 14 16:53:22 2014 Nicolas Ades
*/

#include "vm_arena.h"

int	increase_pc(int pc, int i)
{
  pc = my_mod((pc + i), MEM_SIZE);
  return (pc);
}

void	execute_instru(t_proc *proc, t_arena *arena, inst *instruction,
		       t_champ **champs)
{
  if (arena->arena[proc->pc] == 1)
    proc->pc = increase_pc(proc->pc, live(proc, arena, champs));
  else if (arena->arena[proc->pc] > 1 && arena->arena[proc->pc] <= 16)
    {
      proc->pc = increase_pc(proc->pc,
			     instruction[arena->arena[proc->pc] - 1](proc, arena));
    }
  else
    proc->pc = increase_pc(proc->pc, 1);
}

void		execute_procs(t_fighter *fighters, t_arena *arena, inst *instruction)
{
  t_proc	*tmp;

  tmp = fighters->procs;
  while (tmp)
    {
      if (tmp->cycle_dodo > 0)
	tmp->cycle_dodo--;
      else
	execute_instru(tmp, arena, instruction, &fighters->champs);
      tmp = tmp->next;
    }
}

int		is_winner(t_proc **proc, t_champ *champ, t_cycles *cycles,
			  t_arena *arena)
{
  t_proc	*tmp;

  if ((cycles->current_cycle % cycles->cycle_to_die) == 0)
    {
      tmp = *proc;
      while (tmp != NULL)
	{
	  if (tmp->alive == 0)
	    tmp = del_proc(tmp, proc);
	  if (tmp != NULL)
	    tmp = tmp->next;
	}
      if (one_winner(*proc, champ))
      	return (1);
      cycles->cycle_to_die -= CYCLE_DELTA;
    }
  if (arena->nbr_live == NBR_LIVE)
    {
      cycles->cycle_to_die -= CYCLE_DELTA;
      arena->nbr_live = 0;
    }
  return (0);
}

void		launch_battle(t_arena *arena, t_cycles *cycles, t_champ *champs)
{
  t_fighter	fighters;
  t_win		win;
  int		winner;
  inst		*instruction;

  winner = 0;
  fighters.champs = champs;
  init_proc(&fighters.procs, fighters.champs);
  instruction = get_instr();
  init_window(&win);
  init_color(&win, fighters.champs);
  aff_champions(&win, fighters.champs);
  my_printf("\n==BATTLE==\n\n");
  while (cycles->current_cycle != (cycles->cycle_max + 1) && !winner
	 && cycles->cycle_to_die > 0)
    {
      execute_procs(&fighters, arena, instruction);
      aff_window(&win, arena, &fighters, cycles);
      cycles->current_cycle++;
      winner = is_winner(&fighters.procs, fighters.champs, cycles, arena);
    }
  if (cycles->cycle_max != -1)
    dump_arena(arena->arena, cycles->cycle_max);
  who_win(champs, &win);
  free_battle(instruction, &win, &fighters.procs);
}
