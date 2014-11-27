/*
** gui_8.c for  in /home/ades_n/Workspace/raytracer/merge/server/src/gui
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 04:06:37 2014 nicolas ades
** Last update Sun Jun  8 04:53:46 2014 nicolas ades
*/

#include "core.h"

void	init_all_buttons_opt(t_gui *gui)
{
  init_button_ok_opt(gui);
  init_button_cancel_opt(gui);
}

void	options_click(GtkWidget *useless, t_gui *gui)
{
  (void)useless;
  gtk_widget_set_sensitive(gui->main.sys.window, FALSE);
  init_win_opt(gui);
  init_all_combo(gui);
  init_all_buttons_opt(gui);
  gtk_widget_show_all(gui->opt.sys.window);
  g_signal_connect(G_OBJECT(gui->opt.sys.window), "delete-event",
		   G_CALLBACK(cancel_options), gui);
  g_signal_connect(G_OBJECT(gui->opt.buttons.ok_btn), "clicked",
		   G_CALLBACK(save_options), gui);
  g_signal_connect(G_OBJECT(gui->opt.buttons.can_btn), "clicked",
		   G_CALLBACK(cancel_options), gui);
  gtk_main();
}

void	credits_click()
{
  printf("Credits_click\n");
}

void	init_sys(t_gui *gui)
{
  gui->main.sys.image = load_pixbuf_from_file ("img.jpg");
  gdk_pixbuf_render_pixmap_and_mask(gui->main.sys.image,
				    &(gui->main.sys.background), NULL, 0);
  gui->main.sys.style = gtk_style_new();
  gui->main.sys.style->bg_pixmap[0] = gui->main.sys.background;
  gui->main.sys.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(gui->main.sys.window), "Raytracer Launcher");
  gtk_window_set_decorated(GTK_WINDOW(gui->main.sys.window), FALSE);
  gtk_window_set_default_size(GTK_WINDOW (gui->main.sys.window), 800, 600);
  gtk_window_set_position(GTK_WINDOW(gui->main.sys.window), GTK_WIN_POS_CENTER);
  gtk_widget_set_style(GTK_WIDGET(gui->main.sys.window),
		       GTK_STYLE (gui->main.sys.style));
  gtk_window_set_transient_for(GTK_WINDOW (gui->main.sys.window), NULL);
  gui->main.sys.frame = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(gui->main.sys.window), gui->main.sys.frame);
}

void	init_b_edition(t_gui *gui)
{
  gui->main.buttons.edition = gtk_button_new_with_label("Edition");
  gtk_widget_set_size_request(gui->main.buttons.edition, 200, 50);
  gtk_fixed_put(GTK_FIXED(gui->main.sys.frame),
		gui->main.buttons.edition, 300, 50);
}
