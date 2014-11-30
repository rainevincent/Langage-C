/*
** editor_4.c for  in /home/ades_n/Workspace/raytracer/merge/editor
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 06:45:22 2014 nicolas ades
** Last update Sun Jun  8 06:48:25 2014 nicolas ades
*/

#include "editor.h"

void		inser_tz(t_editor *editor)
{
  editor->pTz = gtk_entry_new();
  gtk_widget_set_size_request(editor->pTz, 80, 25);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pTz, 585, 170);
  editor->pLabel = gtk_label_new("T.z :");
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pLabel, 550, 175);
}

void		catch_sig(t_editor *editor)
{
  g_signal_connect(G_OBJECT(editor->pWindow),
		   "destroy", G_CALLBACK(catch_event), NULL);
  g_signal_connect(G_OBJECT(editor->pQuitBtn),
		   "clicked", G_CALLBACK(gtk_main_quit), NULL);
  g_signal_connect(G_OBJECT(editor->pHelpBtn),
		   "clicked", G_CALLBACK(create_help_win), editor);
  g_signal_connect(G_OBJECT(editor->pSaveBtn),
		   "clicked", G_CALLBACK(create_save_win), editor);
  g_signal_connect(G_OBJECT(editor->pAddBtn),
		   "clicked", G_CALLBACK(add_obj), editor);
  g_signal_connect(G_OBJECT(GTK_COMBO(editor->combo)->entry),
		   "changed", G_CALLBACK(grising_cases), editor);
}
