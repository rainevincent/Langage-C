/*
** error_instruction4.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Mon Apr  7 15:29:25 2014 Jeremy Mediavilla
** Last update Sun Apr 13 14:44:24 2014 Joris Bertomeu
*/

#include "assembleur.h"
#include "gnl.h"

void		aff_check_err(t_system *sys, int *values)
{
  if (values[1] != 0)
    aff_error(sys, "Error on \"aff\" instruction : too many params\n");
  if (values[0] != 1)
    aff_error(sys, "Error on \"aff\" instruction : \
first param must be a register\\n");

}
