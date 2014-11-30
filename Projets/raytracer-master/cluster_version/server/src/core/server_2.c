/*
** server_2.c for  in /home/ades_n/Workspace/raytracer/merge/server/src/core
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 03:09:31 2014 nicolas ades
** Last update Sun Jun  8 18:20:08 2014 Geoffrey Merran
*/

#include "core.h"

void		pixel_put_to_pixbuf(GdkPixbuf *pixbuf, int x, int y, guchar *tab)
{
  int		rowstride;
  int		n_channels;
  guchar	*pixel;
  guchar	*p;

  n_channels = gdk_pixbuf_get_n_channels(pixbuf);
  rowstride = gdk_pixbuf_get_rowstride(pixbuf);
  pixel = gdk_pixbuf_get_pixels(pixbuf);
  p = pixel + y * rowstride + x *n_channels;
  p[0] = tab[2];
  p[1] = tab[1];
  p[2] = tab[0];
}

void		stock_clr_img(t_libserver *libserver, t_gui_serv *gui)
{
  int		i;
  t_pos		count;
  t_union	trans;

   i = 0;
  while (i < 8)
    {
      if (((int*) libserver->tab)[i] == 0 &&
	  ((int*) libserver->tab)[i + 8] == 0)
	return ;
      count.x = ((int*) libserver->tab)[i] % gui->twidth;
      count.y = ((int*) libserver->tab)[i] / gui->twidth;
      trans.clr = ((int*) libserver->tab)[i + 8];
      if (start == 0)
	pixel_put_to_pixbuf(pixbuf, count.x, count.y, (guchar *) trans.color);
      else
	pixel_put_to_pixbuf(pixbuff, count.x, count.y, (guchar *) trans.color);
      i++;
    }
}

void	do_finish(t_libserver *libserver, t_gui_serv *gui)
{
  libserver->nb_finish++;
  if (libserver->nb_finish == libserver->cl_total)
    {
      time(&(gui->finish));
      libserver->flag = 0;
      g_flag = 1;
    }
}

void		parse_line(char *buff, int fd_ok, t_libserver *libserver, t_gui_serv *gui)
{
  char		*addr_client;
  static int	cmptr = 0;

  addr_client = search_ip_from_fd(libserver, fd_ok);
  if (strcmp(buff, "bye") == 0)
    del_client(libserver, addr_client, fd_ok);
  else if (((int*) libserver->tab)[0] == 1080 * 1920 + 100)
    {
      libserver->nb_ready++;
      if (libserver->nb_ready == libserver->cl_total)
	send_all(libserver, addr_client, "go");
    }
  else if (((int*) libserver->tab)[0] == 1080 * 1920 + 200)
    do_finish(libserver, gui);
  else
    {
      stock_clr_img(libserver, gui);
      if (cmptr == 0)
	time(&(gui->start));
      cmptr += 8;
        /*     if (start == 0) */
      	/* gtk_progress_set_percentage(GTK_PROGRESS(gui->progress), */
      	/* 		    (gfloat)(cmptr) / (800 * 600)); */
    }
  free(addr_client);
}

void	init_clients(t_libserver *libserver)
{
  int	i;

  i = 0;
  while (i < 6)
    {
      libserver->clients[i].active = 0;
      libserver->clients[i].id = 0;
      libserver->clients[i].idsock = 0;
      libserver->clients[i].fd = 0;
      i++;
    }
}
