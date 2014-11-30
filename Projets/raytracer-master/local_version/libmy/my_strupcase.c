/*
** my_strupcase.c for my_strupcase in /home/merran_g/work/c_piscine/Piscine-C-Jour_06/ex_07
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Mon Oct  7 16:53:08 2013 Geoffrey Merran
** Last update Tue Oct  8 09:44:37 2013 Geoffrey Merran
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	{
	  str[i] = str[i] - 32;
	}
      i++;
    }
  return (str);
}
