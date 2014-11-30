/*
** assembleur.h for  in /home/mediav_j/corewar/assembleur/includes
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:03:51 2014 Jeremy Mediavilla
** Last update Sun Apr 13 15:10:02 2014 Jeremy Mediavilla
*/

#ifndef COREWAR_H
# define COREWAR_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../../libmy/my.h"
# include "op.h"

typedef struct s_labels t_labels;
struct s_labels
{
  int	offset;
  char	*name;
};


typedef struct s_olabels t_olabels;
struct s_olabels
{
  int	offset;
  char	*name;
  int	line;
};

typedef struct	s_instruction
{
  int		fd;
  char		*str;
  int		i;
  int		ibase;
  char		c;
  char		c_save;
  int		ret_chck;
  int		cmptr;
}		t_instruction;

typedef struct s_system t_system;
struct s_system
{
  char		*name;
  char		*name_file;
  char		*comment;
  char		*ret_gnl;
  int		nb_comment;
  int		nb_name;
  int		kf;
  int		f_c;
  int		f_n;
  int		wm;
  t_labels	labels[128];
  t_olabels	olabels[128];
  t_instruction	ins;
  int		cl;
  int		col;
  int		start_line;
  char		*final_name;
};

typedef union u_conv t_conv;
union u_conv
{
  char	octets[4];
  int	value;
  int	fd;
};

/* fonctions dans init.c */
char		**init_tab();
void		init_cmd_asm(t_system *);
void		init_start(t_system *);

/* fonctions dans init2.c */
void		free_struct(t_system *);
void		init(int, char **);
void		header_init1(int *, t_system *, int, int *);
char		*init_tab_char();
void		init_dataf(int *, int *, int *,int *);

/* fonctions dans pars.c */
void		parse_name(char *, int, t_system *);
void		parse_comment(char *, int, t_system *);
int		parse_line_cn(char *, t_system *, int);
void		parse_list_asm(t_system *);

/* fonctions dans aff.c */
void		affbin(unsigned);
void		aff_error(t_system *sys, char *);
void		aff_info(t_system *, char *);
void		aff_warn(char *);
void		aff_dird(int *, t_system *);

/* fonctions dans instruction1.c */
void		live_instruction(t_system *);
void		ld_instruction(t_system *);
void		st_instruction(t_system *);
void		add_instruction(t_system *);
void		sub_instruction(t_system *);

/* fonctions dans instruction2.c */
void		and_instruction(t_system *);
void		or_instruction(t_system *);
void		xor_instruction(t_system *);
void		zjmp_instruction(t_system *);
void		ldi_instruction(t_system *);

/* fonctions dans instruction3.c */
void		sti_instruction(t_system *);
void		fork_instruction(t_system *);
void		lfork_instruction(t_system *);
void		lld_instruction(t_system *);
void		lldi_instruction(t_system *);

/* fonction dans instruction4.c */
void		aff_instruction(t_system *);

/* fonctions dans data.c */
void		dir_data_condition(int, t_conv *, int);
void		xwrite_reg_data(char *, int *, t_conv *, int);
void		xwrite_undir_data(char *, int *, t_conv *, int);
void		xwrite_dir_data(char *, int *, t_conv *, t_system *);
void		xwrite_data(int, char *, int, t_system *);

/* fonctions dans file.c */
int		register_condition(t_system *);
int		direct_condition(t_system *);
int		indirect_condition(t_system *);
void		xwrite_to_file(char *, int, int, t_system *);

/* fonction dans magic.c */
void		xwrite_magic(int);
void		do_labels(int, t_system *);
void		check_all(t_system *, int , char *, int *);
int		param_pt(char *, t_system *, t_conv *, int *);

/* fonctions dans tread.c */
void		tread_line(char *, t_system *, int, int);
void		tread_file(char *, t_system *);
void		tread_line_cnf_asm(t_system *, char *, int);

/* fonctions dans check_errors.c */
void		check_inst_error(int*, t_system *);

/* fonctions dans main.c */
void		create_header(int, t_system *, int);
int		get_inst_len(char *);
void		create_header(int, t_system *, int);
void		label_detect(t_system *, char *);
int		point_two(t_system *, int);

/* fonction dans pof.c */
void		new_label(t_system *);
void		init_pof(void (*which_instruction[16])(t_system *sys));
int		check_instruction(t_system *);
void		check_ext(int, char **);

/* fonctions dans error_instruction1.c */
void		sti_check_err(t_system *, int *);
void		and_check_err(t_system *, int *);
void		ld_check_err(t_system *, int *);
void		live_check_err(t_system *, int *);
void		zjmp_check_err(t_system *, int *);

/* fonctions dans error_instruction2.c */
void		st_check_err(t_system *, int *);
void		add_check_err(t_system *, int *);
void		sub_check_err(t_system *, int *);
void		or_check_err(t_system *, int *);
void		xor_check_err(t_system *, int *);

/* fonctions dans error_instruction3.c */
void		ldi_check_err(t_system *, int *);
void		fork_check_err(t_system *, int *);
void		lld_check_err(t_system *, int *);
void		lldi_check_err(t_system *, int *);
void		lfork_check_err(t_system *, int *);

/* fonctions dans error_instruction4.c */
void		aff_check_err(t_system *, int *);

/* fonctions dans xfunctions.c */
void		*xmalloc(size_t);
int		xopen(const char *, int);
ssize_t		xwrite(int, const void *, size_t);

#endif /* COREWAR_H */
