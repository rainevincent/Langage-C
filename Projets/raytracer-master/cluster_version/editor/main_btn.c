/*
** main_btn.c for  in /home/ades_n/Workspace/gui
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Fri Jun  6 16:34:46 2014 nicolas ades
** Last update Sun Jun  8 03:22:15 2014 Joris Bertomeu
*/

#include "editor.h"

void		quit_btn(t_editor *editor)
{
  editor->pQuitBtn = gtk_button_new_with_label("Exit");
  gtk_widget_set_size_request(editor->pQuitBtn, 100, 50);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pQuitBtn, 1100, 665);
}

void		new_btn(t_editor *editor)
{
  editor->pNewBtn = gtk_button_new_with_label("New");
  gtk_widget_set_size_request(editor->pNewBtn, 100, 50);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pNewBtn, 1100, 425);
}

void		save_btn(t_editor *editor)
{
  editor->pSaveBtn = gtk_button_new_with_label("Save");
  gtk_widget_set_size_request(editor->pSaveBtn, 100, 50);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pSaveBtn, 1100, 605);
}

void		open_btn(t_editor *editor)
{
  editor->pOpenBtn = gtk_button_new_with_label("Open");
  gtk_widget_set_size_request(editor->pOpenBtn, 100, 50);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pOpenBtn, 1100, 545);
}

void		help_btn(t_editor *editor)
{
  editor->pHelpBtn = gtk_button_new_with_label("Help");
  gtk_widget_set_size_request(editor->pHelpBtn, 100, 50);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pHelpBtn, 1100, 485);
}
