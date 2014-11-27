/*
** server_5.c for  in /home/ades_n/Workspace/raytracer/merge/server/src/core
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 03:11:08 2014 nicolas ades
** Last update Sun Jun  8 18:03:48 2014 Jeremy Mediavilla
*/

#include "core.h"

void	do_sock_client(t_libserver *libserver, fd_set rfds, t_gui_serv *gui)
{
  int	i;
  int	tmp;
  int	total;

  i = 0;
  tmp = 1;
  total = 18 * sizeof(unsigned int);
  while (i < 6)
    {
      libserver->n = 0;
      if (FD_ISSET(libserver->fds[i], &rfds) == 1)
	{
	  memset(libserver->buffer, 0, 4096);
	  while (libserver->n != total && tmp > 0)
	    {
	      tmp = read(libserver->fds[i], &(libserver->tab[libserver->n]),
			 total - libserver->n);
	      libserver->n += tmp;
	    }
	  if (libserver->n <= 0)
	    print_error("Socket Read error");
	  else
	    {
	      libserver->current_id_fd = i;
	      parse_line(libserver->buffer, libserver->fds[i], libserver, gui);
	      return;
	    }
	}
      i++;
    }
}

void	init_all_serv(t_libserver *libserver, t_params *params)
{
  init_lib(libserver, params->port);
  if (start == 0)
    {
      libserver->cl_total = params->nb_clients;
      init_fds(libserver);
      listen(libserver->sockfd, 5);
      printf("Waiting connection on port %d ...\n", libserver->portno);
    }
}

void	decision(t_gui_serv *gui, fd_set rfds, t_libserver *libserver)
{
  if (FD_ISSET(libserver->sockfd, &rfds) == 1)
    do_sock_fd(libserver, gui->params->nb_clients, gui);
  else
    do_sock_client(libserver, rfds, gui);
}

void		*server(void *ok)
{
  t_libserver	*libserver;
  t_gui_serv	*gui;
  fd_set	rfds;
  int		retval;
  int		max;

  libserver = my_xmalloc(sizeof(*libserver));
  gui = ok;
  libserver = gui->libserver;
  init_all_serv(libserver, gui->params);
  while (1)
    {
      max = init_fd(&rfds, libserver);
      retval = select(max, &rfds, NULL, NULL, 0);
      if (retval == -1)
	printf("Error : Select\n");
      else if (retval == EINTR)
	printf("Signal Caught\n");
      else if (retval <= 6)
	decision(gui, rfds, libserver);
      else
	printf("Error - Max : %d retval : %d\n", max, retval);
    }
  return (0);
}

void	refresh_img(GtkWidget *useless, t_gui_serv *gui)
{
  (void)useless;
  gtk_image_set_from_pixbuf(GTK_IMAGE(gui->image), pixbuf);
  gtk_widget_show_all(gui->window);
}
