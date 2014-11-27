/*
** my_mlx.h for my_mlx in /home/merran_g/work/c_igraph/mkdir/minilibx
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun Dec  1 17:53:21 2013 Geoffrey Merran
** Last update Mon May 19 23:38:11 2014 Geoffrey Merran
*/

#ifndef MLX_
# define MLX_
# include <mlx.h>

typedef void * mlxptr;
typedef struct s_pos t_pos;
typedef struct s_vector t_vector;
typedef struct s_window t_window;
typedef struct s_img t_img;
typedef struct s_screen t_screen;

struct	s_pos
{
  int	x;
  int	y;
};

struct	s_vector
{
  float	x;
  float	y;
  float	z;
};

struct		s_window
{
  mlxptr	mlx_ptr;
  mlxptr	ptr;
  t_pos  	size;
};

struct		s_img
{
  mlxptr	mlx_ptr;
  mlxptr	ptr;
  t_pos		size;
  char		*data;
  int		bbp;
  int		s_line;
  int		endian;
};

struct		s_screen
{
  t_window	win;
  t_img		img;
};

int	change_rgb(int r, int g, int b);
void	init_pos(t_pos *pos, int x, int y);
void	init_vec(t_vector *vec, float x, float y, float z);
void	init_window(mlxptr init, t_window *win, t_pos size, char *title);
void	init_img(t_img *i, t_window win, t_pos size);
void	init_screen(t_screen *s, t_window win, t_img img);
void	draw_rectangle(t_img *img, t_pos pos_rec, t_pos size_rec, int color);
void   	my_pixel_put_to_image(t_pos pixel, mlxptr m_ptr, t_img *img, int color);
void	draw_line(t_pos pos1, t_pos pos2, t_img *img, int color);

#endif /* MLX_ */
