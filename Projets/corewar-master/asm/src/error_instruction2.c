/*
** error_instruction2.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Mon Apr  7 15:28:07 2014 Jeremy Mediavilla
** Last update Sun Apr 13 15:15:39 2014 Jeremy Mediavilla
*/

#include "assembleur.h"
#include "gnl.h"

void		st_check_err(t_system *sys, int *values)
{
  if (values[0] != 1 || (values[1] != 1 && values[1] != 3))
    aff_error(sys, "Error on \"st\" instruction : \
wrong type of parameters\n");
  if (values[0] == 0 || values[1] == 0)
    aff_error(sys, "Error on \"st\" instruction : wrong number of params\n");
}

void		add_check_err(t_system *sys, int *values)
{
  if (values[2] == 0)
    aff_error(sys, "Error on \"add\" instruction : wrong number of params\n");
  if (values[0] != 1 || values[1] != 1 || values[2] != 1)
    aff_error(sys, "Error on \"add\" instruction : \
all params must be register\n");
}

void		sub_check_err(t_system *sys, int *values)
{
  if (values[2] == 0)
    aff_error(sys, "Error on \"sub\" instruction : wrong number of params\n");
  if (values[0] != 1 || values[1] != 1 || values[2] != 1)
    aff_error(sys, "Error on \"sub\" instruction : \
all params must be register\n");
}

void		or_check_err(t_system *sys, int *values)
{
  if (values[2] == 0)
    aff_error(sys, "Error on \"or\" instruction : wrong number of param\n");
  if (values[2] != 1)
    aff_error(sys, "Error on \"or\" instruction : \
last param is not a register\n");
}

void		xor_check_err(t_system *sys, int *values)
{
  if (values[2] == 0)
    aff_error(sys, "Error on \"xor\" instruction : wrong number of param\n");
  if (values[2] != 1)
    aff_error(sys, "Error on \"xor\" instruction : \
last param is not a register\n");
}
