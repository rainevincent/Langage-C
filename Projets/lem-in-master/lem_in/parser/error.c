/*
** error.c for error in /home/merran_g/work/c_elem/lem-in/lem_in/parser
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri Apr 25 20:04:56 2014 Geoffrey Merran
** Last update Fri Apr 25 20:05:59 2014 Geoffrey Merran
*/

#include "parser.h"

void	my_error(char *error)
{
  my_puterr(error);
  exit(EXIT_FAILURE);
}
