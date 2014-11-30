/*
** vm_getparams.c for vm_getparams in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu Apr 10 01:13:59 2014 Geoffrey Merran
** Last update Sat Apr 12 01:31:59 2014 Geoffrey Merran
*/

#include "vm_getparams.h"

void	get_codage(unsigned char code, char **params, int nb_args)
{
  int	i;
  int	j;

  i = 0;
  while (i < nb_args)
    {
      j = 0;
      params[TYPE_P][i] = 0;
      while (j < 2)
	{
	  if ((code & 128) != 0)
	    params[TYPE_P][i] += my_power_rec(2, (1 - j));
	  code = code << 1;
	  j++;
	}
      i++;
    }
}

char	*get_value_reg(int *address, t_arena *arena)
{
  char	*reg;

  reg = my_xmalloc(sizeof(char));
  reg[0] = arena->arena[*address];
  *address = increase_pc(*address, 1);
  return (reg);
}

char	*get_value_index(int *address, t_arena *arena)
{
  int	i;
  char	*index;

  index = my_xmalloc(4 * sizeof(char));
  i = 0;
  while (i < 4)
    {
      index[i] = arena->arena[*address];
      *address = increase_pc(*address, 1);
      i++;
    }
  return (index);
}

void	free_params(char **params, int nb_args)
{
  int	i;

  i = 0;
  while (i < (nb_args + 1))
    free(params[i++]);
  free(params);
}

char	**get_params(int nb_args, t_arena *arena, int address)
{
  char	**params;
  int	i;

  params = my_xmalloc((1 + nb_args) * sizeof(char *));
  params[TYPE_P] = my_xmalloc(nb_args * sizeof(char));
  get_codage(arena->arena[address], params, nb_args);
  address = increase_pc(address, 1);
  i = 0;
  while (i < nb_args)
    {
      if (params[TYPE_P][i] == A_REG)
	params[i + 1] = get_value_reg(&address, arena);
      else if (params[TYPE_P][i] == A_DIR || params[TYPE_P][i] == A_IND)
	params[i + 1] = get_value_index(&address, arena);
      else
	{
	  params[i + 1] = my_xmalloc(sizeof(char));
	  params[i + 1][0] = 0;
	}
      i++;
    }
  return (params);
}

