/*
** init.c for  in /home/mediav_j/mabm/42sh
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Thu May  8 18:31:03 2014 Jeremy Mediavilla
** Last update Thu May  8 18:32:22 2014 Jeremy Mediavilla
*/

#include "core.h"

char		*init_unsetenv_var(int name_len, char **command)
{
  char		*var;

  var = my_xmalloc((name_len + 2) * sizeof(char));
  memset(var, '\0', (name_len + 2));
  var = strcat(var, command[1]);
  var = strcat(var, "=");
  return (var);
}
