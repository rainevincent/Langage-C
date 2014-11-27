/*
** my_strfusion.c for my_strfusion in /home/merran_g/work/c_elem/PSU_2013_minishell1
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu Dec 12 12:54:18 2013 Geoffrey Merran
** Last update Mon Dec 16 19:29:39 2013 Geoffrey Merran
*/

#include "my.h"

char	*my_strfusion(char *dest, char *src)
{
  int	s_dest;
  int	s_src;

  s_dest = my_strlen(dest);
  s_src = my_strlen(src);
  my_realloc(dest, (s_dest + s_src) * sizeof(char));
  my_strcat(dest, src);
  return (dest);
}
