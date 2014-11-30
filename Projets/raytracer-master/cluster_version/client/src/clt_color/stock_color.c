/*
** rt.c for  in /home/mediav_j/tmp
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Tue Jun  3 14:31:37 2014 Jeremy Mediavilla
** Last update Tue Jun  3 16:40:54 2014 Jeremy Mediavilla
*/

#include <string.h>
#include "rtv1.h"

void		stock_clr_img(int *color, char *img)
{
  int		i;
  t_union	tmp;
  int		pos;

  i = 0;
  while (i < 8)
    {
      if (color[i] == 0 && color[i + 8] == 0)
	return ;
      tmp.clr = color[i + 8];
      pos = color[i] * 4;
      memcpy(&img[pos], &tmp.color, 4);
      i++;
    }
}
