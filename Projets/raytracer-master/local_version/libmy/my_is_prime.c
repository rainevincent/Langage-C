/*
** my_is_prime.c for is_prime in /home/merran_g/work/c_piscine/Piscine-C-Jour_05
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Oct  8 19:02:42 2013 Geoffrey Merran
** Last update Sat Nov 30 09:33:21 2013 Geoffrey Merran
*/

int	my_is_prime(int nb)
{
  int	i;

  i = 2;
  if (nb <= 1)
    return (0);
  while (i < nb)
    {
      if (nb % i == 0)
	return (0);
      i++;
    }
  return (1);
}
