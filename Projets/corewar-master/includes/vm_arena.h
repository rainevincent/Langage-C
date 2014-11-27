/*
** vm_arena.h for vm_arena in /home/merran_g/work/c_elem/corewar
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Apr  9 18:03:23 2014 Geoffrey Merran
** Last update Sun Apr 13 19:00:26 2014 Geoffrey Merran
*/

#ifndef VM_ARENA_
# define VM_ARENA_
# include "vm_corewar.h"
# include "vm_proc.h"
# include "vm_getchamp.h"
# include "vm_instruction.h"
# include "sdl_xfunction.h"
# include "aff.h"
# include "my_free.h"
# include "my_printf.h"

int	increase_pc(int pc, int i);
int	my_mod(int a, int b);
void   	reset_pc(t_proc *proc);
int    	is_winner(t_proc **proc, t_champ *champ, t_cycles *cycles,
		  t_arena *);
int    	one_winner(t_proc *proc, t_champ *champ);
void   	who_win(t_champ *champ, t_win *win);
void	execute_instru(t_proc *proc, t_arena *arena, inst *instruction,
		       t_champ **champs);
void	execute_procs(t_fighter *fighters, t_arena *arena, inst *instruction);
void	launch_battle(t_arena *arena, t_cycles *cycles, t_champ *champs);
void   	dump_arena(unsigned char *arena, int cycle_max);

#endif /* VM_ARENA_ */
