/*
** draw.c for visu in /home/jobertomeu/Work/lemin/visu
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun May  4 12:23:49 2014 Joris Bertomeu
** Last update Sun May  4 16:07:46 2014 Jeremy Mediavilla
*/

#include "visu.h"

void	swapint(int *x, int *y)
{
  int	t;

  t = *x;
  *x = *y;
  *y = t;
}

void		PutPixel(SDL_Surface *surface, int x, int y, unsigned long pixel)
{
  int		bpp;
  unsigned char *p;

  bpp = surface->format->BytesPerPixel;
  p = (unsigned char *)surface->pixels + y * surface->pitch + x * bpp;
  if (bpp == 4)
    *(unsigned long *)p = pixel;
}

unsigned long	convert_color(int R, int G, int B)
{
  return 65536*R + 256*G + B;
}

void	step2(t_coor *pos1, t_coor *pos2, t_coor incr, SDL_Surface *surf)
{
  int	error;
  int	dx;
  int	dy;
  int	x;
  int	y;
  int	i;

  x = pos1->x;
  y = pos1->y;
  dx = abs(pos2->x - pos1->x);
  dy = abs(pos2->y - pos1->y);
  error = dy / 2;
  i = 0;
  while (i < dy)
    {
      y += incr.y;
      error += dx;
      if (error > dy)
	{
	  error -= dy;
	  x += incr.x;
	}
      PutPixel(surf, x + 50, y + 50, convert_color(0, 0, 255));
      i++;
    }
}

void	step1(t_coor *pos1, t_coor *pos2, t_coor incr, SDL_Surface *surf)
{
  int	error;
  int	dx;
  int	dy;
  int	x;
  int	y;
  int	i;

  x = pos1->x;
  y = pos1->y;
  dx = abs(pos2->x - pos1->x);
  dy = abs(pos2->y - pos1->y);
  error = dx / 2;
  i = 0;
  while (i < dx)
    {
      x += incr.x;
      error += dy;
      if (error > dx)
	{
	  error -= dx;
	  y += incr.y;
	}
      PutPixel(surf, x + 50, y + 50, convert_color(0, 0, 255));
      i++;
    }
}
