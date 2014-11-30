/*
** gui_9.c for  in /home/ades_n/Workspace/raytracer/merge/server/src/gui
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 04:07:01 2014 nicolas ades
** Last update Sun Jun  8 04:07:17 2014 nicolas ades
*/

#include "core.h"

void	init_b_rt(t_gui *gui)
{
  gui->main.buttons.rt = gtk_button_new_with_label("Launch RayTracer");
  gtk_widget_set_size_request(gui->main.buttons.rt, 200, 50);
  gtk_fixed_put(GTK_FIXED(gui->main.sys.frame), gui->main.buttons.rt, 300, 150);
}

void	init_b_options(t_gui *gui)
{
  gui->main.buttons.options = gtk_button_new_with_label("Options");
  gtk_widget_set_size_request(gui->main.buttons.options, 200, 50);
  gtk_fixed_put(GTK_FIXED(gui->main.sys.frame),
		gui->main.buttons.options, 300, 250);
}

void	init_b_quit(t_gui *gui)
{
  gui->main.buttons.quit = gtk_button_new_with_label("Quit");
  gtk_widget_set_size_request(gui->main.buttons.quit, 200, 50);
  gtk_fixed_put(GTK_FIXED(gui->main.sys.frame),
		gui->main.buttons.quit, 300, 350);
}

void	init_b_cred(t_gui *gui)
{
  gui->main.buttons.cred = gtk_button_new_with_label("Credits");
  gtk_widget_set_size_request(gui->main.buttons.cred, 200, 50);
  gtk_fixed_put(GTK_FIXED(gui->main.sys.frame),
		gui->main.buttons.cred, 300, 450);
}

void	init_all_buttons(t_gui *gui)
{
  init_b_edition(gui);
  init_b_rt(gui);
  init_b_options(gui);
  init_b_quit(gui);
  init_b_cred(gui);
}
