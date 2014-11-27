/*
** error_instruction1.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Mon Apr  7 15:26:21 2014 Jeremy Mediavilla
** Last update Sun Apr 13 14:49:45 2014 Joris Bertomeu
*/

#include "assembleur.h"
#include "gnl.h"

void		sti_check_err(t_system *sys, int *values)
{
  if (values[2] == 0)
    aff_error(sys, "Error on \"sti\" instruction : wrong number of params\n");
}

void		and_check_err(t_system *sys, int *values)
{
  if (values[2] == 0)
    aff_error(sys, "Error on \"and\" instruction : wrong number of param\n");
  if (values[2] != 1)
    aff_error(sys, "Error on \"and\" instruction : \
last param is not a register\n");
}

void		ld_check_err(t_system *sys, int *values)
{
  if (values[2] != 0 || values[1] == 0 || values[0] == 0)
    aff_error(sys, "Error on \"ld\" instruction : wrong number of params\n");
  if (values[1] != 1)
    aff_error(sys, "Error on \"ld\" instruction : \
second param must be a register\n");
}

void		live_check_err(t_system *sys, int *values)
{
  if (values[1] != 0 || values[0] == 0)
    aff_error(sys, "Error on \"live\" instruction : worng number of param\n");
  if (values[0] == 1)
    aff_error(sys, "Error on \"live\" instruction : \
first param must be an index\n");
}

void		zjmp_check_err(t_system *sys, int *values)
{
  if (values[1] != 0)
    aff_error(sys, "Error on \"zjmp\" instruction : too many param\n");
  if (values[0] == 1)
    aff_error(sys, "Error on \"zjmp\" instruction : \
first param is not an index\n");
}
