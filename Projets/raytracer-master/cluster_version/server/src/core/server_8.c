/*
** server_8.c for  in /home/ades_n/Workspace/raytracer/merge/server/src/core
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 03:12:37 2014 nicolas ades
** Last update Sun Jun  8 03:13:03 2014 nicolas ades
*/

#include "core.h"

void		write_to_png_full(GtkWidget *widget, GtkWidget *select)
{
  GError	*error;
  const gchar	*path;
  char		*name;

  (void)widget;
  error = NULL;
  path = gtk_file_selection_get_filename(GTK_FILE_SELECTION(select));
  name = clear_path(path, ".png");
  gdk_pixbuf_save(pixbuff, name, "png", &error, NULL);
  widget_destroy(NULL, select);
}

void		save_png_full(GtkWidget *widget, GdkPixbuf *pixbuf)
{
  GtkWidget	*selection;

  (void)widget;
  (void)pixbuf;
  selection = gtk_file_selection_new("Path Selection");
  gtk_window_set_modal(GTK_WINDOW(selection), TRUE);
  gtk_file_selection_hide_fileop_buttons(GTK_FILE_SELECTION(selection));
  gtk_widget_show(selection);
  g_signal_connect(G_OBJECT(GTK_FILE_SELECTION(selection)->ok_button),
		   "clicked", G_CALLBACK(write_to_png_full), selection);
  g_signal_connect(G_OBJECT(GTK_FILE_SELECTION(selection)->cancel_button),
		   "clicked", G_CALLBACK(widget_destroy), selection);
}

void	create_btn_w(t_gui_serv *gui)
{
  gui->refresh_btn = gtk_button_new_with_label("Refresh");
  gtk_widget_set_size_request(gui->refresh_btn, 100, 30);
  gtk_fixed_put(GTK_FIXED(gui->frame), gui->refresh_btn, 400, 700);

  gui->png_btn = gtk_button_new_with_label("Save to PNG");
  gtk_widget_set_size_request(gui->png_btn, 100, 30);
  gtk_fixed_put(GTK_FIXED(gui->frame), gui->png_btn, 50, 700);

  gui->jpg_btn = gtk_button_new_with_label("Save to JPG");
  gtk_widget_set_size_request(gui->jpg_btn, 100, 30);
  gtk_fixed_put(GTK_FIXED(gui->frame), gui->jpg_btn, 750, 700);

  gui->full_btn = gtk_button_new_with_label("FullRes");
  gtk_widget_set_size_request(gui->full_btn, 100, 30);
  gtk_fixed_put(GTK_FIXED(gui->frame), gui->full_btn, 225, 700);
}

void	init_win_serv(t_gui_serv *gui)
{
  gui->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(gui->window), "Raytracer Server");
  gtk_window_set_default_size(GTK_WINDOW(gui->window), 900, 750);
  gtk_window_set_position(GTK_WINDOW(gui->window), GTK_WIN_POS_CENTER);
  gui->frame = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(gui->window), gui->frame);
  gui->progress = gtk_progress_bar_new();
  gtk_progress_configure(GTK_PROGRESS(gui->progress), 0, 0, 100);
  gtk_widget_set_size_request(gui->progress, 800, 30);
  gtk_fixed_put(GTK_FIXED(gui->frame), gui->progress, 50, 660);
}

void	call_all(t_gui_serv *gui)
{
  gui->twidth = gui->width;
  gui->theigh = gui->heigh;
  start = 1;
  g_flag = 0;
  g_fflag = 0;
  init_all_serv(gui->libserver, gui->params);
  send_first_data_re(gui->libserver, gui->params->nb_clients, gui);
}
