/*
** gui_5.c for  in /home/ades_n/Workspace/raytracer/merge/server/src/gui
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 04:05:03 2014 nicolas ades
** Last update Sun Jun  8 04:51:44 2014 nicolas ades
*/

#include "core.h"

void	rt_click(GtkWidget *useless, t_gui *gui)
{
  (void)useless;
  gtk_widget_set_sensitive(gui->main.sys.window, FALSE);
  init_win_rt(gui);
  init_all_buttons_rt(gui);
  gtk_widget_show_all(gui->rt.sys.window);
  g_signal_connect(G_OBJECT(gui->rt.sys.window), "delete-event",
		   G_CALLBACK(gtk_main_quit), NULL);
  g_signal_connect(G_OBJECT(gui->rt.buttons.load), "clicked",
		   G_CALLBACK(open_file), gui);
  g_signal_connect(G_OBJECT(gui->rt.buttons.can), "clicked",
		   G_CALLBACK(cancel_rt), gui);
  g_signal_connect(G_OBJECT(gui->rt.buttons.go), "clicked",
		   G_CALLBACK(launch_rt_go), gui);
  gtk_main();
}

GList	*init_resol_list()
{
  GList	*list;

  list = NULL;
  list = g_list_append(list, g_strdup_printf("800x600"));
  list = g_list_append(list, g_strdup_printf("1024x768"));
  list = g_list_append(list, g_strdup_printf("1280x800"));
  list = g_list_append(list, g_strdup_printf("1280x1024"));
  list = g_list_append(list, g_strdup_printf("1920x1080"));
  list = g_list_append(list, g_strdup_printf("1440x900"));
  list = g_list_append(list, g_strdup_printf("1680x1050"));
  list = g_list_append(list, g_strdup_printf("1920x1080"));
  return (list);
}

GList	*init_antia_list()
{
  GList	*list;

  list = NULL;
  list = g_list_append(list, g_strdup_printf("x2"));
  list = g_list_append(list, g_strdup_printf("x4"));
  list = g_list_append(list, g_strdup_printf("x8"));
  list = g_list_append(list, g_strdup_printf("x16"));
  return (list);
}

GList	*init_cl_list()
{
  GList	*list;

  list = NULL;
  list = g_list_append(list, g_strdup_printf("1"));
  list = g_list_append(list, g_strdup_printf("2"));
  list = g_list_append(list, g_strdup_printf("3"));
  list = g_list_append(list, g_strdup_printf("4"));
  list = g_list_append(list, g_strdup_printf("5"));
  list = g_list_append(list, g_strdup_printf("6"));
  return (list);
}

GList	*init_mode_list()
{
  GList	*list;

  list = NULL;
  list = g_list_append(list, g_strdup_printf("Sépia"));
  list = g_list_append(list, g_strdup_printf("Noir & Blanc"));
  list = g_list_append(list, g_strdup_printf("Andy Warhol"));
  list = g_list_append(list, g_strdup_printf("Surexposé"));
  list = g_list_append(list, g_strdup_printf("Balance des blancs"));
  return (list);
}
