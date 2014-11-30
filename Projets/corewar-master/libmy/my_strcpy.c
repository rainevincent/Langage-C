/*
** my_strcpy.c for my_strcpy in /home/merran_g/work/c_piscine/Piscine-C-Jour_06/ex_01
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Mon Oct  7 09:41:36 2013 Geoffrey Merran
** Last update Mon Feb 10 16:41:36 2014 Geoffrey Merran
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
