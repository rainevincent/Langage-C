/*
** server_6.c for  in /home/ades_n/Workspace/raytracer/merge/server/src/core
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 03:11:37 2014 nicolas ades
** Last update Sun Jun  8 07:53:51 2014 Joris Bertomeu
*/

#include "core.h"

void	refresh_imgf(GtkWidget *useless, t_gui_serv *gui)
{
  (void)useless;
  gtk_image_set_from_pixbuf(GTK_IMAGE(gui->imagef), pixbuff);
  gtk_widget_show_all(gui->windowf);
}

void	*refresh_img_func_full(void *data)
{
  t_gui_serv	*gui;

  gui = data;
  g_flag = 0;
  while (g_flag == 0)
    {
      refresh_imgf(NULL, gui);
      sleep(1);
    }
  if (g_fflag == 1)
    {
      return (NULL);
    }
  refresh_imgf(NULL, gui);
  return (NULL);
}

void		*refresh_img_func(void *data)
{
  char		*final;
  t_gui_serv	*gui;

  gui = data;
  final = my_xmalloc(128 * sizeof(char));
  while (g_flag == 0)
    {
      refresh_img(NULL, gui);
      sleep(1);
    }
  memset(final, 0, 128);
  sprintf(final, "Calculé en moins de %d minute(s) et %d seconde(s)",
	  (int)(gui->finish - gui->start) / 60,
	  (int)(gui->finish - gui->start) % 60);
  refresh_img(NULL, gui);
  gui->label = gtk_label_new(final);
  gtk_fixed_put(GTK_FIXED(gui->frame),
		gui->label, 50, 20);
  gtk_widget_show_all(gui->window);
  return (NULL);
}

int		there_is_ext(const gchar *str, char *ext)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == ext[j])
	     {
	      i++;
	      j++;
	      if (j == (int)strlen(ext))
	        return (0);
	     }
      else
        i++;
    }
  return (-1);
}

void	widget_destroy(GtkWidget *w, GtkWidget *ok)
{
  (void)w;
  gtk_widget_destroy(ok);
}
