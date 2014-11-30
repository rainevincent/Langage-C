/*
** server_10.c for  in /home/ades_n/Workspace/raytracer/merge/server/src/core
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 03:13:38 2014 nicolas ades
** Last update Sun Jun  8 03:13:57 2014 nicolas ades
*/

#include "core.h"

void		start_gtk(t_gui_serv *gui)
{
  pthread_t	thread;

  init_win_serv(gui);
  gui->image = gtk_image_new_from_pixbuf(pixbuf);
  gtk_widget_set_size_request(gui->image, 800, 600);
  gtk_fixed_put(GTK_FIXED(gui->frame), gui->image, 50, 50);
  create_btn_w(gui);

  pthread_create(&thread, NULL, refresh_img_func, (void*)gui);
  gtk_widget_show_all(gui->window);

  g_signal_connect(G_OBJECT(gui->window), "delete-event",
		   G_CALLBACK(gtk_main_quit), NULL);
  g_signal_connect(G_OBJECT(gui->refresh_btn), "clicked",
		   G_CALLBACK(refresh_img), gui);
  g_signal_connect(G_OBJECT(gui->png_btn), "clicked",
		   G_CALLBACK(save_png), pixbuf);
  g_signal_connect(G_OBJECT(gui->jpg_btn), "clicked",
		   G_CALLBACK(save_jpg), pixbuf);
  g_signal_connect(G_OBJECT(gui->full_btn), "clicked",
		   G_CALLBACK(full_res_func), gui);

  gtk_main();
}

void            *my_xrealloc(char *str, int size)
{
  char          *new_str;

  if (str == NULL)
    exit(EXIT_FAILURE);
  if (size == 0)
    return (str);
  new_str = my_xmalloc((strlen(str) + size + 1) * sizeof(char));
  *new_str = '\0';
  my_strcat(new_str, str);
  free(str);
  return (new_str);
}

char   		*check_conf(char *arg)
{
  char		*buff;
  int		fd;

  buff = NULL;
  if ((fd = open(arg, O_RDONLY, 00644)) == -1)
    {
      fprintf(stderr, "File %s not fount\n", arg);
      exit(-1);
    }
  buff = my_read_inf(fd);
  close(fd);
  return (buff);
}

void	fill_resol(t_gui_serv *gui, char **argv)
{
  gui->width = atoi(argv[3]);
  gui->heigh = atoi(argv[4]);
  gui->twidth = 800;
  gui->theigh = 600;
}

void		start_serv(int ac, char **argv)
{
  t_gui_serv	*gui;
  pthread_t	thread;

  start = 0;
  gui = my_xmalloc(sizeof(*gui));
  gui->libserver = my_xmalloc(sizeof(t_libserver));
  gui->file = check_conf(argv[5]);
  gui->params = my_xmalloc(sizeof(*(gui->params)));
  gui->params->nb_clients = atoi(argv[2]);
  gui->params->port = atoi(argv[1]);
  gui->argv = argv;
  fill_resol(gui, argv);
  g_flag = 0;
  XInitThreads();
  gtk_init(&ac, &argv);
  pixbuf = gdk_pixbuf_new(GDK_COLORSPACE_RGB, 0, 8, 800, 600);
  pixbuff = gdk_pixbuf_new(GDK_COLORSPACE_RGB, 0, 8, gui->width, gui->heigh);
  pthread_create(&thread, NULL, server, gui);
  start_gtk(gui);
}
