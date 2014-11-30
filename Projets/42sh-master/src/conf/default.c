/*
** default.c for default.c in /home/merran_g/work/c_elem/42sh/src/conf
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sat May 24 21:35:51 2014 Geoffrey Merran
** Last update Sat May 24 21:41:22 2014 Geoffrey Merran
*/

#include "conf.h"

int	default_conf(t_shell **shell)
{
  (*shell)->history->path = strdup(".mabm_history");
  (*shell)->alias->path = strdup(".mabm_alias");
  (*shell)->prompt = 1;
  return (0);
}
