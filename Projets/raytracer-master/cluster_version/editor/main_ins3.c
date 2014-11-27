/*
** main_ins3.c for  in /home/ades_n/Workspace/raytracer/merge/editor
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sat Jun  7 20:13:30 2014 nicolas ades
** Last update Sat Jun  7 20:34:10 2014 nicolas ades
*/

#include "editor.h"

void		inser_r(t_editor *editor)
{
  editor->pR = gtk_entry_new();
  gtk_widget_set_size_request(editor->pR, 80, 25);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pR, 570, 338);
  editor->pLabel = gtk_label_new("R :");
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pLabel, 560, 342);
}

void		inser_g(t_editor *editor)
{
  editor->pG = gtk_entry_new();
  gtk_widget_set_size_request(editor->pG, 80, 25);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pG, 680, 338);
  editor->pLabel = gtk_label_new("G :");
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pLabel, 670, 342);
}

void		inser_b(t_editor *editor)
{
  editor->pB = gtk_entry_new();
  gtk_widget_set_size_request(editor->pB, 80, 25);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pB, 790, 338);
  editor->pLabel = gtk_label_new("B :");
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pLabel, 780, 342);
}
