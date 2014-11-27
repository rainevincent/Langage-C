/*
** main_ins.c for  in /home/ades_n/Workspace/gui
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Fri Jun  6 16:35:09 2014 nicolas ades
** Last update Sun Jun  8 06:48:26 2014 nicolas ades
*/

#include "editor.h"

GList		*create_list_effects()
{
  GList		*list;

  list = NULL;
  list = g_list_append(list, g_strdup_printf("None"));
  list = g_list_append(list, g_strdup_printf("Wave"));
  list = g_list_append(list, g_strdup_printf("Checkerboard"));
  list = g_list_append(list, g_strdup_printf("Earth"));
  list = g_list_append(list, g_strdup_printf("Wind"));
  list = g_list_append(list, g_strdup_printf("Fire"));
  list = g_list_append(list, g_strdup_printf("Spotto"));
  return (list);
}

void		inser_color(t_editor *editor)
{

  editor->pColor = gtk_combo_new();
  gtk_entry_set_editable(GTK_ENTRY(GTK_COMBO(editor->pColor)->entry), FALSE);
  gtk_combo_set_popdown_strings(GTK_COMBO(editor->pColor),
				create_list_effects());
  gtk_entry_set_text(GTK_ENTRY(GTK_COMBO(editor->pColor)->entry),
		     "None");
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pColor, 605, 220);
  editor->pLabel = gtk_label_new("Effects :");
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pLabel, 550, 225);
}

void		inser_Brightness(t_editor *editor)
{
  editor->pBright = gtk_entry_new();
  gtk_widget_set_size_request(editor->pBright, 80, 25);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pBright, 900, 220);
  editor->pLabel = gtk_label_new("Brightness :");
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pLabel, 810, 225);
}

void		inser_tx(t_editor *editor)
{
  editor->pTx = gtk_entry_new();
  gtk_widget_set_size_request(editor->pTx, 80, 25);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pTx, 585, 75);
  editor->pLabel = gtk_label_new("T.x :");
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pLabel, 550, 80);
}

void		inser_ty(t_editor *editor)
{
  editor->pTy = gtk_entry_new();
  gtk_widget_set_size_request(editor->pTy, 80, 25);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pTy, 585, 120);
  editor->pLabel = gtk_label_new("T.y :");
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pLabel, 550, 125);
}

