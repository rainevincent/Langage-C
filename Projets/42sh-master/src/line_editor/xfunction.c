/*
** xfunction.c for line_editor in /home/merran_g/work/c_elem/42sh/src/line_editor
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed May 14 15:20:21 2014 Geoffrey Merran
** Last update Sat May 24 06:49:51 2014 Geoffrey Merran
*/

#include "line_editor.h"

int	xtcsetattr(int fd, int option, struct termios *t)
{
  if (tcsetattr(fd, option, t) == -1)
    {
      my_puterr("tcsetattr error\n");
      return (-1);
    }
  return (0);
}

int	xtcgetattr(int fd, struct termios *termios_p)
{
  if (tcgetattr(fd, termios_p) == -1)
    {
      my_puterr("tcgetattr error\n");
      return (-1);
    }
  return (0);

}

int	xtgetent(char *bp, char *name)
{
  int	ret;

  ret = tgetent(bp, name);
  if (ret == 0)
    {
      my_puterr("tgetent error : terminal not found\n");
      return (-1);
    }
  if (ret == -1)
    {
      my_puterr("tgetent error : terminal name not valid\n");
      return (-1);
    }
  return (0);
}

char	*xtgetstr(char *id, char **area)
{
  char	*result;

  if ((result = tgetstr(id, area)) == NULL)
    {
      my_puterr("tgetstr error\n");
      return (NULL);
    }
  return (result);
}
