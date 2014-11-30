/*
** mlx_utility.c for mlx_utility in /home/merran_g/work/c_igraph/fdf
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Mon Dec  2 16:20:00 2013 Geoffrey Merran
** Last update Thu Jun  5 21:18:11 2014 Geoffrey Merran
*/

#define _GNU_SOURCE
#include "mlx_utility.h"

float	conv_radian(float degree)
{
  return ((degree * M_PI) / (float) 180);
}

int	is_fzero(float f)
{
  if (f <= 0.0001 && f >= -0.0001)
    return (1);
  return (0);
}

void	normalize_vec(t_vector *vec)
{
  float	longueur;

  longueur = sqrt(pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2));
  vec->x = vec->x / longueur;
  vec->y = vec->y / longueur;
  vec->z = vec->z / longueur;
}

int	my_abs(int n)
{
  if (n < 0)
    n = n * -1;
  return (n);
}
