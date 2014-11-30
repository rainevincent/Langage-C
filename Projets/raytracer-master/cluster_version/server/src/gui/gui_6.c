/*
** gui_6.c for  in /home/ades_n/Workspace/raytracer/merge/server/src/gui
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 04:05:39 2014 nicolas ades
** Last update Sun Jun  8 12:26:05 2014 Joris Bertomeu
*/

#include "core.h"

void		*save_options(GtkWidget *useless, t_gui *gui)
{
  GtkWidget	*dialog;

  (void)useless;
  strcpy(gui->args.nb_max,
	 gtk_entry_get_text(GTK_ENTRY(GTK_COMBO(gui->opt.combo.nb_clients)->entry)));
  strcpy(gui->args.port,
	 gtk_entry_get_text(GTK_ENTRY(gui->opt.combo.mode)));
  strcpy(gui->args.x,
	 gtk_entry_get_text(GTK_ENTRY(GTK_COMBO(gui->opt.combo.resol)->entry)));
  strcpy(gui->args.y,
	 gtk_entry_get_text(GTK_ENTRY(GTK_COMBO(gui->opt.combo.resol)->entry)));
  strcpy(gui->args.y,
	 gtk_entry_get_text(GTK_ENTRY(gui->opt.combo.mode)));
  dialog = gtk_message_dialog_new((GtkWindow*) gui->opt.sys.window,
				  GTK_DIALOG_MODAL,
				  GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
				  "Settings saved !");
  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
  gtk_widget_set_sensitive(gui->main.sys.window, TRUE);
  gtk_widget_destroy(gui->opt.sys.window);
  return (NULL);
}

void		*cancel_options(GtkWidget *useless, t_gui *gui)
{
  (void)useless;
  gtk_widget_set_sensitive(gui->main.sys.window, TRUE);
  gtk_widget_destroy(gui->opt.sys.window);
  return (NULL);
}

void	init_win_opt(t_gui *gui)
{
  gui->opt.sys.image = load_pixbuf_from_file ("config.jpg");
  gdk_pixbuf_render_pixmap_and_mask(gui->opt.sys.image,
				    &(gui->opt.sys.background), NULL, 0);
  gui->opt.sys.style = gtk_style_new();
  gui->opt.sys.style->bg_pixmap[0] = gui->opt.sys.background;
  gui->opt.sys.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(gui->opt.sys.window), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(gui->opt.sys.window), "Raytracer - Options");
  gtk_window_set_decorated(GTK_WINDOW(gui->opt.sys.window), FALSE);
  gtk_window_set_default_size(GTK_WINDOW(gui->opt.sys.window), 350, 300);
  gtk_widget_set_style(GTK_WIDGET(gui->opt.sys.window),
		       GTK_STYLE (gui->opt.sys.style));
  gtk_window_set_transient_for(GTK_WINDOW (gui->opt.sys.window),
			       (GtkWindow*) gui->main.sys.window);
  gui->opt.sys.frame = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(gui->opt.sys.window), gui->opt.sys.frame);
}

void	init_resol(t_gui *gui)
{
  gui->opt.list.list_resol = init_resol_list();
  gui->opt.labels.resol_l = gtk_label_new("Resolution : ");
  gtk_fixed_put(GTK_FIXED(gui->opt.sys.frame), gui->opt.labels.resol_l, 30, 50);
  gui->opt.combo.resol = gtk_combo_new();
  gtk_entry_set_editable(GTK_ENTRY(GTK_COMBO(gui->opt.combo.resol)->entry),
			 FALSE);
  gtk_combo_set_popdown_strings(GTK_COMBO(gui->opt.combo.resol),
				gui->opt.list.list_resol) ;
  gtk_entry_set_text(GTK_ENTRY(GTK_COMBO(gui->opt.combo.resol)->entry),
		     "800x600");
  gtk_fixed_put(GTK_FIXED(gui->opt.sys.frame), gui->opt.combo.resol, 150, 45);
}

void	init_antia(t_gui *gui)
{
  gui->opt.list.list_antia = init_antia_list();
  gui->opt.labels.antialias_l = gtk_label_new("Antialiasing : ");
  gtk_fixed_put(GTK_FIXED(gui->opt.sys.frame),
		gui->opt.labels.antialias_l, 30, 100);
  gui->opt.combo.antialias = gtk_combo_new();
  gtk_entry_set_editable(GTK_ENTRY(GTK_COMBO(gui->opt.combo.antialias)->entry),
			 FALSE);
  gtk_combo_set_popdown_strings(GTK_COMBO(gui->opt.combo.antialias),
				gui->opt.list.list_antia) ;
  gtk_entry_set_text(GTK_ENTRY(GTK_COMBO(gui->opt.combo.antialias)->entry),
		     "x2");
  gtk_fixed_put(GTK_FIXED(gui->opt.sys.frame), gui->opt.combo.antialias,
		150, 95);
}
