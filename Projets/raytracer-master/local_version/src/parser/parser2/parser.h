/*
** parser.h for Parser RT in /home/martel_c/rendu/RT/parser
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Tue May 13 17:50:34 2014 martelliere
** Last update Thu Jun  5 18:26:18 2014 martelliere
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
# include	"../../../includes/rtv1.h"

/*
** DEFINITIONS
*/

typedef	struct	s_parser
{
  int		line;
  int		k;
  int		n;
  char		**tab;
}		t_parser;

typedef void(*ptr)(t_scene *, t_parser *);

/*
** PROTOTYPES
*/

void		get_eye(t_scene *scene, t_parser *parser);
void		get_spot(t_scene *scene, t_parser *parser);
void		get_plan(t_scene *scene, t_parser *parser);
void		get_sphere(t_scene *scene, t_parser *paser);
void		get_cone(t_scene *scene, t_parser *parser);
void		get_cylindre(t_scene *scene, t_parser *parser);
void		init_otab(char **otab, void **which_object);
void            init_vec(t_vector *vec, float x, float y, float z);
void		add_item(t_node **list, t_item new);
void		*my_xmalloc(int size);
void		*my_xrealloc(char *str, int size);
void		*my_alloc_init(int size, char c);
char		*strlower(char *str);
char		**my_str_to_wordtab(char *s);
float		get_pos(t_parser *parser, char *id);
float		get_size(t_parser *parser);
float		get_brill(t_parser *parser);
float		get_opacity(t_parser *parser);
int		my_parser(t_scene *scene, t_parser *parser, int i);
int		xopen(const char *, int, mode_t);
t_vector	get_vector(t_parser *parser, char *id);
t_rgb		get_color(t_parser *parser);
t_scene		*init_scene(t_scene *scene);

#endif		/* PARSER_H_ */
