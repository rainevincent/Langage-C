/*
** my_strstr.c for my_strstr in /home/merran_g/work/c_piscine/Piscine-C-Jour_06
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Mon Oct  7 10:38:49 2013 Geoffrey Merran
** Last update Wed Dec 11 17:22:52 2013 Geoffrey Merran
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;
  int	result;

  i = 0;
  j = 0;
  if (to_find[j] == '\0')
    return (&str[i]);
  while (str[i] != '\0')
    {
      result = i;
      while (str[i] == to_find[j])
	{
	  i++;
	  j++;
	  if (to_find[j] == '\0')
	      return (&str[result]);
	}
      i = result;
      j = 0;
      i++;
    }
  return (0);
}
