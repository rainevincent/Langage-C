/*
** help.c for  in /home/ades_n/Workspace/gui
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Fri Jun  6 16:36:34 2014 nicolas ades
** Last update Sun Jun  8 03:24:57 2014 Joris Bertomeu
*/

#include "editor.h"

void		my_gtk_main_quit(GtkWidget *W, t_editor *editor)
{
  (void)W;
  gtk_widget_set_sensitive(editor->pHelpBtn, TRUE);
  gtk_main_quit();
}

void		create_help_win(GtkWidget *parent, t_editor *editor)
{
  (void)parent;
  editor->pWinHelp = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(editor->pWinHelp), GTK_WIN_POS_NONE);
  gtk_window_set_default_size(GTK_WINDOW(editor->pWinHelp), 300, 600);
  gtk_window_set_title(GTK_WINDOW(editor->pWinHelp), "Editor Help");
  editor->Helpframe = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(editor->pWinHelp), editor->Helpframe);
  gtk_widget_show_all(editor->pWinHelp);
  gtk_widget_set_sensitive(editor->pHelpBtn, FALSE);
  g_signal_connect(G_OBJECT(editor->pWinHelp), "destroy",
		   G_CALLBACK(my_gtk_main_quit), editor);
  gtk_main();
}
