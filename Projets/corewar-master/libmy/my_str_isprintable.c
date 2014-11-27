/*
** my_str_isprintable.c for my_str_isprintable in /home/merran_g/work/c_piscine/Piscine-C-Jour_06/ex_14
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Mon Oct  7 22:32:25 2013 Geoffrey Merran
** Last update Sat Nov 16 15:14:32 2013 Geoffrey Merran
*/

int	my_str_isprintable(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] >= 127)
	return (0);
      i++;
    }
  return (1);
}
