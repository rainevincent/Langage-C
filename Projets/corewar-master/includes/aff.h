/*
** aff.h for aff in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr  8 19:33:03 2014 Geoffrey Merran
** Last update Sun Apr 13 19:20:58 2014 Geoffrey Merran
*/

#ifndef AFF_
# define AFF_
# define SIZE_X 1280
# define SIZE_Y 720
# define PLOT_W 8
# define PLOT_H 8
# define SEP_W 2
# define SEP_H 2
# define BPP 32
# include "vm_corewar.h"
# include "vm_proc.h"
# include "vm_getchamp.h"
# include "sdl_xfunction.h"

void   	init_color(t_win *win, t_champ *champ);
void	init_window(t_win *win);
void   	init_sdl_header(t_win *win);
void   	reset_pos(t_win *win);
Uint32 	get_case_color(t_arena *arena, int address,
		       t_fighter *fighters, t_win *win);
void	aff_arena(t_win *win, t_arena *arena, t_fighter *fighters);
void   	aff_window(t_win *win, t_arena *arena,
		   t_fighter *fighters, t_cycles *cycles);
void   	aff_nb_sdl(int x, int y, int nb, t_win *win);
void   	aff_text_sdl(int x, int y, char *str, t_win *win);
void   	aff_champions(t_win *win, t_champ *champs);
void   	aff_color_champ(int x, int y, t_win *win, t_champ *champ);
void   	aff_winner(t_champ *champ, t_win *win);

#endif /* AFF_ */
