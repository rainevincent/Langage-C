/*
** main_btn2.c for  in /home/ades_n/Workspace/gui
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Fri Jun  6 16:38:45 2014 nicolas ades
** Last update Sun Jun  8 03:24:50 2014 Joris Bertomeu
*/

#include "editor.h"

void		add_btn(t_editor *editor)
{
  editor->pAddBtn = gtk_button_new_with_label("Add");
  gtk_widget_set_size_request(editor->pAddBtn, 100, 50);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pAddBtn, 950, 320);
}
