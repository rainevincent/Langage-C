/*
** main.c for  in /home/nicolas/Workspace/Corewar
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Wed Apr  9 15:44:53 2014 Nicolas Ades
** Last update Sat Apr 12 18:06:11 2014 Geoffrey Merran
*/

#include "main_vm.h"

void		init_all(int ac, char **av)
{
  t_arena	*arena;
  t_champ	*champs;
  t_cycles	cycles;

  champs = NULL;
  arena = my_xmalloc(sizeof(*arena));
  init_cycle(&cycles);
  init_arena(arena);
  vm_pars(ac, av, &cycles, &champs);
  init_id(&champs);
  init_addr(&champs);
  load_champs(&champs, arena);
  launch_battle(arena, &cycles, champs);
  free(arena->arena);
  free(arena->color);
  free(arena);
  free_champ(&champs);
}

int	main(int ac, char **av)
{
  if (ac > 1)
    init_all(ac, av);
  else
    my_printf("%s%s", VM_USAGE, VM_USAGE2);
  return (EXIT_SUCCESS);
}
