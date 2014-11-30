/*
** main.h for main in /home/merran_g/work/c_igraph/rtv1
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri Mar 14 16:54:50 2014 Geoffrey Merran
** Last update Sun Jun  8 17:46:27 2014 Geoffrey Merran
*/

#ifndef MAIN_
# define MAIN_
# define WIN_X 800
# define WIN_Y 800
# define ESCAPE 65307
# define WIN_TITLE "RayTracer V.1 | Geoffrey Merran"
# include <math.h>
# include <stdlib.h>
# include "my_mlx.h"
# include "mlx_utility.h"
# include "my.h"
# include "my_printf.h"
# include "rtv1.h"
# include "parser.h"

/*
** Main functions (OLD to edit)
*/

void		init_cam(t_cam *cam); /* to move in parser */
unsigned int   	calc_image(t_pos pos, t_scene *scene);
void		fill_image(t_img *img, t_scene *scene);
t_inter		get_pixel_color(t_vector pos_3d, t_scene *scene);


/*
** Intersection
*/

typedef t_rinter (*t_finter)(t_cam, t_vector, t_item);

t_inter		find_inter(t_cam eye, t_vector pos_3d, t_node *items);
t_vector	get_eq_param(t_vector eye, float k, t_vector pos_3d);
float		get_k_from_delta(float delta, float a, float b);
t_vector	get_normal(t_inter inter, t_cam *eye);
t_rinter	inter_plan(t_cam eye, t_vector pos_3d, t_item plan);
t_rinter	inter_sphere(t_cam eye, t_vector pos_3d, t_item sphere);
t_rinter	inter_cylinder(t_cam eye, t_vector pos_3d, t_item sphere);
t_rinter	inter_cone(t_cam eye, t_vector pos_3d, t_item cone);
t_rinter	inter_hyper(t_cam eye, t_vector pos_3d, t_item hyper);

/*
** Get position (real / simple)
*/

void		rotate_x(t_vector *eye, float angle);
void		rotate_y(t_vector *eye, float angle);
void		rotate_z(t_vector *eye, float angle);
void		translate(t_vector *eye, t_vector item);
void		rotate_all(t_vector *pos, t_vector angle);
void		get_simple_pos(t_cam *eye, t_item item, t_vector *pos_3d);

/*
** Luminosity / Shadow
*/

t_rgb		luminosity(t_spot spot, t_inter inter);
int		is_shadow(t_spot spot, t_inter inter, t_node *items);


/*
** Effects
*/

void		apply_pertubation(t_inter *inter);
t_rgb		put_reflexion(t_inter inter, t_scene *scene, t_vector pos_3d);
t_rgb		put_transparence(t_inter inter, t_scene *scene, t_vector pos_3d);

/*
** Hook
*/

int		expose_hook(t_screen *params);
int		key_hook(int keycode, t_screen *params);

/*
** Xfunction
*/

mlxptr		xmlx_init();

#endif /* MAIN_ */
