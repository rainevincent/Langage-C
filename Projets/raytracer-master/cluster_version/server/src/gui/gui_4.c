/*
** gui_4.c for  in /home/ades_n/Workspace/raytracer/merge/server/src/gui
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 04:04:30 2014 nicolas ades
** Last update Sun Jun  8 04:51:10 2014 nicolas ades
*/

#include "core.h"

void		open_file(GtkWidget *useless, t_gui *gui)
{
  char		*filename;
  GtkWidget	*dialog;
  int		flag;

  (void)useless;
  flag = 0;
  dialog = gtk_file_chooser_dialog_new("Open File",
					(GtkWindow*) gui->rt.sys.window,
					GTK_FILE_CHOOSER_ACTION_OPEN,
					GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
					GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
					NULL);
  if (gtk_dialog_run(GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT)
    {
      flag = 1;
      filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
    }
  gtk_widget_destroy(dialog);
  if (flag == 1)
    {
      gtk_entry_set_text(GTK_ENTRY(gui->rt.buttons.entry), filename);
      g_free(filename);
    }
}

char	*get_x(char *str)
{
  int	i;
  char	*tmp;

  tmp = malloc(16 * sizeof(char));
  memset(tmp, 0, 16);
  i = 0;
  while (str[i] && str[i] != 'x')
    {
      tmp[i] = str[i];
      i++;
    }
  return (tmp);
}

char	*get_y(char *str)
{
  int	i;
  char	*tmp;
  int	j;

  j = 0;
  tmp = malloc(16 * sizeof(char));
  memset(tmp, 0, 16);
  i = 0;
  while (str[i] && str[i] != 'x')
    i++;
  i++;
  while (str[i])
    tmp[j++] = str[i++];
  return (tmp);
}

char	**set_send(t_gui *gui)
{
  char	**send;

  send = malloc(7 * sizeof(char*));
  send[0] = malloc(32 * sizeof(char));
  memset(send[0], 0, 32);
  strcpy(send[0], "./raytracer");
  send[1] = malloc(32 * sizeof(char));
  memset(send[1], 0, 32);
  strcpy(send[1], gui->args.port);
  send[2] = malloc(32 * sizeof(char));
  memset(send[2], 0, 32);
  strcpy(send[2], gui->args.nb_max);
  send[3] = malloc(32 * sizeof(char));
  memset(send[3], 0, 32);
  strcpy(send[3], get_x(gui->args.x));
  send[4] = malloc(32 * sizeof(char));
  memset(send[4], 0, 32);
  strcpy(send[4], get_y(gui->args.x));
  send[5] = malloc(2048 * sizeof(char));
  memset(send[5], 0, 2048);
  strcpy(send[5], gui->args.conf);
  send[6] = NULL;
  return (send);
}

void	launch_rt_go(GtkWidget *w, t_gui *gui)
{
  char	**send;

  (void)w;
  strcpy(gui->args.conf,
  	 gtk_entry_get_text(GTK_ENTRY(gui->rt.buttons.entry)));
  gtk_widget_set_sensitive(gui->main.sys.window, TRUE);
  gtk_widget_destroy(gui->rt.sys.window);
  send = set_send(gui);
  serv_dacc(6, send);
}
