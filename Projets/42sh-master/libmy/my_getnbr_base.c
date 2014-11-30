/*
** my_getnbr_base.c for my_getnbr_base in /home/merran_g/work/c_piscine/Piscine-C-Jour_06
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Wed Oct  9 16:46:29 2013 Geoffrey Merran
** Last update Thu Nov 14 17:40:01 2013 Geoffrey Merran
*/

#include "my.h"

int	my_checkinext(char *str, char *base)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (str[0] == '\0' || base[0] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      while (base[j] != '\0')
	{
	  if (str[i] == base[j] || str[i] == '+' || str[i] == '-')
	    break;
	  if (base[j + 1] == '\0')
	    return (1);
	  j++;
	}
      j = 0;
      i++;
    }
  return (0);
}

int	my_checkerrors(char *str, char *base)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (my_checkinext(str, base))
    return (0);
  while (base[i] != '\0')
    {
      while (base[j] != '\0')
	{
	  if (base[i] == base[j] && i != j)
	    return (1);
	  j++;
	}
      j = 0;
      i++;
    }
  return (0);
}

int	my_check_neg(char *str)
{
  int	i;
  int	neg;

  neg = 0;
  i = 0;
  while ((str[i] == '+' || str[i] == '-') && str[i] != '\0')
    {
      if (str[i] == '-')
	neg++;
      i++;
    }
  if (neg % 2 == 0)
    return (1);
  return (-1);
}

int	my_getnbr_base(char *str, char *base)
{
  int	negative;
  int	nb;
  int	lenght;
  int	i;
  int	j;

  lenght = my_strlen(base);
  nb = 0;
  i = 0;
  if (my_checkerrors(str, base))
    return (0);
  negative = my_check_neg(str);
  while (str[i] != '\0')
    {
      j = 0;
      while (j < lenght && base[j] != str[i])
	j++;
      nb = nb * lenght + j;
      i++;
    }
  return (negative * nb);
}
