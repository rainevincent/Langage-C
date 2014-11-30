/*
** vm_init.c for vm_init in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri Mar 28 16:00:42 2014 Geoffrey Merran
** Last update Fri Apr 11 22:44:02 2014 Geoffrey Merran
*/

#include "vm_init.h"

void	init_cycle(t_cycles *cycles)
{
  cycles->cycle_to_die = CYCLE_TO_DIE;
  cycles->current_cycle = 1;
  cycles->cycle_max = -1;
}

void	init_arena(t_arena *arena)
{
  int	i;

  arena->arena = my_xmalloc(MEM_SIZE * sizeof(char));
  arena->color = my_xmalloc(MEM_SIZE * sizeof(char));
  arena->nbr_live = 0;
  i = 0;
  while (i < MEM_SIZE)
    {
      arena->color[i] = 0;
      arena->arena[i] = 0;
      i++;
    }
}

int		is_id_possible(t_champ *champs, int id)
{
  t_champ	*tmp;

  tmp = champs;
  while (tmp != NULL)
    {
      if (tmp->id == id)
	return (0);
      tmp = tmp->next;
    }
  return (1);
}

void		init_id(t_champ **champs)
{
  int		id;
  t_champ	*tmp;

  id = 1;
  tmp = *champs;
  while (tmp != NULL)
    {
      while (tmp->id == 0)
	{
	  if (is_id_possible(*champs, id))
	    tmp->id = id;
	  id++;
	}
      tmp = tmp->next;
    }
}

void		init_addr(t_champ **champs)
{
  int		i;
  int		nb_champs;
  int		mem_pos;
  t_champ	*tmp;

  nb_champs = get_nb_champs(*champs);
  if (nb_champs > 4 || nb_champs < 2)
    my_error("Champs error : You must load 2 to 4 champions only\n");
  tmp = *champs;
  mem_pos = 0;
  i = 1;
  while (tmp != NULL)
    {
      if (tmp->address == -1)
	{
	  if (i == 2 && nb_champs == 2)
	    mem_pos += MEM_SIZE / 4;
	  tmp->address = mem_pos;
	}
      i++;
      my_printf("Starting adress of champion n°%d loaded !\n", tmp->id);
      tmp = tmp->next;
      mem_pos += MEM_SIZE / 4;
    }
}
