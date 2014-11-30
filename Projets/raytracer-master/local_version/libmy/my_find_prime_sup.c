/*
** my_find_prime_sup.c for my_find_prime_sup in /home/merran_g/work/c_piscine/Piscine-C-Jour_05
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Oct  8 19:16:51 2013 Geoffrey Merran
** Last update Sat Nov 30 09:31:49 2013 Geoffrey Merran
*/

#include "my.h"

int	my_find_prime_sup(int nb)
{
  if (nb <= 1)
    return (2);
  while (!(my_is_prime(nb)))
    nb++;
  return (nb);
}
