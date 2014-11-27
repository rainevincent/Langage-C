/*
** gui.h for gui in /home/jobertomeu/Work/raytracer/graphic
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Thu Jun  5 15:20:52 2014 Joris Bertomeu
** Last update Sat Jun  7 22:20:42 2014 Joris Bertomeu
*/

#ifndef GUI_
# define GUI_

typedef struct	s_args
{
  char		*port;
  char		*nb_max;
  char		*x;
  char		*y;
  char		*conf;
}		t_args;

typedef struct	s_l_m
{
  int		r;
  int		g;
  int		b;
}		t_l_m;

typedef struct	s_l_o
{
  GtkWidget	*resol_l;
  GtkWidget	*antialias_l;
  GtkWidget	*nb_clients_l;
  GtkWidget	*mode_l;
}		t_l_o;

typedef struct	s_b_m
{
  GtkWidget	*edition;
  GtkWidget	*rt;
  GtkWidget	*options;
  GtkWidget	*quit;
  GtkWidget	*cred;
}		t_b_m;

typedef struct	s_b_o
{
  GtkWidget	*ok_btn;
  GtkWidget	*can_btn;
}		t_b_o;

typedef struct	s_b_r
{
  GtkWidget	*load;
  GtkWidget	*entry;
  GtkWidget	*can;
  GtkWidget	*go;
}		t_b_r;

typedef struct	s_c_o
{
  GtkWidget	*resol;
  GtkWidget	*antialias;
  GtkWidget	*nb_clients;
  GtkWidget	*mode;
}		t_c_o;

typedef struct	s_s_m
{
  GtkWidget	*window;
  GtkWidget	*frame;
  GdkPixbuf	*image;
  GtkWidget	*widget;
  GdkPixmap	*background;
  GtkStyle	*style;
}		t_s_m;

typedef struct	s_g_m
{
  t_b_m		buttons;
  t_l_m		labels;
  t_s_m		sys;
}		t_g_m;

typedef struct	s_li_o
{
  GList		*list_resol;
  GList		*list_antia;
  GList		*list_mode;
  GList		*list_client;
}		t_li_o;

typedef struct	s_g_o
{
  t_b_o		buttons;
  t_l_o		labels;
  t_s_m		sys;
  t_li_o	list;
  t_c_o		combo;
}		t_g_o;

typedef struct	s_g_r
{
  t_b_r		buttons;
  t_l_o		labels;
  t_s_m		sys;
  t_li_o	list;
  t_c_o		combo;
}		t_g_r;

typedef struct	s_gui
{
  t_g_m		main;
  t_g_o		opt;
  t_g_r		rt;
  t_args	args;
}		t_gui;

#endif /* GUI_ */
