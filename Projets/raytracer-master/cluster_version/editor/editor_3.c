/*
** editor_3.c for  in /home/ades_n/Workspace/raytracer/merge/editor
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 06:44:20 2014 nicolas ades
** Last update Sun Jun  8 09:00:44 2014 Joris Bertomeu
*/

#include "editor.h"

char		*add_spot(t_editor *editor)
{
  char		*final;

  final = get_final(editor);
  sprintf(&final[editor->star], "<SPOT>\n\t<POS>\n\t\t<x>%s</x>\n\t\t<y>\
%s</y>\n\t\t<z>%s</z>\n\t</POS>\n\t<COLOR>\n\t\t<r>%s</g>\
\n\t\t<g>%s</G>\n\t\t<b>%s</b>\n\t</COLOR>\n</SPOT>\n",
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pTx))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pTy))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pTz))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pR))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pG))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pB))));
  return (final);
}

char		*add_eye(t_editor *editor)
{
  char		*final;

  final = get_final(editor);
  sprintf(&final[editor->star], "<EYE>\n\t<POS>\n\t\t<x>%s</x>\n\t\t<y>\
%s</y>\n\t\t<z>%s</z>\n\t</POS>\n\t<ROT>\n\t\t<x>%s</x>\
\n\t\t<y>%s</y>\n\t\t<z>%s</z>\n\t</ROT>\n</EYE>\n",
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pTx))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pTy))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pTz))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pRx))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pRy))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pRz))));
  return (final);
}

char	*sort_number(const gchar *str)
{
  char	*final;

  final = malloc(16 * sizeof(char));
  memset(final, 0, 16);
  strcpy(final, "0");
  if (strcmp(str, "Wave") == 0)
    strcpy(final, "1");
  if (strcmp(str, "Checkerboard") == 0)
    strcpy(final, "2");
  return (final);
}

char	*add_object(t_editor *editor)
{
  char	*final;

  final = get_final(editor);
  sprintf(&final[editor->star], "<%s>\n\t<POS>\n\t\t<x>%s</x>\n\t\t<y>\
%s</y>\n\t\t<z>%s</z>\n\t</POS>\n\t<ROT>\n\t\t<x>%s</x>\
\n\t\t<y>%s</y>\n\t\t<z>%s</z>\n\t</ROT>\n\t<COLOR>\n\t\t<r>%s</g>\
\n\t\t<g>%s</G>\n\t\t<b>%s</b>\n\t</COLOR>\n\t<EFFECTS>\n\t\t<BRILL>%s</BRILL>\
\n\t\t<TRANSP>%s</TRANSP>\n\t\t<REFLEXION>%s</REFLEXION\
>\n\t\t<EFFECT>%s</EFFECT>\n\t</EFFECTS>\n\t<SIZE>%s</SIZE>\n\
</%s>\n", cts(gtk_entry_get_text(GTK_ENTRY(GTK_COMBO(editor->combo)->entry))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pTx))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pTy))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pTz))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pRx))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pRy))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pRz))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pR))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pG))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pB))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pBright))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pOpa))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->pReflex))),
	  sort_number(gtk_entry_get_text(GTK_ENTRY(GTK_COMBO(editor->pColor)->entry))),
	  cts(gtk_entry_get_text(GTK_ENTRY(editor->sizeo))),
	  cts(gtk_entry_get_text(GTK_ENTRY(GTK_COMBO(editor->combo)->entry))));
  return (final);
}

void	add_obj(GtkWidget *w, t_editor *editor)
{
  char	*final;

  (void)w;
  if (strcmp(gtk_entry_get_text(GTK_ENTRY(GTK_COMBO(editor
						    ->combo)->entry)), "SPOT") == 0)
    final = add_spot(editor);
  else if (strcmp(gtk_entry_get_text(GTK_ENTRY(GTK_COMBO(editor
							 ->combo)->entry)), "EYE") == 0)
    final = add_eye(editor);
  else
    final = add_object(editor);
  gtk_text_buffer_set_text(editor->buffer, final, (gint) strlen(final));
  gtk_text_view_set_buffer((GTK_TEXT_VIEW(editor->area)),
			   GTK_TEXT_BUFFER(editor->buffer));
}










