/*
** error_instruction3.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Mon Apr  7 15:28:42 2014 Jeremy Mediavilla
** Last update Sun Apr 13 15:16:07 2014 Jeremy Mediavilla
*/

#include "assembleur.h"
#include "gnl.h"

void		ldi_check_err(t_system *sys, int *values)
{
  if (values[0] != 2 && values[0] != 3)
    aff_error(sys, "Error on \"ldi\" instruction : \
first param must be an index\n");
  if (values[1] != 2 && values[1] != 3)
    aff_error(sys, "Error on \"ldi\" instruction : \
second param must be an index\n");
}

void		fork_check_err(t_system *sys, int *values)
{
  if (values[1] != 0)
    aff_error(sys, "Error on \"fork\" instruction : too many param\n");
  if (values[0] == 1)
    aff_error(sys, "Error on \"fork\" instruction : \
first param is not an index\n");
}

void		lld_check_err(t_system *sys, int *values)
{
  if (values[2] != 0 || values[1] == 0 || values[0] == 0)
    aff_error(sys, "Error on \"lld\" instruction : wrong number of params\n");
  if (values[1] != 1)
    aff_error(sys, "Error on \"lld\" instruction : \
second param must be a register\n");
}

void		lldi_check_err(t_system *sys, int *values)
{
  if (values[0] != 2 || values[0] != 3)
    aff_error(sys, "Error on \"lldi\" instruction : \
first param must be an index\n");
  if (values[1] != 2 || values[1] != 3)
    aff_error(sys, "Error on \"lldi\" instruction : \
second param must be an index\n");
}

void		lfork_check_err(t_system *sys, int *values)
{
  if (values[1] != 0)
    aff_error(sys, "Error on \"lfork\" instruction : too many param\n");
  if (values[0] == 1)
    aff_error(sys, "Error on \"lfork\" instruction : \
first param is not an index\n");
}
