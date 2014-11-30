/*
** instruction1.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:18:04 2014 Jeremy Mediavilla
** Last update Fri Apr 11 20:25:55 2014 Joris Bertomeu
*/

#include "assembleur.h"
#include "gnl.h"

void		live_instruction(t_system *sys)
{
  sys->ins.c = 0x01;
  xwrite(sys->ins.fd, &sys->ins.c, 1);
  sys->ins.i += 4;
  sys->ins.ret_chck = -1;
  my_printf(">> Instruction : live (1 Octet)\n");
  if (sys->ins.str[sys->ins.i] == ':')
    {
      sys->ins.ret_chck = -1;
      my_printf(">> Label %s\n", &sys->ins.str[(sys->ins.i) - 4]);
      while (sys->ins.str[sys->ins.i] && sys->ins.str[sys->ins.i] != '%')
  	(sys->ins.i)++;
    }
  sys->ins.ibase = sys->ins.i;
}

void		ld_instruction(t_system *sys)
{
  sys->ins.c = 0x02;
  xwrite(sys->ins.fd, &sys->ins.c, 1);
  sys->ins.i += 2;
  sys->ins.ret_chck = 1;
  my_printf(">> Instruction : ld (1 Octet)\n");
  if (sys->ins.str[sys->ins.i] == ':')
    {
      sys->ins.ret_chck = -1;
      my_printf(">> Label : %s\n", &sys->ins.str[(sys->ins.i) - 4]);
      while (sys->ins.str[sys->ins.i] && sys->ins.str[sys->ins.i] != '%')
  	(sys->ins.i)++;
    }
  sys->ins.ibase = sys->ins.i;
}

void		st_instruction (t_system *sys)
{
  sys->ins.c = 0x03;
  xwrite(sys->ins.fd, &sys->ins.c, 1);
  sys->ins.i += 2;
  sys->ins.ret_chck = 1;
  my_printf(">> Instruction : st (1 Octet)\n");
  if (sys->ins.str[sys->ins.i] == ':')
    {
      sys->ins.ret_chck = -1;
      my_printf(">> Label : %s\n", &sys->ins.str[(sys->ins.i) - 4]);
      while (sys->ins.str[sys->ins.i] && sys->ins.str[sys->ins.i] != '%')
  	(sys->ins.i)++;
    }
  sys->ins.ibase = sys->ins.i;
}

void		add_instruction(t_system *sys)
{
  sys->ins.c = 0x04;
  xwrite(sys->ins.fd, &sys->ins.c, 1);
  sys->ins.i += 3;
  sys->ins.ret_chck = 1;
  my_printf(">> Instruction : add (1 Octet)\n");
  if (sys->ins.str[sys->ins.i] == ':')
    {
      sys->ins.ret_chck = -1;
      my_printf(">> Label : %s\n", &sys->ins.str[(sys->ins.i) - 4]);
      while (sys->ins.str[sys->ins.i] && sys->ins.str[sys->ins.i] != '%')
  	(sys->ins.i)++;
    }
  sys->ins.ibase = sys->ins.i;
}

void		sub_instruction(t_system *sys)
{
  sys->ins.c = 0x05;
  xwrite(sys->ins.fd, &sys->ins.c, 1);
  sys->ins.i += 3;
  sys->ins.ret_chck = 1;
  my_printf(">> Instruction : sub (1 Octet)\n");
  if (sys->ins.str[sys->ins.i] == ':')
    {
      sys->ins.ret_chck = -1;
      my_printf(">> Label : %s\n", &sys->ins.str[(sys->ins.i) - 4]);
      while (sys->ins.str[sys->ins.i] && sys->ins.str[sys->ins.i] != '%')
  	(sys->ins.i)++;
    }
  sys->ins.ibase = sys->ins.i;
}
