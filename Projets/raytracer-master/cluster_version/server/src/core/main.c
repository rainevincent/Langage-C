/*
** main.c for  in /home/merran_g/work/c_piscine/mkdir
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Fri Oct  4 09:11:03 2013 Geoffrey Merran
** Last update Sun Jun  8 12:29:01 2014 Joris Bertomeu
*/

#include "core.h"

GdkPixbuf	*pixbuf;
GdkPixbuf	*pixbuff;
int		g_flag;
int		start;
int		g_fflag;

int		serv_dacc(int ac, char **argv)
{
  if (ac != 6)
    {
      printf("USAGE: ./rt_server <Port> <Nb_clients_max>\
 <Width> <Heigh> <Conf File>\n");
      exit(-1);
    }
  else if (atoi(argv[1]) >= 1 && atoi(argv[1]) <= 999999
	   && atoi(argv[2]) >= 1 && atoi(argv[2]) <= 6)
    start_serv(ac, argv);
  else
    {
      printf("You must enter a valid port and a number maximum of 6 peers\n");
      exit(-1);
    }
  g_flag = 1;
  return (0);
}
