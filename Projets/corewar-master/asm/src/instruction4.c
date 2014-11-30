/*
** instruction4.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:27:16 2014 Jeremy Mediavilla
** Last update Wed Apr  9 14:04:24 2014 Jeremy Mediavilla
*/

#include "assembleur.h"
#include "gnl.h"

void		aff_instruction(t_system *sys)
{
  sys->ins.c = 0x10;
  xwrite(sys->ins.fd, &sys->ins.c, 1);
  sys->ins.i += 3;
  sys->ins.ret_chck = 1;
  my_printf(">> Instruction : aff (1 Octet)\n");
  if (sys->ins.str[sys->ins.i] == ':')
    {
      sys->ins.ret_chck = -1;
      my_printf(">> Label : %s\n", &sys->ins.str[(sys->ins.i) - 4]);
      while (sys->ins.str[sys->ins.i] && sys->ins.str[sys->ins.i] != '%')
  	(sys->ins.i)++;
    }
  sys->ins.ibase = sys->ins.i;
}
