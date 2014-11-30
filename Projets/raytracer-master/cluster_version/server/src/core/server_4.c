/*
** server_4.c for  in /home/ades_n/Workspace/raytracer/merge/server/src/core
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 03:10:37 2014 nicolas ades
** Last update Sun Jun  8 03:11:01 2014 nicolas ades
*/

#include "core.h"

void	send_first_data_re(t_libserver *libserver, int nb_cl_total,
			   t_gui_serv *gui)
{
  int	size;
  int	i;

  i = 0;
  size = strlen(gui->file);
  while (i < 6)
    {
      if (libserver->clients[i].active == 1)
	{
	  write(libserver->clients[i].fd, "Bienvenue sur le MABM_RTServer !\n",
		strlen("Bienvenue sur le MABM_RTServer !\n") + 1);
	  sleep(1);
	  write(libserver->clients[i].fd, &size, sizeof(int));
	  printf("Taille cnf : %d\n", (int) strlen(gui->file));
	  write(libserver->clients[i].fd, gui->file, strlen(gui->file));
	  printf("Envoie du fichier de conf\n");
	  sleep(1);
	  write(libserver->clients[i].fd, &nb_cl_total, sizeof(int));
	  printf("Envoie du nombre de clients total\n");
	  sleep(1);
	  send_rest(libserver, gui, i);
	}
      i++;
    }
}

void		check_new_client(t_libserver *libserver, int nb_cl_total, t_gui_serv *gui)
{
  char		*addr_client;

  addr_client = my_xmalloc(INET_ADDRSTRLEN * sizeof(*addr_client));
  if (id_exist(libserver->cli_addr[0].sin_addr.s_addr, libserver) == 0)
    {
      if (libserver->id_client >= 5)
	printf("Number maximum of player reached\n");
      else
	{
	  inet_ntop(AF_INET, &(libserver->cli_addr[0].sin_addr.s_addr),
		    addr_client, INET_ADDRSTRLEN);
	  printf("-------------------\nNouveau client : %s\
\n-------------------\n\n", addr_client);
	  send_first_data(libserver, nb_cl_total, gui);
	  libserver->fds[libserver->id_client] = libserver->newsockfd;
	  add_client(libserver->cli_addr[0].sin_addr.s_addr, libserver);
	  libserver->id_client++;
	}
    }
  free(addr_client);
}

void	init_fds(t_libserver *libserver)
{
  int	i;

  i = 0;
  while (i < 6)
    libserver->fds[i++] = 0;
}

int	init_fd(fd_set	*rfds, t_libserver *libserver)
{
  int	i;
  int	max;

  i = 0;
  max = libserver->sockfd + 1;
  FD_ZERO(rfds);
  FD_SET(libserver->sockfd, rfds);
  while (i < libserver->id_client)
    {
      FD_SET(libserver->fds[i], rfds);
      max = (libserver->fds[i] >= max) ? libserver->fds[i] + 1 : max;
      i++;
    }
  return (max);
}

void	do_sock_fd(t_libserver *libserver, int client_max, t_gui_serv *gui)
{
  libserver->clilen = sizeof(libserver->cli_addr[0]);
  libserver->newsockfd = accept(libserver->sockfd,
				(struct sockaddr *)&(libserver->cli_addr[0]),
				(socklen_t*) &(libserver->clilen));
  check_new_client(libserver, client_max, gui);
  if (libserver->newsockfd < 0)
    print_error("Acception client error");
}
