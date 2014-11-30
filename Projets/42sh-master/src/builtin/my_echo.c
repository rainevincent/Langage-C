/*
** my_echo.c for  in /home/nicolas/Workspace/Unix/42sh/src/builtin
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sat May 24 16:53:37 2014 Nicolas Ades
** Last update Mon May 26 19:21:53 2014 Nicolas Ades
*/

#include "core.h"

int		get_opt_n(char **cmd, int i, t_echo *echo)
{
  if (cmd[i][0] == '-' && cmd[i][1] == 'n')
    echo->opt_n = 1;
  return (i);
}

int		get_opt_e(char **cmd, int i, t_echo *echo)
{
  if (cmd[i][0] == '-' && cmd[i][1] == 'e')
    echo->opt_e = 1;
  return (i);
}

int		go_to_arg(char **cmd)
{
  int		i;

  i = 1;
  while (cmd[i] != NULL)
    {
      if (cmd[i][0] == '-' && (cmd[i][1] == 'e' || cmd[i][1] == 'n'))
	i++;
      else
	return (i);
    }
  return (i);
}

int		do_echo(char **cmd, t_echo *echo)
{
  int		i;

  i = go_to_arg(cmd);
  if (echo->opt_e == 1)
    do_echo_with_e(cmd);
  else
    {
      while (cmd[i] != NULL)
	{
	  my_putstr(cmd[i]);
	  i++;
	}
    }
  return (0);
}

int		my_echo(t_shell *shell, char **cmd)
{
  t_echo	*echo;
  int		i;

  (void)shell;
  if ((echo = my_xmalloc(sizeof(*echo))) == NULL)
    return (-1);
  echo->opt_n = 0;
  echo->opt_e = 0;
  i = 1;
  while (cmd[i] != NULL)
    {
      i = get_opt_n(cmd, i, echo);
      i = get_opt_e(cmd, i, echo);
      i++;
    }
  if (do_echo(cmd, echo) == -1)
    return (-1);
  if (echo->opt_n != 1)
    my_putchar('\n');
  return (0);
}
