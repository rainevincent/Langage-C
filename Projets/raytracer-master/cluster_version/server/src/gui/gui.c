/*
** main.c for paint in /home/jobertomeu/Work/raytracer/graphic
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Tue Jun  3 12:48:10 2014 Joris Bertomeu
** Last update Sun Jun  8 04:08:37 2014 nicolas ades
*/

#include "core.h"

void	manage_callback(t_gui *gui)
{
  g_signal_connect(G_OBJECT(gui->main.sys.window), "delete-event",
		   G_CALLBACK(quit), gui);
  gtk_signal_connect (GTK_OBJECT (gui->main.buttons.edition), "clicked",
                      GTK_SIGNAL_FUNC (edition_click), NULL);
  gtk_signal_connect (GTK_OBJECT (gui->main.buttons.quit), "clicked",
                      G_CALLBACK(quit), NULL);
  gtk_signal_connect (GTK_OBJECT (gui->main.buttons.rt), "clicked",
                      GTK_SIGNAL_FUNC (rt_click), gui);
  gtk_signal_connect (GTK_OBJECT (gui->main.buttons.options), "clicked",
                      GTK_SIGNAL_FUNC (options_click), gui);
  gtk_signal_connect (GTK_OBJECT (gui->main.buttons.cred), "clicked",
                      GTK_SIGNAL_FUNC (credits_click), NULL);
}

void	init_arg(t_gui *gui)
{
  gui->args.port = malloc(16 * sizeof(char));
  memset(gui->args.port, 0, 16);
  strcpy(gui->args.port, "33669");
  gui->args.nb_max = malloc(8 * sizeof(char));
  memset(gui->args.nb_max, 0, 8);
  strcpy(gui->args.nb_max, "1");
  gui->args.x = malloc(16 * sizeof(char));
  memset(gui->args.x, 0, 16);
  strcpy(gui->args.x, "800x600");
  gui->args.y = malloc(16 * sizeof(char));
  memset(gui->args.y, 0, 16);
  strcpy(gui->args.y, "800x600");
  gui->args.conf = malloc(2048 * sizeof(char));
  memset(gui->args.conf, 0, 2048);
  strcpy(gui->args.conf, "naz");
}

int main (int argc, char *argv[])
{
  t_gui		*gui;

  gui = malloc(sizeof(*gui));
  gtk_init(&argc, &argv);
  init_arg(gui);
  init_sys(gui);
  init_all_buttons(gui);
  manage_callback(gui);
  gtk_widget_show_all(gui->main.sys.window);
  gtk_main();
  return 0;
}
