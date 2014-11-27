/*
** do_cd.c for  in /home/nicolas/Workspace/Unix/42sh
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Mon May 26 21:25:18 2014 Nicolas Ades
** Last update Wed May 28 14:44:24 2014 Jeremy Mediavilla
*/

#include "core.h"

int		xchdir(const char *path)
{
  if (access(path, R_OK) == -1)
    {
      fprintf(stderr, "42sh: cd: %s: permission denied\n", path);
      return (-1);
    }
  if ((chdir(path)) == -1)
    {
      fprintf(stderr, "42sh: cd: Error on chdir \
with this path : [%s]\n", path);
      return (-1);
    }
  return (0);
}

char		*get_pwd()
{
  char *dest;

  if ((dest = my_xmalloc(500 * sizeof (*dest))) == NULL)
    return (NULL);
  memset(dest, 0, 500);
  dest = getcwd(dest, 500);
  return (dest);
}

int		do_cd_bis(t_shell *shell, char *path)
{
  char		*new;
  char		*old;

  if (my_strcmp(path, "-/") == 0)
    {
      if ((old = get_pwd()) == NULL)
	return (-1);
      if ((new = check_env_var(shell->env, "OLDPWD=", 7)) == NULL)
	return (-1);
      if ((xchdir(new)) == -1)
	return (-1);
      if ((new = get_pwd()) == NULL)
	return (-1);
      change_old_pwd(shell, old);
      change_pwd(shell, new);
      return (0);
    }
  else
    {
      if ((old = get_pwd()) == NULL)
	return (-1);
      if ((xchdir(path)) == -1)
	return (-1);
      if ((new = get_pwd()) == NULL)
	return (-1);
      change_old_pwd(shell, old);
      change_pwd(shell, new);
    }
  return (0);
}

int		do_cd(t_shell *shell, char **cmd)
{
  char		*new;
  char		*old;
  char		*path;

  if (cmd[1] == NULL)
    path = strdup("~");
  else
    path = strdup(cmd[1]);
    if ((path = add_slash(path)) == NULL)
    return (-1);
  if (my_strcmp(path, "~/") == 0 || path == NULL)
    {
      if ((old = get_pwd()) == NULL)
	return (-1);
      if ((new = check_env_var(shell->env, "HOME=", 5)) == NULL)
	return (-1);
      if ((xchdir(new)) == -1)
	return (-1);
      if ((new = get_pwd()) == NULL)
	return (-1);
      change_old_pwd(shell, old);
      change_pwd(shell, new);
      return (0);
    }
  if ((do_cd_bis(shell, path)) == -1)
    return (-1);
  return (0);
}
