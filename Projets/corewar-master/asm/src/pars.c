/*
** pars.c for  in /home/mediav_j/corewar/assembleur/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed Apr  2 15:11:09 2014 Jeremy Mediavilla
** Last update Sun Apr 13 12:53:38 2014 Joris Bertomeu
*/

#include "assembleur.h"
#include "gnl.h"

void		parse_name(char *buff, int k, t_system *system)
{
  int		i;
  int		j;

  j = 0;
  if (my_strlen(buff) >= 128)
    aff_error(system, "Name >= 128, name must be shorter\n");
  system->name = xmalloc(my_strlen(buff) * sizeof(*system->name));
  my_memset(system->name, 0, my_strlen(buff));
  i = 2 + k + my_strlen(".name");
  while (buff[i] != '\"' && buff[i])
    system->name[j++] = buff[i++];
}

void		parse_comment(char *buff, int k, t_system *system)
{
  int		i;
  int		j;

  j = 0;
  if (my_strlen(buff) >= 2048)
    aff_error(system, "Comment >= 2048, comment must be shorter\n");
  system->comment = xmalloc(my_strlen(buff) * sizeof(*system->comment));
  my_memset(system->comment, 0, my_strlen(buff));
  i = 2 + k + my_strlen(".comment");
  while (buff[i] != '\"' && buff[i])
    system->comment[j++] = buff[i++];
}

int		parse_line_cn(char *buff, t_system *system, int fd)
{
  int		i;
  int		ret;

  ret = 0;
  i = 0;
  while (buff[i])
    {
      if (my_strncmp(&buff[i], ".comment", my_strlen(".comment")) == 0)
	{
	  parse_comment(buff, i, system);
	  create_header(fd, system, 2);
	  ret = 1;
	}
      if (my_strncmp(&buff[i], ".name", my_strlen(".name")) == 0)
	{
	  parse_name(buff, i, system);
	  create_header(fd, system, 1);
	  ret = 1;
	}
	i++;
    }
  return (ret);
}
