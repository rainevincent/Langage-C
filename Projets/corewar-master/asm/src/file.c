/*
** file.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:33:49 2014 Jeremy Mediavilla
** Last update Sat Apr 12 22:45:52 2014 Geoffrey Merran
*/

#include "assembleur.h"
#include "gnl.h"

int		register_condition(t_system *sys)
{
  if (sys->ins.str[sys->ins.i] == 'r' && '0' <= sys->ins.str[sys->ins.i + 1] &&
      sys->ins.str[sys->ins.i + 1] <= '9')
    {
      if (sys->ins.cmptr == 0)
	sys->ins.c += 0x40;
      else if (sys->ins.cmptr == 1)
	sys->ins.c += 0x10;
      else if (sys->ins.cmptr == 2)
	sys->ins.c += 0x4;
      else if (sys->ins.cmptr == 3)
	sys->ins.c += 0x1;
      sys->ins.i += 1;
      return (1);
    }
  return (0);
}

int		direct_condition(t_system *sys)
{
  if (sys->ins.str[sys->ins.i] == '%')
    {
      if (sys->ins.cmptr == 0)
	sys->ins.c += 0x80;
      else if (sys->ins.cmptr == 1)
	sys->ins.c += 0x20;
      else if (sys->ins.cmptr == 2)
	sys->ins.c += 0x8;
      else if (sys->ins.cmptr == 3)
	sys->ins.c += 0x2;
      while (sys->ins.str[sys->ins.i + 1] != ',' &&
	     sys->ins.str[sys->ins.i + 1] != '\0')
	(sys->ins.i)++;
      return (2);
    }
  return (0);
}

int		indirect_condition(t_system *sys)
{
  if ('0' <= sys->ins.str[sys->ins.i] && sys->ins.str[sys->ins.i] <= '9' &&
      (sys->ins.str[sys->ins.i - 1] == ' ' ||
       sys->ins.str[sys->ins.i - 1] == '-'))
    {
      if (sys->ins.cmptr == 0)
	sys->ins.c += 0xC0;
      else if (sys->ins.cmptr == 1)
	sys->ins.c += 0x30;
      else if (sys->ins.cmptr == 2)
	sys->ins.c += 0xC;
      else if (sys->ins.cmptr == 3)
	sys->ins.c += 0x3;
      return (3);
    }
  return (0);
}

void	init_struct_wtf(t_system *sys, char *str, int fd, int *values)
{
  values[0] = 0;
  values[1] = 0;
  values[2] = 0;
  sys->ins.fd = fd;
  sys->ins.str = str;
  sys->ins.fd = fd;
  sys->ins.str = str;
  sys->ins.c = 0;
  sys->ins.i = 0;
  sys->ins.ibase = 0;
  sys->ins.ret_chck = 0;
  sys->ins.cmptr = 0;
}

void		xwrite_to_file(char *str, int fd, int line, t_system *sys)
{
  int		*values;
  int		tmp;

  tmp = 0;
  values = xmalloc(3 * sizeof(int));
  init_struct_wtf(sys, str, fd, values);
  while (str[sys->ins.i])
    {
      check_all(sys, tmp, str, values);
      sys->ins.i++;
    }
  check_inst_error(values, sys);
  if (sys->ins.ret_chck == 1)
    xwrite(fd, &sys->ins.c, 1);
  xwrite_data(sys->ins.ibase, str, line, sys);
  free(values);
}
