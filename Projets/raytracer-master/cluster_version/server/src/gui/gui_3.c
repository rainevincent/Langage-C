/*
** gui_3.c for  in /home/ades_n/Workspace/raytracer/merge/server/src/gui
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 04:04:03 2014 nicolas ades
** Last update Sun Jun  8 04:47:54 2014 nicolas ades
*/

#include "core.h"

void	init_button_go(t_gui *gui)
{
  gui->rt.buttons.go = gtk_button_new_with_label("Start Raycasting !");
  gtk_widget_set_size_request(gui->rt.buttons.go, 120, 30);
  gtk_fixed_put(GTK_FIXED(gui->rt.sys.frame),
		gui->rt.buttons.go, 230, 80);
}

void		*cancel_rt(GtkWidget *useless, t_gui *gui)
{
  (void)useless;
  gtk_widget_set_sensitive(gui->main.sys.window, TRUE);
  gtk_widget_destroy(gui->rt.sys.window);
  return (NULL);
}

void	init_button_can_rt(t_gui *gui)
{
  gui->rt.buttons.can = gtk_button_new_with_label("Cancel");
  gtk_widget_set_size_request(gui->rt.buttons.can, 120, 30);
  gtk_fixed_put(GTK_FIXED(gui->rt.sys.frame),
		gui->rt.buttons.can, 50, 80);
}

void	init_entry_path(t_gui *gui)
{
  gui->rt.buttons.entry = gtk_entry_new();
  gtk_widget_set_size_request(gui->rt.buttons.entry, 280, 30);
  gtk_fixed_put(GTK_FIXED(gui->rt.sys.frame),
		gui->rt.buttons.entry, 20, 30);
}

void	init_all_buttons_rt(t_gui *gui)
{
  init_button_load(gui);
  init_entry_path(gui);
  init_button_go(gui);
  init_button_can_rt(gui);
}
