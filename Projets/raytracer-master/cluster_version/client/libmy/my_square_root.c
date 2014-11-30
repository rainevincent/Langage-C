/*
** my_square_root.c for my_square_root in /home/merran_g/work/c_piscine/Piscine-C-Jour_05
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Oct  8 18:39:13 2013 Geoffrey Merran
** Last update Tue Oct  8 18:54:08 2013 Geoffrey Merran
*/

int	my_square_root(int nb)
{
  int	i;

  i = nb;
  if (nb < 0)
    return (0);
  while (i * i != nb && i != 0)
    i--;
  return (i);
}
