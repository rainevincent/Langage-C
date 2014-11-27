/*
** echo_fct.c for  in /home/nicolas/Workspace/Unix/42sh/src/builtin
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sat May 24 17:58:13 2014 Nicolas Ades
** Last update Mon May 26 20:19:51 2014 Nicolas Ades
*/

#include "core.h"

int		do_echo_with_e(char **cmd)
{
  char		*tmp;
  int		i;
  int		j;

  i = go_to_arg(cmd);
  while (cmd[i] != NULL)
    {
      j = 0;
      while (cmd[i][j])
	{
	  if (cmd[i][j] == '\\')
	    {
	      if ((tmp = my_xmalloc(3 * sizeof (*tmp))) == NULL)
		return (-1);
	      memset(tmp, 0, 3);
	      tmp = strncpy(tmp, &cmd[i][j], 2);
	      my_putstr(tmp);
	      free(tmp);
	      j += 2;
	    }
	  else
	    {
	      my_putchar(cmd[i][j]);
	      j++;
	    }
	}
      i++;
    }
  return (0);
}
