/*
** main.c for  in /home/mediav_j/mabm/42sh/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May 28 14:43:30 2014 Jeremy Mediavilla
** Last update Wed May 28 14:43:38 2014 Jeremy Mediavilla
*/

#include "core.h"

int		init_shell(t_shell **shell, int ac, char **av)
{
  (*shell)->history = my_xmalloc(sizeof(*(*shell)->history));
  if ((*shell)->history == NULL)
    return (-1);
  (*shell)->alias = my_xmalloc(sizeof(*(*shell)->alias));
  if ((*shell)->alias == NULL)
    return (-1);
  default_conf(shell);
  if (ac == 2)
    load_conf(shell, av[1]);
  init_history(shell);
  init_aliasing(shell);
  return (0);
}

int		loading_shell(t_shell **shell, char **env, int ac, char **av)
{
  if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
    return (-1);
  if (signal(SIGTSTP, SIG_IGN) == SIG_ERR)
    return (-1);
  *shell = my_xmalloc(sizeof(**shell));
  if (shell == NULL)
    return (-1);
  (*shell)->env = create_list(NULL);
  get_all_env((*shell)->env, env);
  (*shell)->online = online_mode();
  if (init_shell(shell, ac, av) == -1)
    return (-1);
  (*shell)->error = 0;
  (*shell)->end = 0;
  (*shell)->exit_val = EXIT_SUCCESS;
  return (xtgetent(NULL, "xterm"));
}

int		main(int ac, char **av, char **env)
{
  t_shell	*shell;
  int		val;

  if (ac > 2)
    return (my_error("USAGE: ./42sh <conf_file>"));
  if (loading_shell(&shell, env, ac, av) == -1)
    return (EXIT_FAILURE);
  if (prompt(shell) == -1)
    return (EXIT_FAILURE);
  save_history(shell->history, shell);
  if (shell->online->active == 1)
    modify_active(shell->online->pseudo, "0");
  val = shell->exit_val;
  free_shell(shell);
  return (val);
}
