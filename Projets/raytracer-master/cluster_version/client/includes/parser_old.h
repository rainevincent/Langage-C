/*
** parser.h for parser in /home/merran_g/work/c_elem/raytracer/includes
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Mon May 19 23:05:46 2014 Geoffrey Merran
** Last update Fri Jun  6 03:19:18 2014 Geoffrey Merran
*/

#ifndef PARSER_
# define PARSER_
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include "my.h"
# include "my_mlx.h"
# include "rtv1.h"

typedef		struct s_list
{
  char		*data;
  struct s_list *next;
  struct s_list *prev;
}		t_list;

/* fonctions dans list.c */

t_list		*create_list(char *);
void		add_after(t_list *, char *);
void		add_before(t_list *, char *);
void		remove_from_list(t_list *);
void		add_to_end(t_list *, char *);

/*
** Old
*/

void   	add_item(t_node **list, t_item new);
void	init_item(t_item *new, t_vector pos, t_vector angle, t_type type);
void	init_item2(t_item *new, float rayon, t_rgb color, float brillance, float reflexion);
void	init_rgb(t_rgb *color, int r, int g, int b);
t_node 	*get_items();
t_spot 	*get_spots();

/*
** Get Scene (To Do)
*/

t_scene	*get_scene();

#endif /* PARSER_ */
