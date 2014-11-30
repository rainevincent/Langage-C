/*
** communication.c for  in /home/ades_n/Workspace/raytracer/merge/client/src/core
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 00:55:48 2014 nicolas ades
** Last update Sun Jun  8 01:02:31 2014 nicolas ades
*/

#define _BSD_SOURCE
#include "core.h"

void	calculate_pix_core(t_info *info, int total)
{
  int	i;
  int	pix_img;

  pix_img = info->pix_img / info->nb_clients;
  i = 0;
  while (i < 4)
    {
      if (i != info->nb_core - 1)
	{
	  info->pix_by_core[i] = pix_img / 4;
	  total -= pix_img / 4;
	}
      else
	info->pix_by_core[i] = total;
      info->max[i] = info->pix_by_core[i];
      printf("[%d] = %d --- Core %d Calcule : %d pixels\n",
	     i, info->max[i], i + 1, info->pix_by_core[i]);
      i++;
    }
}

void	wait_rep(t_libclient *slib)
{
  int	c;

  c = 0;
  while (1)
    {
      read(slib->to_server_socket, &c, sizeof(char));
      if (c == 0x7f01 || c == 0x01)
	break;
      else
	{
	  printf("Bad start trame : %x\n", c);
	  exit(-1);
	}
    }
}

void	create_threads(t_info *info, pthread_t *threads)
{
  int	i;

  i = 0;
  while (i < 4)
    {
      info->current = i;
      pthread_create(&(threads[i]), NULL, calculate_pixel, info);
      pthread_join(threads[i], NULL);
      i++;
    }
}

void		fill(char **argv, t_libclient *slib, t_info *info)
{
  int		pix_img;
  pthread_t	*threads;
  int		total;
  unsigned int	tab[18];

  tab[0] = 1080 * 1920 + 100;
  if (start == 0)
    init_lib(slib, argv[1], atoi(argv[2]));
  slib->flag = 1;
  info->fd_server = slib->to_server_socket;
  rcv_trames(slib, info);
  pix_img = info->x * info->y;
  info->pix_img = pix_img;
  info->pix_by_core = malloc(4 * sizeof(int));
  total = info->pix_img;
  calculate_pix_core(info, total);
  threads = malloc(4 * sizeof(*threads));
  usleep(100);
  write(slib->to_server_socket, &tab, 18 * sizeof(unsigned int));
  wait_rep(slib);
  create_threads(info, threads);
  my_putstr("\rPixel Color calculation done !\n");
  tab[0] = 1920 * 1080 + 200;
  write(slib->to_server_socket, &tab, 18 * sizeof(unsigned int));
}

void	printerror(char *msg)
{
  fprintf(stderr, msg);
  exit(-1);
}
