/*
** init2.c for  in /home/mediav_j/corewar/asm/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sun Apr 13 15:06:13 2014 Jeremy Mediavilla
** Last update Sun Apr 13 15:06:44 2014 Jeremy Mediavilla
*/

#include "assembleur.h"
#include "gnl.h"

void	free_struct(t_system *sys)
{
  int	i;

  i = 0;
  free(sys->name);
  free(sys->name_file);
  free(sys->comment);
  free(sys->final_name);
  free(sys->ins.str);
  while (i < sys->cl)
    free(sys->labels[i++].name);
  i = 0;
  while (i < sys->col)
    free(sys->olabels[i++].name);
}

void		init(int ac, char **argv)
{
  int		i;
  t_system	*system;

  i = 1;
  system = xmalloc(sizeof(*system));
  check_ext(ac, argv);
  init_start(system);
  while (i < ac)
    {
      system->comment = 0;
      system->name = 0;
      my_strcpy(system->name_file, argv[i]);
      tread_file(argv[i], system);
      aff_info(system, argv[i++]);
    }
  free_struct(system);
  free(system);
}

void		header_init1(int *j, t_system *sys, int fd, int *i)
{
  char		c;

  c = 0x0;
  sys->f_n = 1;
  *j = (int) lseek(fd, 0, SEEK_CUR);
  xwrite(fd, sys->name, my_strlen(sys->name));
  *i = (int) lseek(fd, 0, SEEK_CUR) - *j;
  *j = 0;
  while (*j < PROG_NAME_LENGTH - *i)
    {
      xwrite(fd, &c, 1);
      (*j)++;
    }
  my_printf(">> Name wrote ( %d/%i octets, Total %d octets )\n", *i,
	 PROG_NAME_LENGTH, (int) lseek(fd, 0, SEEK_CUR));
}

char		*init_tab_char()
{
  char		*tab;

  tab = xmalloc(17 * sizeof(char));
  tab[0] = 0x1;
  tab[1] = 0x2;
  tab[2] = 0x3;
  tab[3] = 0x4;
  tab[4] = 0x5;
  tab[5] = 0x6;
  tab[6] = 0x7;
  tab[7] = 0x8;
  tab[8] = 0x9;
  tab[9] = 0xa;
  tab[10] = 0xb;
  tab[11] = 0xc;
  tab[12] = 0xd;
  tab[13] = 0xe;
  tab[14] = 0xf;
  tab[15] = 0x10;
  tab[16] = '\0';
  return (tab);
}

void	init_dataf(int *neg, int *j, int *k, int *i)
{
  *neg = 1;
  *j = *i;
  *k = 0;
}
