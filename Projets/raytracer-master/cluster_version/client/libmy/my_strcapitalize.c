/*
** my_strcapitalize.c for my_strcapitalize in /home/merran_g/work/c_piscine/Piscine-C-Jour_06
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Mon Oct  7 17:16:16 2013 Geoffrey Merran
** Last update Sat Nov 30 09:37:40 2013 Geoffrey Merran
*/

int	my_isalpha(char c)
{
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    return (1);
  return (0);
}

int	my_isdigit(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int	my_isupchar(char c)
{
  if (c >= 'A' && c <= 'Z')
    return (1);
  return (0);
}

char	*my_strcapitalize(char *str)
{
  int	i;
  int	upcase;

  upcase = 0;
  i = 1;
  if (str[0] >= 'a' && str[0] <= 'z')
    str[0] = str[0] - 32;
  while (str[i] != '\0')
    {
      if (!(my_isalpha(str[i]) || my_isdigit(str[i])))
	upcase = 1;
      else if (str[i] >= 'a' && str[i] <= 'z' && upcase == 1)
	{
	  str[i] = str[i] - 32;
	  upcase = 0;
	}
      else if (my_isupchar(str[i]) || (my_isdigit(str[i]) && upcase))
	upcase = 0;
      else if (str[i] >= 'A' && str[i] <= 'Z')
	str[i] = str[i] + 32;
      i++;
    }
  return (str);
}
