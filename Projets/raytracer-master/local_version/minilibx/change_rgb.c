/*
** change_rgb.c for change_rgb in /home/merran_g/work/c_igraph/fdf
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun Dec  1 18:04:48 2013 Geoffrey Merran
** Last update Sun Dec  1 18:05:31 2013 Geoffrey Merran
*/

int	change_rgb(int r, int g, int b)
{
  return (r * 65536 + g * 256 + b);
}
