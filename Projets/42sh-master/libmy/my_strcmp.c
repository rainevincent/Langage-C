/*
** my_strcmp.c for mu_strcmp in /home/merran_g/work/c_piscine/Piscine-C-Jour_06
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Mon Oct  7 11:38:50 2013 Geoffrey Merran
** Last update Wed Nov  6 11:54:29 2013 Geoffrey Merran
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	result;

  i = 0;
  result = 0;
  while (s1[i] == s2[i])
    {
      if (s1[i] == '\0' && s2[i] == '\0')
	return (0);
      i++;
    }
  if (s1[i] != s2[i])
    result = s1[i] - s2[i];
  return (result);
}
