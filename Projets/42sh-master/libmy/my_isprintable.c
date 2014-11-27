/*
** my_isprintable.c for my_isprintable in /home/merran_g/work/c_elem/PSU_2018_my_printf
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu Nov  7 17:49:07 2013 Geoffrey Merran
** Last update Sat Nov 16 15:14:15 2013 Geoffrey Merran
*/

int	my_isprintable(char c)
{
  if (c < 32 || c >= 127)
    return (0);
  return (1);
}
