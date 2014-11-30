/*
** server_7.c for  in /home/ades_n/Workspace/raytracer/merge/server/src/core
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 03:12:06 2014 nicolas ades
** Last update Sun Jun  8 03:12:24 2014 nicolas ades
*/

#include "core.h"

gchar		*clear_path(const gchar *str, char *ext)
{
  char		*res;

  if (!str)
    return (NULL);
  if (there_is_ext(str, ext) != 0)
    {
      res = my_xmalloc((strlen((char *)str) + strlen(ext)) * sizeof(*res));
      strcpy(res, (char *)str);
      res = strcat(res, ext);
      return (res);
    }
  else
    {
      res = my_xmalloc((strlen((char *)str) + 1) * sizeof(*res));
      strcpy(res, (char *) str);
      return (res);
    }
}

void		write_to_jpg(GtkWidget *widget, GtkWidget *select)
{
  GError	*error;
  const gchar	*path;
  char		*name;

  (void)widget;
  (void)select;
  error = NULL;
  path = gtk_file_selection_get_filename(GTK_FILE_SELECTION(select));
  name = clear_path(path, ".jpeg");
  gdk_pixbuf_save(pixbuf, name, "jpeg", &error, NULL);
  widget_destroy(NULL, select);
}

void		save_jpg(GtkWidget *widget, GdkPixbuf *pixbuf)
{
  GtkWidget	*selection;

  (void)widget;
  (void)pixbuf;
  selection = gtk_file_selection_new("Path Selection");
  gtk_window_set_modal(GTK_WINDOW(selection), TRUE);
  gtk_file_selection_hide_fileop_buttons(GTK_FILE_SELECTION(selection));
  gtk_widget_show(selection);
  g_signal_connect(G_OBJECT(GTK_FILE_SELECTION(selection)->ok_button),
		   "clicked", G_CALLBACK(write_to_jpg), selection);
  g_signal_connect(G_OBJECT(GTK_FILE_SELECTION(selection)->cancel_button),
		   "clicked", G_CALLBACK(widget_destroy), selection);
}

void		write_to_png(GtkWidget *widget, GtkWidget *select)
{
  GError	*error;
  const gchar	*path;
  char		*name;

  (void)widget;
  error = NULL;
  path = gtk_file_selection_get_filename(GTK_FILE_SELECTION(select));
  name = clear_path(path, ".png");
  gdk_pixbuf_save(pixbuf, name, "png", &error, NULL);
  widget_destroy(NULL, select);
}

void		save_png(GtkWidget *widget, GdkPixbuf *pixbuf)
{
  GtkWidget	*selection;

  (void)widget;
  (void)pixbuf;
  selection = gtk_file_selection_new("Path Selection");
  gtk_window_set_modal(GTK_WINDOW(selection), TRUE);
  gtk_file_selection_hide_fileop_buttons(GTK_FILE_SELECTION(selection));
  gtk_widget_show(selection);
  g_signal_connect(G_OBJECT(GTK_FILE_SELECTION(selection)->ok_button),
		   "clicked", G_CALLBACK(write_to_png), selection);
  g_signal_connect(G_OBJECT(GTK_FILE_SELECTION(selection)->cancel_button),
		   "clicked", G_CALLBACK(widget_destroy), selection);
}
