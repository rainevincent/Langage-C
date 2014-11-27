/*
** pof.c for Corewar in /home/jobertomeu/Work/corewar/assembleur
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sat Apr 12 14:09:23 2014 Joris Bertomeu
** Last update Sun Apr 13 12:46:14 2014 Joris Bertomeu
*/

#include "gnl.h"
#include "assembleur.h"

void	new_label(t_system *sys)
{
  int	i;
  char	*nl;
  int	flag;

  i = 0;
  flag = 0;
  nl = xmalloc(128 * sizeof(char));
  while (sys->ins.str[i] != ':' && sys->ins.str[i] != ' ' && sys->ins.str[i])
    {
      nl[i] = sys->ins.str[i];
      i++;
    }
  if (sys->ins.str[i] == ':')
    flag = point_two(sys, i);
  nl[i] = '\0';
  i = 0;
  if (flag == 2)
    label_detect(sys, nl);
  free(nl);
}

void	init_pof(void (*which_instruction[16])(t_system *sys))
{
  which_instruction[0] = &st_instruction;
  which_instruction[1] = &and_instruction;
  which_instruction[2] = &ld_instruction;
  which_instruction[3] = &live_instruction;
  which_instruction[4] = &zjmp_instruction;
  which_instruction[5] = &sti_instruction;
  which_instruction[6] = &add_instruction;
  which_instruction[7] = &sub_instruction;
  which_instruction[8] = &or_instruction;
  which_instruction[9] = &xor_instruction;
  which_instruction[10] = &ldi_instruction;
  which_instruction[11] = &fork_instruction;
  which_instruction[12] = &lld_instruction;
  which_instruction[13] = &lldi_instruction;
  which_instruction[14] = &lfork_instruction;
  which_instruction[15] = &aff_instruction;
}

int	check_instruction(t_system *sys)
{
  char	**tab;
  void	(*which_instruction[16])(t_system *sys);
  int	j;

  tab = init_tab();
  init_pof(which_instruction);
  new_label(sys);
  j = 0;
  while (j < 16)
    {
      if (my_strncmp(&sys->ins.str[sys->ins.i], tab[j],
		  get_inst_len(&sys->ins.str[sys->ins.i])) == 0)
	{
	  (*which_instruction[j])(sys);
	  j = 16;
	}
      j++;
    }
  free(tab);
  return (1);
}

void	check_ext(int ac, char **argv)
{
  int	i;

  i = 1;
  while (i < ac)
    {
      if (my_strncmp(&argv[i][my_strlen(argv[i]) - 2], ".s", 2) != 0)
	aff_warn("Warning : It's preferable to give *.s\n");
      i++;
    }
}
