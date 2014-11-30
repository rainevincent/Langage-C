/*
** my_puterr.c for my_puterr in /home/merran_g/work/c_elem/PSU_2013_minishell1
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Feb 18 12:16:38 2014 Geoffrey Merran
** Last update Fri Jun  6 17:48:07 2014 Geoffrey Merran
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void	my_error(char *err)
{
  my_puterr(err);
  exit(EXIT_FAILURE);
}

void	my_puterr(char *err)
{
  if (write(2, err, my_strlen(err)) == -1)
    exit(-1);
}
