/*
** menu.c for raytracer in /home/raine_v/Projets/C/Tek1/test/gtk/editeur/src
**
** Made by Vincent Raine
** Login   <raine_v@epitech.net>
**
** Started on  Thu Jun  5 04:50:53 2014 Vincent Raine
** Last update Thu Jun  5 13:44:19 2014 Vincent Raine
*/

#include <gtk/gtk.h>
#include "callback.h"
#include "menu.h"
#include "raccourcis.h"

static void	menu_item_new (GtkMenu *, const gchar *, const gchar *, GCallback, gpointer);

GtkMenuBar	*menu_new (gpointer user_data)
{
  GtkWidget *menu_bar;

  menu_bar = gtk_menu_bar_new ();

  /* Menu "Fichier" */
  {
    GtkWidget	*menu;
    GtkWidget	*menu_item;

    menu = gtk_menu_new ();
    gtk_menu_set_accel_group (GTK_MENU (menu), accel_group_new (user_data));
    menu_item = gtk_menu_item_new_with_mnemonic ("_Fichier");
    menu_item_new (GTK_MENU (menu), "_Nouveau", ACCEL_PATH_NEW, G_CALLBACK (cb_new), user_data);
    menu_item_new (GTK_MENU (menu), "_Ouvrir", ACCEL_PATH_OPEN, G_CALLBACK (cb_open), user_data);
    menu_item_new (GTK_MENU (menu), "_Enregistrer", ACCEL_PATH_SAVE, G_CALLBACK (cb_save), user_data);
    menu_item_new (GTK_MENU (menu), "Enregistrer _sous", ACCEL_PATH_SAVEAS, G_CALLBACK (cb_saveas), user_data);
    menu_item_new (GTK_MENU (menu), "_Fermer", ACCEL_PATH_CLOSE, G_CALLBACK (cb_close), user_data);
    menu_item_new (GTK_MENU (menu), "_Quitter", ACCEL_PATH_QUIT, G_CALLBACK (cb_quit), user_data);
    gtk_menu_item_set_submenu (GTK_MENU_ITEM (menu_item), menu);
    gtk_menu_shell_append (GTK_MENU_SHELL (menu_bar), menu_item);
  }
  return GTK_MENU_BAR (menu_bar);
}

static void	menu_item_new (GtkMenu *menu, const gchar *title, const gchar *accel_path, GCallback callback, gpointer user_data)
{
  GtkWidget	*menu_item = NULL;

  menu_item = gtk_menu_item_new_with_mnemonic (title);
  gtk_menu_shell_append (GTK_MENU_SHELL (menu), menu_item);
  g_signal_connect (G_OBJECT (menu_item), "activate", callback, user_data);
  gtk_menu_item_set_accel_path (GTK_MENU_ITEM (menu_item), accel_path);
}
