/*
** vm_pars.c for  in /home/nicolas/Workspace/Corewar/vm
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Wed Mar 26 11:40:53 2014 Nicolas Ades
** Last update Sun Apr 13 19:51:31 2014 Geoffrey Merran
*/

#include "vm_parser.h"

int	dump_opt(int i, int ac, char **av, t_cycles *cycles)
{
  int	nbr_cycle;

  if (my_strcmp(av[i], "-dump") == 0)
    {
      if (i + 1 < ac)
	{
	  nbr_cycle = my_getnbr(av[i + 1]);
	  if (nbr_cycle <= 0)
	    my_error("-dump error : -dump must be positive\n");
	  if (cycles->cycle_max > -1)
	    my_error("-dump error : too much -dump opt");
	  cycles->cycle_max = nbr_cycle;
	  return (i + 2);
	}
      else
	my_error("-dump error : You must give a value with the option\n");
    }
  return (i);
}

int	a_opt(int i, int ac, char **av, t_champ **champ)
{
  int	ld_add;

  if (i >= ac)
    my_error("Arg error : need more champs\n");
  if (my_strcmp(av[i], "-a") == 0)
    {
      if (i + 1 < ac)
	{
	  ld_add = my_getnbr(av[i + 1]);
	  if ((ld_add < 0 || ld_add > MEM_SIZE - 1))
	    my_error("-a error : Value must be contain in memory\n");
	  add_champ(champ);
	  if ((*champ)->address != -1)
	    my_error("-a error : too much -a opt\n");
	  (*champ)->address = ld_add;
	  return (i + 2);
	}
      else
	my_error("-a error : You must give a value with the option\n");
    }
  return (i);
}

int	n_opt(int i, int ac, char **av, t_champ **champ)
{
  int	prog_nb;

  if (i >= ac)
    my_error("Arg error : need more champs\n");
  if (my_strcmp(av[i], "-n") == 0)
    {
      if (i + 1 < ac)
	{
	  prog_nb = my_getnbr(av[i + 1]);
	  if (prog_nb <= 0)
	    my_error("-n error : -n must be positive\n");
	  add_champ(champ);
	  if ((*champ)->id > 0)
	    my_error("-n error : too much -n opt\n");
	  (*champ)->id = prog_nb;
	  return (i + 2);
	}
      else
	  my_error("-n error : You must give a value with the option\n");
    }
  return (i);
}

int	get_cor(int i, int ac, char **av, t_champ **champ)
{
  int	k;

  if (i >= ac)
    my_error("Arg error : need more champs\n");
  k = my_strlen(av[i]);
  if (k < 4)
    my_error("champ error : Invalid champion file\n");
  if (my_strcmp(&(av[i][k - 4]), ".cor") == 0)
    {
      add_champ(champ);
      (*champ)->path = av[i];
      (*champ)->live = 0;
    }
  else
    my_error("champ error : Invalid champion extansion\n");
  return (i);
}

void	vm_pars(int ac, char **av, t_cycles *cycles, t_champ **champs)
{
  int	i;

  i = 1;
  while (i < ac)
    {
      i = dump_opt(i, ac, av, cycles);
      i = a_opt(i, ac, av, champs);
      i = n_opt(i, ac, av, champs);
      i = get_cor(i, ac, av, champs);
      i++;
    }
}
