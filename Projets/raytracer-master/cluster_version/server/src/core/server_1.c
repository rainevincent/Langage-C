/*
** server_1.c for  in /home/ades_n/Workspace/raytracer/merge/server/src/core
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 03:08:38 2014 nicolas ades
** Last update Sun Jun  8 03:09:22 2014 nicolas ades
*/

#include "core.h"

void	print_error(char *str)
{
  char	*cmd;

  cmd = my_xmalloc(512 * sizeof(char));
  memset(cmd, 0, 512);
  sprintf(cmd, "%s > ", str);
  perror(cmd);
  free(cmd);
  exit(-1);
}

char	*search_ip_from_fd(t_libserver *libserver, int fd)
{
  char	*ip;
  int	i;

  i = 0;
  ip = my_xmalloc((INET_ADDRSTRLEN + 15) * sizeof(char));
  memset(ip, 0, (INET_ADDRSTRLEN + 15));
  while (i < 6)
    {
      if (libserver->clients[i].fd == fd)
	{
	  inet_ntop(AF_INET, &(libserver->clients[i].cli_addr.sin_addr.s_addr),
		    ip, INET_ADDRSTRLEN);
	}
      i++;
    }
  return (ip);
}

int	search_id_from_fd(t_libserver *libserver, int fd)
{
  int	i;

  i = 0;
  while (i < 6)
    {
      if (libserver->clients[i].fd == fd)
	return (i);
      i++;
    }
  return (-1);
}

void	send_all(t_libserver *libserver, char *addr_client, char *buff)
{
  int	i;
  char	c;

  (void)addr_client;
  if (strcmp(buff, "go") == 0)
    {
      i = 0;
      c =  0x01;
      while (i < 6)
	{
	  if (libserver->clients[i].active == 1)
	    write(libserver->clients[i].fd, &c, sizeof(char));
	  i++;
	}
    }
}

void	del_client(t_libserver *libserver, char *addr_client, int fd_ok)
{
  int	id;

  id = search_id_from_fd(libserver, fd_ok);
  libserver->clients[id].active = 0;
  libserver->clients[id].idsock = 0;
  libserver->clients[id].id = 0;
  libserver->clients[id].fd = 0;
  printf("%s a quitté la conversation\n", addr_client);
}
