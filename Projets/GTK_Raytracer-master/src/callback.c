/*
** callback.c for raytracer in /home/raine_v/Projets/C/Tek1/test/gtk/editeur/src
**
** Made by Vincent Raine
** Login   <raine_v@epitech.net>
**
** Started on  Thu Jun  5 04:50:09 2014 Vincent Raine
** Last update Thu Jun  5 14:01:36 2014 Vincent Raine
*/

#include "callback.h"
#include "document.h"
#include "error.h"

static void	open_file (const gchar *, GtkTextView *);

void	cb_new (GtkWidget *p_widget, gpointer user_data)
{
  if (docs.actif)
    cb_close (p_widget, user_data);

  /* Pour l'instant il faut allouer la memoire, par la suite on modifiera
     simplement le pointeur */
  docs.actif = g_malloc (sizeof (*docs.actif));
  docs.actif->path = NULL;
  /* Pour l'instant, on se contente de stocker le seul GtkTextView qui existe,
    par la suite, il faudra en creer un nouveau ! */
  docs.actif->text_view = GTK_TEXT_VIEW (user_data);
  /* Le document vient d'etre creer, il n'est donc pas modifie */
  docs.actif->sauve = TRUE;
  gtk_widget_set_sensitive (GTK_WIDGET (docs.actif->text_view), TRUE);
}

void	cb_open (GtkWidget *p_widget, gpointer user_data)
{
  GtkWidget	*dialog;
  dialog = gtk_file_chooser_dialog_new ("Ouvrir un fichier", NULL,
                                          GTK_FILE_CHOOSER_ACTION_OPEN,
                                          GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                          GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
                                          NULL);
  if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT)
  {
    gchar	*file_name;

    file_name = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
    open_file (file_name, GTK_TEXT_VIEW (user_data));
    g_free (file_name), file_name = NULL;
  }
  gtk_widget_destroy (dialog);

  /* Parametre inutilise */
  (void)p_widget;
}

void	cb_save (GtkWidget *p_widget, gpointer user_data)
{
  if (docs.actif)
  {
    if (!docs.actif->sauve)
    {
      /* Le fichier n'a pas encore ete enregistre */
      if (!docs.actif->path)
      {
        GtkWidget	*dialog;

        dialog = gtk_file_chooser_dialog_new ("Sauvegarder le fichier", NULL,
                                                GTK_FILE_CHOOSER_ACTION_SAVE,
                                                GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                                GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT,
                                                NULL);
        if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT)
        {
          docs.actif->path = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
        }
        gtk_widget_destroy (dialog);
      }
      /* Soit le fichier a deja ete enregistre, soit l'utilisateur vient de nous
         fournir son nouvel emplacement, on peut donc l'enregistrer */
      if (docs.actif->path)
      {
        FILE *fichier;

        fichier = fopen (docs.actif->path, "w");
        if (fichier)
        {
          gchar	*contents;
          gchar	*locale;
          GtkTextIter	start;
          GtkTextIter	end;
          GtkTextBuffer	*text_buffer;

          text_buffer = gtk_text_view_get_buffer (docs.actif->text_view);
          gtk_text_buffer_get_bounds (text_buffer, &start, &end);
          contents = gtk_text_buffer_get_text (text_buffer, &start, &end, FALSE);
          locale = g_locale_from_utf8 (contents, -1, NULL, NULL, NULL);
          g_free (contents), contents = NULL;
          fprintf (fichier, "%s", locale);
          g_free (locale), locale = NULL;
          fclose (fichier), fichier = NULL;
          docs.actif->sauve = TRUE;
        }
        else
          print_warning ("Impossible de sauvegarder le fichier %s", docs.actif->path);
      }
    }
  }
  else
    print_warning ("Aucun document ouvert");

  /* Parametres inutilises */
  (void)p_widget;
  (void)user_data;
}

