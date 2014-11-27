/*
** editor.c for  in /home/ades_n/Workspace/gui
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Wed Jun  4 13:21:49 2014 nicolas ades
** Last update Sun Jun  8 08:53:05 2014 Joris Bertomeu
*/

#include "editor.h"

GList		*create_list()
{
  GList		*list;

  list = NULL;
  list = g_list_append(list, g_strdup_printf("SPHERE"));
  list = g_list_append(list, g_strdup_printf("PLAN"));
  list = g_list_append(list, g_strdup_printf("CYLINDRE"));
  list = g_list_append(list, g_strdup_printf("CONE"));
  list = g_list_append(list, g_strdup_printf("EYE"));
  list = g_list_append(list, g_strdup_printf("SPOT"));
  return (list);
}

void		create_combo(t_editor *editor)
{
  editor->combo = gtk_combo_new();
  gtk_entry_set_editable(GTK_ENTRY(GTK_COMBO(editor->combo)->entry), FALSE);
  gtk_combo_set_popdown_strings(GTK_COMBO(editor->combo), create_list());
  gtk_entry_set_text(GTK_ENTRY(GTK_COMBO(editor->combo)->entry), "SPHERE");
  gtk_fixed_put(GTK_FIXED(editor->frame), editor->combo, 550, 30);
}

void		generate_editor(t_editor *editor)
{
  quit_btn(editor);
  save_btn(editor);
  open_btn(editor);
  help_btn(editor);
  new_btn(editor);
  add_btn(editor);
  create_box1(editor);
  create_box2(editor);
  inser_tx(editor);
  inser_ty(editor);
  inser_tz(editor);
  inser_rx(editor);
  inser_ry(editor);
  inser_rz(editor);
  inser_color(editor);
  inser_Brightness(editor);
  inser_opacity(editor);
  inser_reflexion(editor);
  inser_r(editor);
  inser_g(editor);
  inser_b(editor);
  create_area(editor);
  create_combo(editor);
  catch_sig(editor);
}

void		editor(int ac, char **av)
{
  t_editor	*editor;

  editor = malloc(sizeof(t_editor));
  gtk_init(&ac, &av);
  init_window(editor);
  editor->list = create_list();
  generate_editor(editor);
  gtk_widget_show_all(editor->pWindow);
  gtk_main();
}
