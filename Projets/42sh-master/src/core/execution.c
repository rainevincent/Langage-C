/*
** execution.c for  in /home/nicolas/Workspace/Unix/42sh/src/core
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sat May 24 08:06:43 2014 Nicolas Ades
** Last update Wed May 28 01:22:10 2014 Geoffrey Merran
*/

#include "core.h"

int		do_fork_bis(char **envp, char **cmd)
{
  pid_t		pid;

  if ((pid = fork()) == -1)
    {
      fprintf(stderr, "42sh: execution: Error with fork\n");
      return (-1);
    }
  if (pid == 0)
    execve(cmd[0], cmd, envp);
  else
    status = wait_father(pid);
  return (0);
}

int		do_fork(char **envp, char **cmd, char **path, int pos)
{
  pid_t		pid;
  int		status;

  if ((pid = fork()) == -1)
    {
      fprintf(stderr, "Error with fork\n");
      return (-1);
    }
  if (pid == 0)
    execve(path[pos], cmd, envp);
  else
    status = wait_father(pid);
  return (0);
}

int		is_cmd_exist(char **cmd, char **path)
{
  int		i;
  char		*tmp;

  i = 0;
  while (path[i] != NULL)
    {
      if ((tmp = my_xmalloc((strlen(path[i]) + 1) *sizeof(*path))) == NULL)
	return (-1);
      memset(tmp, 0, (strlen(path[i]) + 1));
      tmp = strcat(tmp, path[i]);
      tmp = strcart(tmp, cmd[0]);
      if (access(tmp, F_OK) != -1)
	{
	  if (access(tmp, X_OK) == -1)
	    {
	      fprintf(stderr, "%s: Permission denied\n", cmd[0]);
	      return (-1);
	    }
	  return (i);
	}
      i++;
    }
  fprintf(stderr, "%: Command not found\n", cmd[0]);
  return (-1);
}

int		my_exec(t_shell *shell, char **cmd)
{
  int		pos;
  char		**envp;
  char		**path;

  envp = env_in_tab(shell->env);
  if (strstr(cmd[0], "/") != NULL)
    {
      if (do_fork_bis(envp, cmd) == -1)
	return (-1);
      return (0);
    }
  if ((path = check_env_var(shell->env, "PATH=", 5)) == NULL)
    return (-1);
  if ((pos = is_cmd_exist(cmd, path)) == -1)
    return (-1);
  if (do_fork(envp, cmd, path, pos) == -1)
    return (-1);
  return (0);
}
