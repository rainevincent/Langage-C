/*
** barreoutils.c for raytracer in /home/raine_v/Projets/C/Tek1/test/gtk/editeur/src
**
** Made by Vincent Raine
** Login   <raine_v@epitech.net>
**
** Started on  Thu Jun  5 04:49:54 2014 Vincent Raine
** Last update Thu Jun  5 13:28:13 2014 Vincent Raine
*/

#include <gtk/gtk.h>
#include "callback.h"
#include "barreoutils.h"

static void	toolbar_item_new (GtkToolbar *, const gchar *, GCallback, gpointer);

GtkToolbar	*toolbar_new (gpointer user_data)
{
  GtkWidget	*toolbar;

  toolbar = gtk_toolbar_new ();
  gtk_toolbar_set_style (GTK_TOOLBAR (toolbar), GTK_TOOLBAR_ICONS);
  toolbar_item_new (GTK_TOOLBAR (toolbar), GTK_STOCK_NEW, G_CALLBACK (cb_new), user_data);
  toolbar_item_new (GTK_TOOLBAR (toolbar), GTK_STOCK_OPEN, G_CALLBACK (cb_open), user_data);
  toolbar_item_new (GTK_TOOLBAR (toolbar), GTK_STOCK_SAVE, G_CALLBACK (cb_save), user_data);
  toolbar_item_new (GTK_TOOLBAR (toolbar), GTK_STOCK_SAVE_AS, G_CALLBACK (cb_saveas), user_data);
  toolbar_item_new (GTK_TOOLBAR (toolbar), GTK_STOCK_CLOSE, G_CALLBACK (cb_close), user_data);
  toolbar_item_new (GTK_TOOLBAR (toolbar), GTK_STOCK_QUIT, G_CALLBACK (cb_quit), user_data);
  return GTK_TOOLBAR (toolbar);
}

static void	toolbar_item_new (GtkToolbar *toolbar, const gchar *stock_id, GCallback callback, gpointer user_data)
{
  GtkToolItem	*tool_item;

  tool_item = gtk_tool_button_new_from_stock (stock_id);
  g_signal_connect (G_OBJECT (tool_item), "clicked", callback, user_data);
  gtk_toolbar_insert (toolbar, tool_item, -1);
}
