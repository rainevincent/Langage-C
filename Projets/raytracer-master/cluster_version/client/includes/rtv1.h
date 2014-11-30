/*
** rtv1.h for rtv1 in /home/merran_g/work/c_igraph/rtv1
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Sat Mar 15 18:20:39 2014 Geoffrey Merran
** Last update Sun Jun  8 12:03:48 2014 Geoffrey Merran
*/

#ifndef RTV1_
# define RTV1_
# include "my_mlx.h"

typedef struct	s_qua
{
  float		a;
  float		b;
  float		c;
}		t_qua;

typedef union	s_union
{
  int		clr;
  char		color[4];
}		t_union;

typedef enum	s_type
  {
    SPHERE = 0,
    PLANE,
    CONE,
    CYLINDER,
    HYPER
  }		t_type;

typedef enum	s_effect
  {
    NONE = 0,
    VAGUE,
    DAMIER
  }		t_effect;

typedef struct	s_rgb
{
  int		r;
  int		g;
  int		b;
}		t_rgb;

typedef struct	s_cam
{
  t_vector	pos;
  t_vector	angle;
  float		distance;
}		t_cam;

typedef struct	s_item
{
  t_vector	pos;
  t_vector	angle;
  t_qua		qua;
  t_type	type;
  t_rgb		color;
  t_effect	effect;
  float		rayon;
  float		brillance;
  float		reflexion;
  float		transparence;
}		t_item;

typedef struct	s_node
{
  t_item	item;
  struct s_node	*next;
}		t_node;

typedef struct	s_inter
{
  float		k;
  t_vector	n;
  t_vector	p;
  t_rgb		rgb;
  t_item	item;
}		t_inter;

typedef struct	s_rinter
{
  float		k;
  t_vector	p;
}		t_rinter;

typedef struct	s_spot
{
  t_vector	pos;
  t_rgb		color;
  struct s_spot	*next;
}		t_spot;

typedef struct	s_scene
{
  t_cam		*eye;
  t_node	*items;
  t_spot	*spots;
}		t_scene;

#endif /* RTV1_ */
