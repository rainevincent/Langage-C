/*
** main.c for rt in /home/jobertomeu/Work/raytracer/merge/client
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun Jun  8 12:15:00 2014 Joris Bertomeu
** Last update Sun Jun  8 12:19:59 2014 Joris Bertomeu
*/

#define _BSD_SOURCE
#include "core.h"

int	WIN_X;
int	WIN_Y;
int	start;

void	check_arg(int ac, char **argv)
{
  if (ac != 3)
    printerror("Usage : ./clientrt <ServerIP> <Port>\n");
  if (atoi(argv[2]) <= 0 && atoi(argv[2]) >= 99999999)
    printerror("Port number must be > 0 and < 99999999\n");
}

int		main(int ac, char **argv)
{
  /* int		fd; */
  /* char		*buf; */

  /* (void)ac; */
  /* fd = open(argv[1], O_RDONLY); */
  /* buf = my_read_inf(fd); */
  /* close(fd); */
  /* get_scene(buf); */
  t_libclient	*slib;
  t_info	*info;

  check_arg(ac, argv);
  info = malloc(sizeof(t_info));
  slib = malloc(sizeof(t_libclient));
  start = 0;
  while (1)
    {
      fill(argv, slib, info);
      start = 1;
    }
  return (0);
}
