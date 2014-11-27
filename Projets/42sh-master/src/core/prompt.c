/*
** prompt.c for prompt in /home/merran_g/work/c_elem/42sh
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue May 27 23:04:16 2014 Geoffrey Merran
** Last update Wed May 28 11:49:10 2014 Jeremy Mediavilla
*/

#include "core.h"
#include "gnl.h"

t_shell		*g_shell;

t_builtin	builtin[] =
  {
    {"env", aff_env},
    {"unsetenv", my_unsetenv},
    {"setenv", my_setenv},
    {"alias", builtin_alias},
    {"history", builtin_history},
    {"cd", do_cd},
    {"echo", my_echo},
    {"exit", my_exit}
  };

/*
** Ajouter des built-in seulement de la forme
**	int	my_builtin(t_shell *shell, char **cmd);
**
*/

int            check_builtin(t_shell *shell, char **cmd)
{
  int           i;

  i = 0;
  if (cmd == NULL)
    return (-1);
  while (i < 8)
    {
      if (strcmp(cmd[0], builtin[i].name) == 0)
	return (builtin[i].fptr(shell, cmd));
      i++;
    }
  return (-2);
}

void		catch_sigint(int __attribute__((unused)) signum)
{
  printf("\n");
  prompt(g_shell);
}

int		prompt(t_shell *shell)
{
  char		*cmd;

  g_shell = shell;
  signal(SIGINT, &catch_sigint);
  cmd = line_editor(shell);
  if (cmd != NULL)
    {
      if (shell->end == 1)
	{
	  free(cmd);
	  return (0);
	}
      my_lexer(cmd, shell);
      add_cmd(shell->history, cmd);
      free(cmd);
      shell->error = 0;
    }
  else
    shell->error++;
  if (shell->error == 10)
    return (my_error("42sh: critical errors: too much error, \
can't continue. Exiting\n"));
  if (shell->end != 1)
    prompt(shell);
  return (0);
}
