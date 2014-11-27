/*
** server_9.c for  in /home/ades_n/Workspace/raytracer/merge/server/src/core
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 03:13:14 2014 nicolas ades
** Last update Sun Jun  8 04:45:10 2014 nicolas ades
*/

#include "core.h"

void	quit_res(GtkWidget *w, t_gui_serv *gui)
{
  (void)gui;
  g_flag = 1;
  g_fflag = 1;
  gtk_widget_destroy(w);
}

void	get_key_event(GtkWidget *w, GdkEventKey *event)
{
  if (strcmp(gdk_keyval_name(event->keyval), "Escape") == 0)
    quit_res(w, NULL);
  if (strcmp(gdk_keyval_name(event->keyval), "s") == 0)
    save_png_full(w, pixbuff);
}

void		init_res_func(t_gui_serv *gui)
{
  gui->windowf = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(gui->windowf), "Raytracer Server - FULLRES");
  gtk_window_set_decorated(GTK_WINDOW(gui->windowf), FALSE);
  gtk_window_fullscreen(GTK_WINDOW(gui->windowf));
}

void		manage_call_res(t_gui_serv *gui)
{
  g_signal_connect(G_OBJECT(gui->windowf), "delete-event",
		   G_CALLBACK(quit_res), gui);
  g_signal_connect(G_OBJECT(gui->windowf), "key-release-event",
		   G_CALLBACK(get_key_event), NULL);
}

void		full_res_func(GtkWidget *w, t_gui_serv *gui)
{
  GtkWidget	*frame;
  pthread_t	thread;
  GdkScreen	*screen;
  int		x;
  int		y;

  (void)w;
  call_all(gui);
  gtk_rc_parse("./sys/rc.cnf");
  init_res_func(gui);
  frame = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(gui->windowf), frame);
  gui->imagef = gtk_image_new_from_pixbuf(pixbuff);
  gtk_widget_set_size_request(gui->imagef, gui->width, gui->heigh);
  screen = gdk_screen_get_default();
  x = gdk_screen_get_width(screen);
  y = gdk_screen_get_height(screen);
  gtk_fixed_put(GTK_FIXED(frame), gui->imagef,
		(gint)((x / 2) - (gui->width / 2)),
		(gint)((y / 2) - (gui->heigh / 2)));
  pthread_create(&thread, NULL, refresh_img_func_full, gui);
  gtk_widget_show_all(gui->windowf);
  manage_call_res(gui);
  gtk_main();
}
