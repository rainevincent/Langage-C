/*
** main.h for main in /home/merran_g/work/c_igraph/rtv1
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri Mar 14 16:54:50 2014 Geoffrey Merran
** Last update Sun Jun  8 16:20:39 2014 Geoffrey Merran
*/

#ifndef MAIN_
# define MAIN_

# define WIN_X 800
# define WIN_Y 600
# define ESCAPE 65307
# define _BSD_SOURCE
# include <math.h>
# include <arpa/inet.h>
# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include <string.h>
# include <libserver.h>
# include <pthread.h>
# include <gtk/gtk.h>
# include <time.h>
# include <X11/Xlib.h>
# include "gui.h"
# include "my.h"
# include "my_printf.h"
# include "parser.h"

extern GdkPixbuf	*pixbuf;
extern GdkPixbuf	*pixbuff;
extern int		g_flag;
extern int		start;
extern int		g_fflag;

typedef union	s_union
{
  unsigned int	clr;
  unsigned char	color[4];
}		t_union;

typedef struct	s_params
{
  int		nb_clients;
  int		port;
}		t_params;

typedef		struct s_list
{
  char		*data;
  struct s_list *next;
  struct s_list *prev;
}		t_list;

typedef struct	s_gui_serv
{
  GtkWidget	*window;
  GtkWidget	*windowf;
  GtkWidget	*imagef;
  GtkWidget	*frame;
  GtkWidget	*image;
  GtkWidget	*refresh_btn;
  GtkWidget	*png_btn;
  GtkWidget	*jpg_btn;
  GtkWidget	*full_btn;
  GtkWidget	*progress;
  GtkWidget	*label;
  char		*file;
  t_params	*params;
  time_t	start;
  time_t	finish;
  int		width;
  int		heigh;
  int		twidth;
  int		theigh;
  char		**argv;
  t_libserver	*libserver;
}		t_gui_serv;

typedef struct s_pos		t_pos;
struct				s_pos
{
  int				x;
  int				y;
};

/* Server */

void		print_error(char *str);
char		*search_ip_from_fd(t_libserver *libserver, int fd);
int		search_id_from_fd(t_libserver *libserver, int fd);
void		send_all(t_libserver *libserver, char *addr_client, char *buff);
void		del_client(t_libserver *libserver, char *addr_client, int fd_ok);
void		pixel_put_to_pixbuf(GdkPixbuf *pixbuf, int x, int y, guchar *tab);
void		stock_clr_img(t_libserver *libserver, t_gui_serv *gui);
void		do_finish(t_libserver *libserver, t_gui_serv *gui);
void		parse_line(char *buff, int fd_ok, t_libserver *libserver,
 t_gui_serv *gui);
void		init_clients(t_libserver *libserver);
void		init_lib(t_libserver *libserver, int port);
void		add_client(int id, t_libserver *libserver);
int		id_exist(int id, t_libserver *libserver);
void		send_first_data(t_libserver *libserver, int nb_cl_total, t_gui_serv *gui);
void		send_rest(t_libserver *libserver, t_gui_serv *gui, int i);
void		send_first_data_re(t_libserver *libserver, int nb_cl_total,
 t_gui_serv *gui);
void		check_new_client(t_libserver *libserver,
int nb_cl_total, t_gui_serv *gui);
void		init_fds(t_libserver *libserver);
int		init_fd(fd_set *rfds, t_libserver *libserver);
void		do_sock_fd(t_libserver *libserver, int client_max, t_gui_serv *gui);
void		do_sock_client(t_libserver *libserver, fd_set rfds, t_gui_serv *gui);
void		init_all_serv(t_libserver *libserver, t_params *params);
void		decision(t_gui_serv *gui, fd_set rfds, t_libserver *libserver);
void		*server(void *ok);
void		refresh_img(GtkWidget *useless, t_gui_serv *gui);
void		refresh_imgf(GtkWidget *useless, t_gui_serv *gui);
void		*refresh_img_func_full(void *data);
void		*refresh_img_func(void *data);
int		there_is_ext(const gchar *str, char *ext);
void		widget_destroy(GtkWidget *w, GtkWidget *ok);
gchar		*clear_path(const gchar *str, char *ext);
void		write_to_jpg(GtkWidget *widget, GtkWidget *select);
void		save_jpg(GtkWidget *widget, GdkPixbuf *pixbuf);
void		write_to_png(GtkWidget *widget, GtkWidget *select);
void		save_png(GtkWidget *widget, GdkPixbuf *pixbuf);
void		write_to_png_full(GtkWidget *widget, GtkWidget *select);
void		save_png_full(GtkWidget *widget, GdkPixbuf *pixbuf);
void		create_btn_w(t_gui_serv *gui);
void		init_win_serv(t_gui_serv *gui);
void		call_all(t_gui_serv *gui);
void		quit_res(GtkWidget *w, t_gui_serv *gui);
void		get_key_event(GtkWidget *w, GdkEventKey *event);
void		init_res_func(t_gui_serv *gui);
void		manage_call_res(t_gui_serv *gui);
void		full_res_func(GtkWidget *w, t_gui_serv *gui);
void		start_gtk(t_gui_serv *gui);
void		*my_xrealloc(char *str, int size);
char		*check_conf(char *arg);
void		fill_resol(t_gui_serv *gui, char **argv);
void		start_serv(int ac, char **argv);
int		serv_dacc(int ac, char **argv);
char		*my_read_inf(int);
t_list		*create_list(char *str);
void		add_after(t_list *list, char *str);
void		add_before(t_list *list, char *str);
void		remove_from_list(t_list *list);
void		add_to_end(t_list *list, char *str);

/* Gui */

void		quit(GtkWidget *useless, t_gui *gui);
GdkPixbuf	*load_pixbuf_from_file(char *filename);
void		edition_click();
void		init_win_rt(t_gui *gui);
void		init_button_load(t_gui *gui);
void		init_button_go(t_gui *gui);
void		*cancel_rt(GtkWidget *useless, t_gui *gui);
void		init_button_can_rt(t_gui *gui);
void		init_entry_path(t_gui *gui);
void		init_all_buttons_rt(t_gui *gui);
void		open_file(GtkWidget *useless, t_gui *gui);
char		*get_x(char *str);
char		*get_y(char *str);
char		**set_send(t_gui *gui);
void		launch_rt_go(GtkWidget *w, t_gui *gui);
void		rt_click(GtkWidget *useless, t_gui *gui);
GList		*init_resol_list();
GList		*init_antia_list();
GList		*init_cl_list();
GList		*init_mode_list();
void		*save_options(GtkWidget *useless, t_gui *gui);
void		*cancel_options(GtkWidget *useless, t_gui *gui);
void		init_win_opt(t_gui *gui);
void		init_resol(t_gui *gui);
void		init_antia(t_gui *gui);
void		init_clients_g(t_gui *gui);
void		init_mode(t_gui *gui);
void		init_all_combo(t_gui *gui);
void		init_button_ok_opt(t_gui *gui);
void		init_button_cancel_opt(t_gui *gui);
void		init_all_buttons_opt(t_gui *gui);
void		options_click(GtkWidget *useless, t_gui *gui);
void		credits_click();
void		init_sys(t_gui *gui);
void		init_b_edition(t_gui *gui);
void		init_b_rt(t_gui *gui);
void		init_b_options(t_gui *gui);
void		init_b_quit(t_gui *gui);
void		init_b_cred(t_gui *gui);
void		init_all_buttons(t_gui *gui);
void		manage_callback(t_gui *gui);
void		init_arg(t_gui *gui);

#endif /* MAIN_ */
