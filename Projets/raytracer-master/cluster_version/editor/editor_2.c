/*
** editor_2.c for  in /home/ades_n/Workspace/raytracer/merge/editor
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 06:38:49 2014 nicolas ades
** Last update Sun Jun  8 06:44:10 2014 nicolas ades
*/

#include "editor.h"

void	set_all_sen_true(t_editor *editor)
{
  gtk_widget_set_sensitive(editor->pR, TRUE);
  gtk_widget_set_sensitive(editor->pG, TRUE);
  gtk_widget_set_sensitive(editor->pB, TRUE);
  gtk_widget_set_sensitive(editor->pRx, TRUE);
  gtk_widget_set_sensitive(editor->pRy, TRUE);
  gtk_widget_set_sensitive(editor->pRz, TRUE);
  gtk_widget_set_sensitive(editor->pColor, TRUE);
  gtk_widget_set_sensitive(editor->pBright, TRUE);
  gtk_widget_set_sensitive(editor->pReflex, TRUE);
  gtk_widget_set_sensitive(editor->pOpa, TRUE);
  gtk_widget_set_sensitive(editor->pColor, TRUE);
}

void	set_sen_eye(t_editor *editor)
{
  set_all_sen_true(editor);
  gtk_widget_set_sensitive(editor->pR, FALSE);
  gtk_widget_set_sensitive(editor->pG, FALSE);
  gtk_widget_set_sensitive(editor->pB, FALSE);
  gtk_widget_set_sensitive(editor->pColor, FALSE);
  gtk_widget_set_sensitive(editor->pBright, FALSE);
  gtk_widget_set_sensitive(editor->pReflex, FALSE);
  gtk_widget_set_sensitive(editor->pOpa, FALSE);
  gtk_widget_set_sensitive(editor->pColor, FALSE);
}

void	grising_cases(GtkWidget *w, t_editor *editor)
{
  (void)w;
  if (strcmp(gtk_entry_get_text(GTK_ENTRY(GTK_COMBO(editor
						    ->combo)->entry)), "SPOT") == 0)
    {
      set_all_sen_true(editor);
      gtk_widget_set_sensitive(editor->pRx, FALSE);
      gtk_widget_set_sensitive(editor->pRy, FALSE);
      gtk_widget_set_sensitive(editor->pRz, FALSE);
      gtk_widget_set_sensitive(editor->pColor, FALSE);
      gtk_widget_set_sensitive(editor->pBright, FALSE);
      gtk_widget_set_sensitive(editor->pReflex, FALSE);
      gtk_widget_set_sensitive(editor->pOpa, FALSE);
      gtk_widget_set_sensitive(editor->pColor, FALSE);
    }
  else if (strcmp(gtk_entry_get_text(GTK_ENTRY(GTK_COMBO(editor
						    ->combo)->entry)), "EYE") == 0)
    set_sen_eye(editor);
  else
    set_all_sen_true(editor);
}

char	*get_final(t_editor *editor)
{
  char		*final;
  int		star;
  GtkTextBuffer	*saved;
  GtkTextIter	start;
  GtkTextIter	end;
  char       	*text;

  saved = gtk_text_view_get_buffer(GTK_TEXT_VIEW(editor->area));
  gtk_text_buffer_get_start_iter(saved, &start);
  gtk_text_buffer_get_end_iter(saved, &end);
  text = (char *) gtk_text_buffer_get_text(saved, &start, &end, FALSE);
  star = strlen(text);
  final = malloc((star + 1024 + 2) * sizeof(char));
  memset(final, 0, (star + 1024 + 2));
  strcpy(final, text);
  editor->star = star;
  return (final);
}

char	*cts(const gchar *str)
{
  char	*tmp;

  tmp = malloc((16 + 1) * sizeof(char));
  memset(tmp, 0, 16);
  strcpy(tmp, "0");
  if (str[0] != 0)
    return ((char *)str);
  return (tmp);
}
