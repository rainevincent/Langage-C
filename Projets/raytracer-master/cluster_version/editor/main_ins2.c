/*
** main_ins2.c for  in /home/ades_n/Workspace/gui
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Fri Jun  6 16:35:53 2014 nicolas ades
** Last update Sun Jun  8 08:56:56 2014 Joris Bertomeu
*/

#include "editor.h"

void		inser_rx(t_editor *editor)
{
  editor->pRx = gtk_entry_new();
  gtk_widget_set_size_request(editor->pRx, 80, 25);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pRx, 785, 75);
  editor->pLabel = gtk_label_new("R.x :");
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pLabel, 750, 80);

  editor->sizeo = gtk_entry_new();
  gtk_widget_set_size_request(editor->sizeo, 80, 25);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->sizeo, 940, 75);
  editor->sizeol = gtk_label_new("Size :");
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->sizeol, 900, 80);

}

void		inser_ry(t_editor *editor)
{
  editor->pRy = gtk_entry_new();
  gtk_widget_set_size_request(editor->pRy, 80, 25);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pRy, 785, 120);
  editor->pLabel = gtk_label_new("R.y :");
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pLabel, 750, 125);
}

void		inser_rz(t_editor *editor)
{
  editor->pRz = gtk_entry_new();
  gtk_widget_set_size_request(editor->pRz, 80, 25);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pRz, 785, 170);
  editor->pLabel = gtk_label_new("R.z :");
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pLabel, 750, 175);
}

void		inser_opacity(t_editor *editor)
{
  editor->pOpa = gtk_entry_new();
  gtk_widget_set_size_request(editor->pOpa, 80, 25);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pOpa, 615, 265);
  editor->pLabel = gtk_label_new("Opacity :");
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pLabel, 550, 270);
}

void		inser_reflexion(t_editor *editor)
{
  editor->pReflex = gtk_entry_new();
  gtk_widget_set_size_request(editor->pReflex, 80, 25);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pReflex, 830, 265);
  editor->pLabel = gtk_label_new("Reflexion :");
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pLabel, 750, 270);
}
