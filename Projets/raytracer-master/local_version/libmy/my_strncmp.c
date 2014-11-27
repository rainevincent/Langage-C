/*
** my_strncmp.c for my_strncmp in /home/merran_g/work/c_piscine/Piscine-C-Jour_06/ex_06
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Mon Oct  7 15:37:00 2013 Geoffrey Merran
** Last update Wed Nov  6 12:29:42 2013 Geoffrey Merran
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;
  int	result;

  i = 0;
  result = 0;
  while (s1[i] == s2[i] && i < (n - 1))
    {
      if (s1[i] == '\0' && s2[i] == '\0')
	return (0);
      i++;
    }
  if (s1[i] != s2[i])
    result = s1[i] - s2[i];
  return (result);
}
