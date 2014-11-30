/*
** main.c for raytracer in /home/raine_v/Projets/C/Tek1/test/gtk/editeur/src
**
** Made by Vincent Raine
** Login   <raine_v@epitech.net>
**
** Started on  Thu Jun  5 04:50:33 2014 Vincent Raine
** Last update Fri Jun  6 12:03:19 2014 Vincent Raine
*/

#include <stdlib.h>
#include <gtk/gtk.h>
#include "barreoutils.h"
#include "callback.h"
#include "document.h"
#include "menu.h"

docs_t	docs = {NULL, NULL, NULL};

int	main (int argc, char **argv)
{
  GtkWidget	*main_window = NULL;
  GtkWidget *main_box = NULL;
  GtkWidget *text_view = NULL;

  /* Initialisation de GTK+ */
  gtk_init (&argc, &argv);

  /* Creation de la fenetre principale de notre application */
  main_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(main_window), 950, 850);
  gtk_window_set_position(GTK_WINDOW(main_window), GTK_WIN_POS_CENTER);
  gtk_window_set_title (GTK_WINDOW (main_window), "Raytracer - Editeur fichier Conf");
  g_signal_connect (G_OBJECT (main_window), "destroy", G_CALLBACK (cb_quit), NULL);
  docs.main_window = GTK_WINDOW (main_window);

  /* Creation du conteneur principal */
  main_box = gtk_vbox_new (FALSE, 0);
  gtk_container_add (GTK_CONTAINER (main_window), main_box);

  text_view = gtk_text_view_new ();

  /* Creation du menu */
  gtk_box_pack_start (GTK_BOX (main_box), GTK_WIDGET (menu_new (text_view)), FALSE, FALSE, 0);

  /* Creation de la barre d'outils */
  gtk_box_pack_start (GTK_BOX (main_box), GTK_WIDGET (toolbar_new (text_view)), FALSE, FALSE, 0);

  /* Creation de la zone de texte */
  {
    GtkTextBuffer	*text_buffer;
    GtkWidget	*scroll_window;

    scroll_window = gtk_scrolled_window_new (NULL, NULL);
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scroll_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_box_pack_start (GTK_BOX (main_box), scroll_window, TRUE, TRUE, 0);
    text_buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (text_view));
    g_signal_connect (G_OBJECT (text_buffer), "changed", G_CALLBACK (cb_modifie), NULL);
    gtk_widget_set_sensitive (text_view, FALSE);
    gtk_container_add (GTK_CONTAINER (scroll_window), text_view);
  }

  /* Affichage de la fenetre principale */
  gtk_widget_show_all (main_window);
  /* Lancement de la boucle principale */
  gtk_main ();
  return (EXIT_SUCCESS);
}
