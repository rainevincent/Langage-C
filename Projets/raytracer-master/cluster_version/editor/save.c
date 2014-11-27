/*
** save.c for  in /home/ades_n/Workspace/gui
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Fri Jun  6 16:37:15 2014 nicolas ades
** Last update Sun Jun  8 07:32:02 2014 Joris Bertomeu
*/

#include "editor.h"

void		create_file(GtkWidget *less, t_editor *editor)
{
  int		fd;
  const char	*path;

  (void)less;
  path =
    gtk_file_selection_get_filename(GTK_FILE_SELECTION(editor->pselection));
  fd = open(path, O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
  get_from_text_view(fd, editor);
  close (fd);
  gtk_main_quit();
}

void		my_widget_destroy(GtkWidget *useless, t_editor *editor)
{
  (void)useless;
  gtk_widget_set_sensitive(editor->pSaveBtn, TRUE);
  gtk_widget_destroy(editor->pselection);
}

void		create_save_win(GtkWidget *parent, t_editor *editor)
{
  (void)parent;
  editor->pselection = gtk_file_selection_new("Save file");
  gtk_window_set_modal(GTK_WINDOW(editor->pselection), TRUE);
  gtk_file_selection_hide_fileop_buttons(GTK_FILE_SELECTION(editor
							    ->pselection));
  gtk_window_set_position(GTK_WINDOW(editor->pselection), GTK_WIN_POS_CENTER);
  gtk_widget_show(editor->pselection);
  g_signal_connect(G_OBJECT(GTK_FILE_SELECTION(editor->pselection)->ok_button),
		   "clicked", G_CALLBACK(create_file), editor);
  g_signal_connect(G_OBJECT(GTK_FILE_SELECTION(editor->pselection)
			    ->cancel_button),
		   "clicked", G_CALLBACK(my_widget_destroy), editor);
  gtk_widget_set_sensitive(editor->pSaveBtn, FALSE);
}
