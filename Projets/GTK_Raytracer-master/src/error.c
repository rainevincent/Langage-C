/*
** error.c for raytracer in /home/raine_v/Projets/C/Tek1/test/gtk/editeur/src
**
** Made by Vincent Raine
** Login   <raine_v@epitech.net>
**
** Started on  Thu Jun  5 04:50:21 2014 Vincent Raine
** Last update Fri Jun  6 15:47:22 2014 Vincent Raine
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "document.h"
#include "error.h"

static void	print_message (GtkMessageType, const gchar *, va_list);

void	print_info (char *format, ...)
{
  va_list	va;

  va_start (va, format);
  print_message (GTK_MESSAGE_INFO, format, va);
}

void	print_warning (char *format, ...)
{
  va_list	va;

  va_start (va, format);
  print_message (GTK_MESSAGE_WARNING, format, va);
}

void	print_error (char *format, ...)
{
  va_list	va;

  va_start (va, format);
  print_message (GTK_MESSAGE_ERROR, format, va);
  exit (EXIT_FAILURE);
}

static void	print_message (GtkMessageType type, const gchar *format, va_list va)
{
  gchar	*message;
  GtkWidget	*dialog;

  message = g_strdup_printf (format, va);
  dialog = gtk_message_dialog_new (docs.main_window, GTK_DIALOG_MODAL, type, GTK_BUTTONS_OK, message);
  g_free (message), message = NULL;
  gtk_dialog_run (GTK_DIALOG (dialog));
  gtk_widget_destroy (dialog);
}
