/*
** rtv1.h for rtv1 in /home/merran_g/work/c_igraph/rtv1
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sat Mar 15 18:20:39 2014 Geoffrey Merran
** Last update Mon May 19 23:27:11 2014 Geoffrey Merran
*/

#ifndef RTV1_
# define RTV1_

typedef enum	s_type
  {
    SPHERE = 1,
    PLANE = 2,
    CONE = 3,
    CYLINDER = 4
  }		t_type;

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
  t_type	type;
  float		rayon;
  t_rgb		color;
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
}		t_spot;

typedef struct	s_scene
{
  t_cam		*eye;
  t_node	*items;
  t_spot	*spots;
}		t_scene;

#endif /* RTV1_ */
