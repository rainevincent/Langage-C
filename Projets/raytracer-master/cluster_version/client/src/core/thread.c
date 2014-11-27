/*
** thread.c for  in /home/ades_n/Workspace/raytracer/merge/client/src/core
** 
** Made by nicolas ades
** Login   <ades_n@epitech.net>
** 
** Started on  Sun Jun  8 00:54:54 2014 nicolas ades
** Last update Sun Jun  8 12:30:50 2014 Jeremy Mediavilla
*/

#include "core.h"

void	init_int(t_info *info)
{
  info->j = 1;
  info->k = 0;
  info->i = 0;
}

t_pos	do_pos(int i, t_info *info)
{
  t_pos	pos;

  pos.x = i % info->x;
  pos.y = i / info->y;
  return (pos);
}

void	do_all(unsigned int *tab, t_info *info, t_pos pos)
{
  tab[info->k] = info->i;
  pos = do_pos(info->i, info);
  tab[info->k + 8] = calc_image(pos, info->scene);
  info->k++;
  if (info->j != 0 && info->j % 8 == 0)
    {
      write(info->fd_server, tab, 18 * sizeof(unsigned int));
      info->k = 0;
    }
  info->i += 4 * info->nb_clients;
  info->j++;
}

void	*calculate_pixel(void *data)
{
  t_info	*info;
  unsigned int	*tab;
  t_pos		pos;

  info = (t_info*) data;
  tab = malloc(18 * sizeof(int));
  init_int(info);
  while (info->i < 18)
    tab[info->i++] = 0;
  info->i = info->pos_me + info->current * info->nb_clients;
  printf("Thread Créé pour le core %d i = %d\n", info->current, info->i);
  tab[0] = info->i;
  tab[8] = 0x000000;
  while (info->j <= info->max[info->current] - 1)
    do_all(tab, info, pos);
  write(info->fd_server, tab, 18 * sizeof(unsigned int));
  printf("Thread %d a finit avec j = %d\n", info->current, info->j);
  return (NULL);
}

void	rcv_trames(t_libclient *slib, t_info *info)
{
  int	n;
  int	size;

  memset(slib->buffer, 0, 4096);
  n = read(slib->to_server_socket, slib->buffer, 4096);
  if (n <= 0)
    printerror("Error on Socket ..\n");
  printf("Trame de bienvenue : %s\n", slib->buffer);
  memset(slib->buffer, 0, 4096);
  n = read(slib->to_server_socket, &size, sizeof(int));
  if (n <= 0)
    printerror("Error on Socket ..\n");
  n = 0;
  info->file = malloc((size + 1) * sizeof(char));
  memset(info->file, 0, size + 1);
  while (n != size)
    n += read(slib->to_server_socket, &(info->file[n]), size - n);
  info->scene = get_scene(info->file);
  free(info->file);
  read(slib->to_server_socket, &(info->nb_clients), sizeof(int));
  memset(slib->buffer, 0, 4096);
  read(slib->to_server_socket, &(info->pos_me), sizeof(int));
  read(slib->to_server_socket, &(info->x), sizeof(int));
  read(slib->to_server_socket, &(info->y), sizeof(int));
  WIN_X = info->x;
  WIN_Y = info->y;
}
