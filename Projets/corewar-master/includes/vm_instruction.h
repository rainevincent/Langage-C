/*
** vm_instruction.h for vm_instruction in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 12:46:20 2014 Geoffrey Merran
** Last update Sat Apr 12 00:56:09 2014 Geoffrey Merran
*/

#ifndef VM_INSTRUCTION_
# define VM_INSTRUCTION_
# include <stdlib.h>
# include "vm_corewar.h"
# include "vm_proc.h"
# include "vm_arena.h"
# include "vm_getparams.h"
# include "my.h"

inst	*get_instr();
int	live(t_proc *, t_arena *, t_champ **);
int	ld(t_proc *, t_arena *);
int	st(t_proc *, t_arena *);
int	add(t_proc *, t_arena *);
int	sub(t_proc *, t_arena *);
int	and(t_proc *, t_arena *);
int	or(t_proc *, t_arena *);
int	xor(t_proc *, t_arena *);
int	zjmp(t_proc *, t_arena *);
int	ldi(t_proc *, t_arena *);
int	sti(t_proc *, t_arena *);
int	vm_fork(t_proc *, t_arena *);
int	lld(t_proc *, t_arena *);
int	lldi(t_proc *, t_arena *);
int	lfork(t_proc *, t_arena *);
int	aff(t_proc *, t_arena *);
void   	live_champ(t_proc *proc, t_champ **champ);

#endif /* VM_INSTRUCTION */
