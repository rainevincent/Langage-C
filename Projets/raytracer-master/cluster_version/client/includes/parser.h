/*
** parser.h for  in /home/mediav_j/mabm/raytracer/merge/client
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sun Jun  8 07:29:05 2014 Jeremy Mediavilla
** Last update Sun Jun  8 15:49:15 2014 Jeremy Mediavilla
*/

#ifndef		PARSER_H_
# define	PARSER_H_

/*
** INCLUDES
*/

# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	<string.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	"get_next_line.h"
# include	"my_mlx.h"
# include	"my.h"
# include	"my_printf.h"
# include	"rtv1.h"

/*
** DEFINITIONS
*/


typedef struct	s_parser
{
  t_scene	*scene;
  t_item	tmp;
}		t_parser;

typedef void(*ptr)(t_scene *, t_parser *);

typedef		struct s_list
{
  char		*data;
  struct s_list *next;
  struct s_list *prev;
}		t_list;

/* fonctions dans balise_tools.c */
int		is_xml_balise(char **, char *, int);
char		*get_closing_balise(char *);
int		is_valid_balise(char *);
void		is_closing_balise(int, char *, char **);
void		wrong_balise(int *, char **);

/* fonctions dans balise_value.c */
int		get_ibalise_value(char *, char *, int);
float		get_fbalise_value(char *, char *, int);
float		get_fcoord_pars(char **, int, char *);
float		get_fbalise_value_spec(char *, char *, int);
float		get_effects_val(char *, char **, int);

/* fonctions dans get_infos.c */
void		get_color_info(int, char **, t_parser *);
void		get_item_info(int *, char **, char *, t_parser *);
void		get_spot_info(int *, char **, char *, t_parser *);
void		get_eye_info(int *, char **, char *, t_parser *);
float		get_effects_val2(char *, char **, int);

/* fonctions dans get_item_val.c */
void		print_rgb_error(int);
void		get_item_pos(char **, int, char *, t_parser *);
int		get_color_rgb(int, char **, char *);
void		get_effects(int, char **, t_parser *);
void		get_size_item(int, char **, t_parser *);

/* fonctions dans parser.c */
void		check_balise(int *, char *, char **, t_parser *);
char		**epure_tab(char **, char *);
t_scene		*get_scene(char *);

/* fonctions dans scene_tools.c */
void		reset_item(t_parser *);
void		init_scene(t_scene **);
void		aff_the_scene(t_scene *);

/* fonctions dans str_tools.c */
int		is_char_from_str(char, char *);
int		nbr_char_begin(char *, char *);
char		*remove_char_begin(char *, char *);
char		*get_item_type(char *);
int		type_val(char *);

/* fonctions dans read_inf.c */
char		*my_read_inf(int);

/* fonctions dans list.c */

t_list		*create_list(char *);
void		add_after(t_list *, char *);
void		add_before(t_list *, char *);
void		remove_from_list(t_list *);
void		add_to_end(t_list *, char *);

/* fonction dans items.c */
void		add_item(t_node **, t_item);
int		get_type_effect_val(char *, char **, int);

#endif		/* PARSER_H_ */
