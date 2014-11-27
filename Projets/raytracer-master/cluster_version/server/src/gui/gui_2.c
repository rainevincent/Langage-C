/*
** gui_2.c for  in /home/ades_n/Workspace/raytracer/merge/server/src/gui
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 04:03:31 2014 nicolas ades
** Last update Sun Jun  8 04:46:24 2014 nicolas ades
*/

#include "core.h"

GdkPixbuf	*load_pixbuf_from_file(char *filename)
{
  GError	*error;
  GdkPixbuf	*pixbuf;

  error = NULL;
  pixbuf = gdk_pixbuf_new_from_file(filename, &error);
  if (pixbuf == NULL)
    {
      g_print("Error loading file: %d : %s\n", error->code, error->message);
      g_error_free(error);
      exit(1);
    }
  return (pixbuf);
}

void	quit(GtkWidget *useless, t_gui *gui)
{
  (void)useless;
  (void)gui;
  exit(0);
}

void	edition_click()
{
  printf("Edition_click\n");
}

void	init_win_rt(t_gui *gui)
{
  gui->rt.sys.image = load_pixbuf_from_file ("launching.jpg");
  gdk_pixbuf_render_pixmap_and_mask(gui->rt.sys.image,
				    &(gui->rt.sys.background), NULL, 0);
  gui->rt.sys.style = gtk_style_new();
  gui->rt.sys.style->bg_pixmap[0] = gui->rt.sys.background;
  gui->rt.sys.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(gui->rt.sys.window), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(gui->rt.sys.window), "Raytracer - Launching");
  gtk_window_set_decorated(GTK_WINDOW(gui->rt.sys.window), FALSE);
  gtk_window_set_default_size(GTK_WINDOW(gui->rt.sys.window), 400, 200);
  gtk_widget_set_style(GTK_WIDGET(gui->rt.sys.window),
		       GTK_STYLE (gui->rt.sys.style));
  gtk_window_set_transient_for(GTK_WINDOW (gui->rt.sys.window),
			       (GtkWindow*) gui->main.sys.window);
  gui->rt.sys.frame = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(gui->rt.sys.window), gui->rt.sys.frame);
}

void	init_button_load(t_gui *gui)
{
  gui->rt.buttons.load = gtk_button_new_with_label("Open File");
  gtk_widget_set_size_request(gui->rt.buttons.load, 80, 30);
  gtk_fixed_put(GTK_FIXED(gui->rt.sys.frame),
		gui->rt.buttons.load, 300, 30);
}
