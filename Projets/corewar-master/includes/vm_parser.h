/*
** parser.h for  in /home/nicolas/Workspace/Corewar/includes
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Wed Mar 26 11:51:33 2014 Nicolas Ades
** Last update Wed Apr  9 22:15:21 2014 Geoffrey Merran
*/

#ifndef VM_PARSER_H_
# define VM_PARSER_H_
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "my.h"
# include "xfunction.h"
# include "vm_corewar.h"
# include "vm_getchamp.h"

int	dump_opt(int i, int ac, char **av, t_cycles *cycles);
int	a_opt(int i, int ac, char **av, t_champ **champ);
int	n_opt(int i, int ac, char **av, t_champ **champ);
int	get_cor(int i, int ac, char **av, t_champ **champ);
void	vm_pars(int ac, char **av, t_cycles *cycles, t_champ **champs);

#endif /* VM_PARSER_H_ */
