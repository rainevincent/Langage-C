/*
** main_window.c for  in /home/ades_n/Workspace/gui
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Fri Jun  6 16:33:18 2014 nicolas ades
** Last update Sun Jun  8 06:45:44 2014 nicolas ades
*/

#define _BSD_SOURCE
#include "editor.h"

void		catch_event(GtkWidget *pWidget, gpointer pData)
{
  (void)pWidget;
  (void)pData;
  gtk_main_quit();
}

void		init_window(t_editor *editor)
{
  editor->pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(editor->pWindow), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(editor->pWindow), WIN_X, WIN_Y);
  gtk_window_set_resizable(GTK_WINDOW(editor->pWindow), FALSE);
  gtk_window_set_title(GTK_WINDOW(editor->pWindow), "MABM_RT: Editor");
  editor->frame = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(editor->pWindow), editor->frame);
}

void		create_area(t_editor *editor)
{
  editor->area = gtk_text_view_new();
  gtk_widget_set_size_request(editor->area, 500, 680);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->area, 30, 40);
  editor->buffer = gtk_text_buffer_new(NULL);
}

void		create_box1(t_editor *editor)
{
  editor->pbox = gtk_frame_new("File config");
  gtk_widget_set_size_request(editor->pbox, 1080, 700);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pbox, 15, 15);
}

void		create_box2(t_editor *editor)
{
  editor->pbox2 = gtk_frame_new("RGB Color");
  gtk_widget_set_size_request(editor->pbox2, 330, 50);
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->pbox2, 550, 320);
}
