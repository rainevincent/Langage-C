/*
** parse.c for visu in /home/jobertomeu/Work/lemin/visu
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun May  4 12:18:21 2014 Joris Bertomeu
** Last update Sun May  4 19:48:14 2014 Joris Bertomeu
*/

#include "visu.h"

void	parse(t_system *sys)
{
  int	fd;
  char	*tmp;

  sys->current = 0;
  sys->nbr_box = 0;
  tmp = xmalloc(4096 * sizeof(*tmp));
  fd = 0;
  while ((tmp = get_next_line(fd)) != NULL)
    {
      tread_line(tmp, sys);
      sys->current++;
    }
  free(tmp);
}

void		tread_line(char *str, t_system *sys)
{
  t_coor	pos;
  t_coor	flag;

  init_coor(&pos);
  init_coor(&flag);
  if (strcmp(str, "##start") == 0)
    sys->func = 1;
  else if (strcmp(str, "##end") == 0)
    sys->func = 2;
  else
    {
      while (str[pos.x])
	{
	  if (str[pos.x] == ' ')
	    flag.x++;
	  else if (str[pos.x] == '-')
	    pos.y++;
	  else if ((str[pos.x] >= 'a' && str[pos.x] <= 'z') ||
		   (str[pos.x] >= 'A' && str[pos.x] <= 'Z'))
	    flag.y++;
	  pos.x++;
	}
      decision(flag, pos, str, sys);
      sys->func = 0;
    }
}

void	decision(t_coor flag, t_coor pos, char *str, t_system *sys)
{
  if (flag.x == 2 && str[0] != 'P')
    {
      parse_decl(str, sys, sys->func, 0);
    }
  else if (flag.x == 0 && pos.y != 0 && str[0] != 'P')
    {
      parse_pipe(str, sys, 0, 0);
    }
  else
    {
      parse_path(str, sys);
    }
}

void		parse_path(char *str, t_system *sys)
{
  int		i;
  unsigned int	nbr;
  static int	flag = 0;

  nbr = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
	nbr++;
      else
	nbr = 0;
      i++;
    }
  if (nbr == strlen(str))
    check_nbr_ants(str, sys);
  else if (flag == 0)
    {
      put_ants_room(sys, sys->nbr_ants);
      flag = 1;
    }
  ants_path(str, sys, 0, 0);
}

void	parse_pipe(char *str, t_system *sys, int i, int j)
{
  int	flag;
  int	k;
  char	name1[4096];
  char	name2[4096];

  k = 0;
  flag = 0;
  while (str[i])
    {
      if (str[i] == '-')
	flag++;
      else if (flag == 0)
	name1[j++] = str[i];
      else
	name2[k++] = str[i];
      i++;
    }
  name1[j] = 0;
  name2[k] = 0;
  draw_tunel(name1, name2, sys);
}
