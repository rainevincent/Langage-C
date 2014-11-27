/*
** server_3.c for  in /home/ades_n/Workspace/raytracer/merge/server/src/core
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 03:10:06 2014 nicolas ades
** Last update Sun Jun  8 03:10:28 2014 nicolas ades
*/

#include "core.h"

void	init_lib(t_libserver *libserver, int port)
{
  if (start == 0)
    {
      init_clients(libserver);
      printf("Server port : %d\n", port);
      libserver->portno = port;
      libserver->id_client = 0;
      if ((libserver->sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	print_error("Socket Opening failed");
      bzero((char *) &(libserver->serv_addr), sizeof(libserver->serv_addr));
      libserver->serv_addr.sin_family = AF_INET;
      libserver->serv_addr.sin_addr.s_addr = INADDR_ANY;
      libserver->serv_addr.sin_port = htons(libserver->portno);
      if (bind(libserver->sockfd, (struct sockaddr *) &(libserver->serv_addr),
	       sizeof(libserver->serv_addr)) < 0)
	print_error("Bind error");
    }
  libserver->nb_ready = 0;
  libserver->flag = 1;
  libserver->nb_finish = 0;
  libserver->tab[0] = 99;
}

void	add_client(int	id, t_libserver *libserver)
{
  libserver->clients[libserver->id_client].cli_addr = libserver->cli_addr[0];
  libserver->clients[libserver->id_client].id = id;
  libserver->clients[libserver->id_client].active = 1;
  libserver->clients[libserver->id_client].idsock = libserver->id_client;
  libserver->clients[libserver->id_client].fd =
    libserver->fds[libserver->id_client];
}

int	id_exist(int id, t_libserver *libserver)
{
  int	i;

  i = 0;
  while (i < 6)
    {
      if (libserver->clients[i].id == id && libserver->clients[i].active == 1)
	return (1);
      i++;
    }
  return (0);
}

void	send_first_data(t_libserver *libserver, int nb_cl_total, t_gui_serv *gui)
{
  int	size;

  size = strlen(gui->file);
  write(libserver->newsockfd, "Bienvenue sur le MABM_RTServer !\n",
	strlen("Bienvenue sur le MABM_RTServer !\n") + 1);
  sleep(1);
  write(libserver->newsockfd, &size, sizeof(int));
  printf("Taille cnf : %d\n", (int) strlen(gui->file));
  write(libserver->newsockfd, gui->file, strlen(gui->file));
  printf("Envoie du fichier de conf\n");
  sleep(1);
  write(libserver->newsockfd, &nb_cl_total, sizeof(int));
  printf("Envoie du nombre de clients total\n");
  sleep(1);
  write(libserver->newsockfd, &(libserver->id_client), sizeof(int));
  printf("Envoie de la position du client\n");
  write(libserver->newsockfd, &(gui->twidth), sizeof(int));
  printf("Envoie de la resolution_x\n");
  write(libserver->newsockfd, &(gui->theigh), sizeof(int));
  printf("Envoie de la resolution_y\n");
}

void	send_rest(t_libserver *libserver, t_gui_serv *gui, int i)
{
  write(libserver->clients[i].fd, &(libserver->id_client), sizeof(int));
  printf("Envoie de la position du client\n");
  write(libserver->clients[i].fd, &(gui->twidth), sizeof(int));
  printf("Envoie de la resolution_x\n");
  write(libserver->clients[i].fd, &(gui->theigh), sizeof(int));
  printf("Envoie de la resolution_y\n");
}
