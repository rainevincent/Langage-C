/*
** vm_getchamp.h for vm_getchamp in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Mar 26 11:52:31 2014 Geoffrey Merran
** Last update Sun Apr 13 17:12:46 2014 Geoffrey Merran
*/

#ifndef VM_GETCHAMP_
# define VM_GETCHAMP_
# define BUFFER_SIZE 3717
# include "vm_parser.h"
# include "vm_corewar.h"

void	add_champ(t_champ **champ);
void   	create_champ(t_champ **champ);
void	load_champs(t_champ **champs, t_arena *arena);
void	fill_champ(t_champ *champ, int fd, t_arena *arena);
void	write_champ_in(unsigned char *, t_champ *, t_arena *arena, int);
int    	nb_champ_alive(t_champ *champ);
int    	get_nb_champs(t_champ *champs);
int	get_magic(unsigned char *buffer);
int    	get_size(unsigned char *buffer);
void	get_name(unsigned char *buffer, char prog_name[]);
void	get_comment(unsigned char *buffer, char comment[]);

#endif /* VM_GETCHAMP_ */
