/*
** gui_7.c for  in /home/ades_n/Workspace/raytracer/merge/server/src/gui
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 04:06:12 2014 nicolas ades
** Last update Sun Jun  8 04:06:31 2014 nicolas ades
*/

#include "core.h"

void	init_clients_g(t_gui *gui)
{
  gui->opt.list.list_client = init_cl_list();
  gui->opt.labels.nb_clients_l = gtk_label_new("Nombre clients : ");
  gtk_fixed_put(GTK_FIXED(gui->opt.sys.frame),
		gui->opt.labels.nb_clients_l, 30, 150);
  gui->opt.combo.nb_clients = gtk_combo_new();
  gtk_entry_set_editable(GTK_ENTRY(GTK_COMBO(gui->opt.combo.nb_clients)->entry),
			 FALSE);
  gtk_combo_set_popdown_strings(GTK_COMBO(gui->opt.combo.nb_clients),
				gui->opt.list.list_client) ;
  gtk_entry_set_text(GTK_ENTRY(GTK_COMBO(gui->opt.combo.nb_clients)->entry),
		     "1");
  gtk_fixed_put(GTK_FIXED(gui->opt.sys.frame), gui->opt.combo.nb_clients,
		150, 145);
}

void	init_mode(t_gui *gui)
{
  gui->opt.list.list_mode = init_mode_list();
  gui->opt.labels.mode_l = gtk_label_new("Port : ");
  gtk_fixed_put(GTK_FIXED(gui->opt.sys.frame), gui->opt.labels.mode_l, 30, 200);
  gui->opt.combo.mode = gtk_entry_new();
  gtk_widget_set_size_request(gui->opt.combo.mode, 185, 30);
  gtk_fixed_put(GTK_FIXED(gui->opt.sys.frame), gui->opt.combo.mode, 150, 195);
}

void	init_all_combo(t_gui *gui)
{
  init_resol(gui);
  init_antia(gui);
  init_clients_g(gui);
  init_mode(gui);
}

void	init_button_ok_opt(t_gui *gui)
{
  gui->opt.buttons.ok_btn = gtk_button_new_with_label("OK");
  gtk_widget_set_size_request(gui->opt.buttons.ok_btn, 100, 25);
  gtk_fixed_put(GTK_FIXED(gui->opt.sys.frame),
		gui->opt.buttons.ok_btn, 50, 250);
}

void	init_button_cancel_opt(t_gui *gui)
{
  gui->opt.buttons.can_btn = gtk_button_new_with_label("Cancel");
  gtk_widget_set_size_request(gui->opt.buttons.can_btn, 100, 25);
  gtk_fixed_put(GTK_FIXED(gui->opt.sys.frame),
		gui->opt.buttons.can_btn, 200, 250);
}
