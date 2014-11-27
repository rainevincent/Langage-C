/*
** my_swap.c for my_swap in /home/merran_g/work/c_piscine/Piscine-C-Jour_04
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu Oct  3 09:24:59 2013 Geoffrey Merran
** Last update Wed Nov  6 12:29:31 2013 Geoffrey Merran
*/

int	my_swap(int *a, int *b)
{
  int	swap;

  swap = *a;
  *a = *b;
  *b = swap;
  return (0);
}
