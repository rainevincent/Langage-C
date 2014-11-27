/*
** vm_corewar.h for vm_corewar.h in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Mar 26 12:00:22 2014 Geoffrey Merran
** Last update Fri Apr 11 22:43:35 2014 Geoffrey Merran
*/

#ifndef VM_COREWAR_
# define VM_COREWAR_
# define MAGIC_NUMBER 413
# define TYPE_P 0
# define A_REG 1
# define A_DIR 2
# define A_IND 3
# include <SDL/SDL.h>
# include "op.h"

typedef struct	s_arena
{
  unsigned char *arena;
  unsigned char *color;
  int		nbr_live;
}		t_arena;

typedef struct		s_champ
{
  int			id;
  header_t		header;
  int			address;
  char			*path;
  int			live;
  Uint32		color;
  struct s_champ	*next;
  struct s_champ	*prev;
}			t_champ;

typedef	struct	s_cycles
{
  int		cycle_to_die;
  int		current_cycle;
  int		cycle_max;
}		t_cycles;

typedef struct	s_proc
{
  int		id;
  int		pc;
  int		carry;
  int		alive;
  int		cycle_dodo;
  int		reg[REG_NUMBER];
  struct s_proc	*next;
  struct s_proc	*prev;
}		t_proc;

typedef union	u_conv
{
  char	octet[4];
  int	integer;
}		t_conv;

typedef struct	s_fighter
{
  t_champ	*champs;
  t_proc	*procs;
}		t_fighter;

typedef int (*inst)(t_proc *, t_arena *);

#endif /* VM_COREWAR_ */
