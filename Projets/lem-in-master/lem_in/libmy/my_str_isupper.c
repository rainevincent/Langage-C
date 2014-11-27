/*
** my_str_isupper.c for my_str_isupper in /home/merran_g/work/c_piscine/Piscine-C-Jour_06
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Mon Oct  7 22:09:54 2013 Geoffrey Merran
** Last update Tue Oct  8 09:44:33 2013 Geoffrey Merran
*/

int	my_str_isupper(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= 'A' && str[i] <= 'Z'))
	return (0);
      i++;
    }
  return (1);
}
