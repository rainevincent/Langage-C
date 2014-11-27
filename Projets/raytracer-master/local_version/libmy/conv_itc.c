/*
** conv.c for conv in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Apr  9 15:52:48 2014 Geoffrey Merran
** Last update Wed Apr  9 16:07:40 2014 Geoffrey Merran
*/

#include "my.h"

char	*int_to_str(int	nb)
{
  char	*str;
  int	i;
  int	s;

  s = 0;
  i = nb;
  while (i)
    {
      i = i / 10;
      s++;
    }
  str = my_xmalloc((s + 1) * sizeof(char));
  my_memset(str, 0, (s + 1));
  i = s - 1;
  while (i >= 0)
    {
      str[i] = nb % 10 + '0';
      nb = nb / 10;
      i--;
    }
  return (str);
}