void	cb_saveas (GtkWidget *p_widget, gpointer user_data)
{
  if (docs.actif)
  {
    document_t	tmp = *docs.actif;

    docs.actif->path = NULL;
    docs.actif->sauve = FALSE;
    cb_save (p_widget, user_data);
    if (!docs.actif->sauve)
      (*docs.actif) = tmp;
  }
  else
    print_warning ("Aucun document ouvert");
}

void	cb_close (GtkWidget *p_widget, gpointer user_data)
{
  /* Avant de fermer, il faut verifier qu'un document a bien ete ouvert */
  if (docs.actif)
  {
    if (!docs.actif->sauve)
    {
      GtkWidget	*dialog;
      GtkWidget	*p_label;

      dialog = gtk_dialog_new_with_buttons ("Sauvegarder",
                                              docs.main_window,
                                              GTK_DIALOG_MODAL,
                                              GTK_STOCK_YES, GTK_RESPONSE_YES,
                                              GTK_STOCK_NO, GTK_RESPONSE_NO,
                                              GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, NULL);
      p_label = gtk_label_new ("Voulez-vous sauvegarder les modifications ?");
      gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog)->vbox), p_label, TRUE, TRUE, 0);
      gtk_widget_show_all (GTK_DIALOG (dialog)->vbox);
      switch (gtk_dialog_run (GTK_DIALOG (dialog)))
      {
        case GTK_RESPONSE_YES:
          cb_save (p_widget, user_data);
        break;
        case GTK_RESPONSE_NO:
        break;
        case GTK_RESPONSE_CANCEL:
          gtk_widget_destroy (dialog);
        break;
      }
      gtk_widget_destroy (dialog);
    }
    {
      GtkTextIter	start;
      GtkTextIter	end;
      GtkTextBuffer	*text_buffer;

      text_buffer = gtk_text_view_get_buffer (docs.actif->text_view);
      gtk_text_buffer_get_bounds (text_buffer, &start, &end);
      gtk_text_buffer_delete (text_buffer, &start, &end);
      gtk_widget_set_sensitive (GTK_WIDGET (docs.actif->text_view), FALSE);
      g_free (docs.actif->path), docs.actif->path = NULL;
      docs.actif->text_view = NULL;
      g_free (docs.actif), docs.actif = NULL;
    }
  }
  else
    print_warning ("Aucun document ouvert");

  /* Parametres inutilises */
  (void)p_widget;
  (void)user_data;
}

void	cb_quit (GtkWidget *p_widget, gpointer user_data)
{
  if (docs.actif)
    cb_close (p_widget, user_data);
  if (!docs.actif)
    gtk_main_quit();
}

void	cb_modifie (GtkWidget *p_widget, gpointer user_data)
{
  if (docs.actif)
    docs.actif->sauve = FALSE;

  /* Parametres inutilises */
  (void)p_widget;
  (void)user_data;
}

static void	open_file (const gchar *file_name, GtkTextView *text_view)
{
  g_return_if_fail (file_name && text_view);
  {
    gchar	*contents = NULL;

    if (g_file_get_contents (file_name, &contents, NULL, NULL))
    {
      /* Copie de contents dans le GtkTextView */
      gchar	*utf8;
      GtkTextIter	iter;
      GtkTextBuffer	*text_buffer;

      cb_new (NULL, text_view);
      docs.actif->path = g_strdup (file_name);
      gtk_widget_set_sensitive (GTK_WIDGET (docs.actif->text_view), TRUE);
      text_buffer = gtk_text_view_get_buffer (text_view);
      gtk_text_buffer_get_iter_at_line (text_buffer, &iter, 0);
      utf8 = g_locale_to_utf8 (contents, -1, NULL, NULL, NULL);
      g_free (contents), contents = NULL;
      gtk_text_buffer_insert (text_buffer, &iter, utf8, -1);
      g_free (utf8), utf8 = NULL;

      /* obliges de remetre save a TRUE car insertion du contenu
         du fichier dans le GtkTextView a appele cb_modfie */
      docs.actif->sauve = TRUE;
    }
    else
      print_warning ("Impossible d'ouvrir le fichier %s\n", file_name);
  }
}
