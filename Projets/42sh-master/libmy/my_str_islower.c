/*
** my_str_islower.c for my_str_islower in /home/merran_g/work/c_piscine/Piscine-C-Jour_06
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Mon Oct  7 21:25:44 2013 Geoffrey Merran
** Last update Mon Oct  7 22:24:19 2013 Geoffrey Merran
*/

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= 'a' && str[i] <= 'z'))
	return (0);
      i++;
    }
  return (1);
}
