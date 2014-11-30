/*
** raccourcis.c for raytracer in /home/raine_v/Projets/C/Tek1/test/gtk/editeur/src
**
** Made by Vincent Raine
** Login   <raine_v@epitech.net>
**
** Started on  Thu Jun  5 04:51:12 2014 Vincent Raine
** Last update Thu Jun  5 13:58:14 2014 Vincent Raine
*/

#include <gtk/gtk.h>
#include "callback.h"
#include "document.h"
#include "raccourcis.h"

static void	accelerator_new (GtkAccelGroup *, const gchar *, const gchar *, GCallback, gpointer);
static gboolean	accel_new (GtkAccelGroup *, GObject *, guint keyval, GdkModifierType, gpointer);
static gboolean	accel_open (GtkAccelGroup *, GObject *, guint keyval, GdkModifierType, gpointer);
static gboolean	accel_save (GtkAccelGroup *, GObject *, guint keyval, GdkModifierType, gpointer);
static gboolean	accel_saveas (GtkAccelGroup *, GObject *, guint keyval, GdkModifierType, gpointer);
static gboolean	accel_close (GtkAccelGroup *, GObject *, guint keyval, GdkModifierType, gpointer);
static gboolean	accel_quit (GtkAccelGroup *, GObject *, guint keyval, GdkModifierType, gpointer);

GtkAccelGroup	*accel_group_new (gpointer user_data)
{
  GtkAccelGroup	*accel_group = NULL;

  accel_group = gtk_accel_group_new ();
  accelerator_new (accel_group, "<Control>N", ACCEL_PATH_NEW, G_CALLBACK (accel_new), user_data);
  accelerator_new (accel_group, "<Control>O", ACCEL_PATH_OPEN, G_CALLBACK (accel_open), user_data);
  accelerator_new (accel_group, "<Control>S", ACCEL_PATH_SAVE, G_CALLBACK (accel_save), user_data);
  accelerator_new (accel_group, "<Control><Shift>S", ACCEL_PATH_SAVEAS, G_CALLBACK (accel_saveas), user_data);
  accelerator_new (accel_group, "<Control>W", ACCEL_PATH_CLOSE, G_CALLBACK (accel_close), user_data);
  accelerator_new (accel_group, "<Control>Q", ACCEL_PATH_QUIT, G_CALLBACK (accel_quit), user_data);
  gtk_window_add_accel_group (docs.main_window, accel_group);
  return (accel_group);
}

static void	accelerator_new (GtkAccelGroup *accel_group, const gchar *accelerator, const gchar *accel_path,
				 GCallback callback, gpointer user_data)
{
  guint	key;
  GdkModifierType	mods;
  GClosure	*closure;

  gtk_accelerator_parse (accelerator, &key, &mods);
  closure = g_cclosure_new (callback, user_data, NULL);
  gtk_accel_group_connect (accel_group, key, mods, GTK_ACCEL_VISIBLE, closure);
  gtk_accel_map_add_entry (accel_path, key, mods);
}

static gboolean	accel_new (GtkAccelGroup *accel_group, GObject *acceleratable,
			   guint keyval, GdkModifierType modifier, gpointer user_data)
{
  cb_new (NULL, user_data);

  /* parametres inutilises */
  (void)accel_group;
  (void)acceleratable;
  (void)keyval;
  (void)modifier;
  (void)user_data;

  return (TRUE);
}

static gboolean accel_open (GtkAccelGroup *accel_group, GObject *acceleratable,
			    guint keyval, GdkModifierType modifier, gpointer user_data)
{
  cb_open (NULL, user_data);

  /* parametres inutilises */
  (void)accel_group;
  (void)acceleratable;
  (void)keyval;
  (void)modifier;
  (void)user_data;

  return (TRUE);
}

static gboolean	accel_save (GtkAccelGroup *accel_group, GObject *acceleratable,
			    guint keyval, GdkModifierType modifier, gpointer user_data)
{
  cb_save (NULL, user_data);

  /* parametres inutilises */
  (void)accel_group;
  (void)acceleratable;
  (void)keyval;
  (void)modifier;
  (void)user_data;

  return (TRUE);
}

static gboolean	accel_saveas (GtkAccelGroup *accel_group, GObject *acceleratable,
			      guint keyval, GdkModifierType modifier, gpointer user_data)
{
  cb_saveas (NULL, user_data);

  /* parametres inutilises */
  (void)accel_group;
  (void)acceleratable;
  (void)keyval;
  (void)modifier;
  (void)user_data;

  return (TRUE);
}

static gboolean	accel_close (GtkAccelGroup *accel_group, GObject *acceleratable,
			     guint keyval, GdkModifierType modifier, gpointer user_data)
{
  cb_close (NULL, user_data);

  /* parametres inutilises */
  (void)accel_group;
  (void)acceleratable;
  (void)keyval;
  (void)modifier;
  (void)user_data;

  return (TRUE);
}

static gboolean accel_quit (GtkAccelGroup *accel_group, GObject *acceleratable,
			    guint keyval, GdkModifierType modifier, gpointer user_data)
{
  cb_quit (NULL, user_data);

  /* parametres inutilises */
  (void)accel_group;
  (void)acceleratable;
  (void)keyval;
  (void)modifier;
  (void)user_data;

  return (TRUE);
}
