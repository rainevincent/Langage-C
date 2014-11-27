/*
** push_in_file.c for  in /home/ades_n/Workspace/raytracer/merge/editor
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sat Jun  7 18:41:24 2014 nicolas ades
** Last update Sun Jun  8 06:48:43 2014 nicolas ades
*/

#include "editor.h"

void		get_from_text_view(int fd, t_editor *editor)
{
  GtkTextIter start;
  GtkTextIter end;
  GtkTextBuffer *buffer;
  gchar *text;

  buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(editor->area));
  gtk_text_buffer_get_bounds(buffer, &start, &end);
  text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
  write(fd, text, strlen(text));
}
