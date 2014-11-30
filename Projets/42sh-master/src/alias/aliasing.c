/*
** aliasing.c for aliasing in /home/martel_c/rendu/42sh/aliasing
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Mon May 12 15:16:12 2014 martelliere
** Last update Wed May 28 14:37:53 2014 Jeremy Mediavilla
*/

#include "aliasing.h"

int		get_alias(t_alias *alias, t_shell *shell)
{
  int		fd;

  if (shell->online->active == 0)
    {
      if (alias->path == NULL)
	return (-1);
      if (access(alias->path, F_OK) == -1)
	{
	  fprintf(stderr, "42sh: alias: can't access %s\n", alias->path);
	  return (-1);
	}
      if (access(alias->path, R_OK) == -1)
	{
	  fprintf(stderr, "42sh: alias: can't read alias file. \
Check your rights.\n");
	  return (-1);
	}
      if ((fd = open(alias->path, O_RDONLY)) == -1)
	return (-1);
      return (load_alias(alias, fd, shell, 0));
    }
  return (load_alias(alias, 0, shell, 1));
}

int	add_shell_alias(t_shell *shell, char *new)
{
  char	*name;
  char	*content;

  if (get_alias_things(new, &name, &content) != -1)
    add_alias(shell->alias, name, content);
  else
    fprintf(stderr, "42sh: alias: couldn't alias this '%s'\n", new);
  return (0);
}

int	builtin_alias(t_shell *shell, char **cmd)
{
  int	size;
  int	i;

  i = 1;
  size = my_strlen_tabs(cmd);
  if (size == 1)
    display_all_alias(shell->alias);
  else
    {
      while (cmd[i])
	{
	  if (strstr(cmd[i], "=") != NULL)
	    add_shell_alias(shell, cmd[i]);
	  else
	    display_alias(shell->alias, cmd[i]);
	  i++;
	}
    }
  return (0);
}

int		init_aliasing(t_shell **shell)
{
  (*shell)->alias->list = NULL;
  return (get_alias((*shell)->alias, *shell));
}
