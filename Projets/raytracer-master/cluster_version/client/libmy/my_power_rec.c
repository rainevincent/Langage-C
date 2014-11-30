/*
** my_power_rec.c for my_power_rec in /home/merran_g/work/c_piscine/Piscine-C-Jour_05
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri Oct  4 12:27:55 2013 Geoffrey Merran
** Last update Wed Nov  6 12:29:01 2013 Geoffrey Merran
*/

int	my_power_rec(int nb, int power)
{
  int	result;

  result = 1;
  if (power > 0)
    result = nb * my_power_rec(nb, power - 1);
  if (power < 0)
    result = 0;
  return (result);
}
