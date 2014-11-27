/*
** builtin.c for  in /home/mediav_j/mabm/42sh/src/builtin
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May  7 17:42:12 2014 Jeremy Mediavilla
** Last update Sun May 25 21:49:54 2014 Geoffrey Merran
*/

#include "core.h"

int             already_here(t_list *list, char *var, int len)
{
  while (list != NULL)
    {
      if (list->data != NULL)
        if (strncmp(list->data, var, len) == 0)
          {
            memset(list->data, '\0', strlen(list->data));
            list->data = var;
            return (1);
          }
      list = list->next;
    }
  return (0);
}

int		my_unsetenv(t_shell *shell, char **cmd)
{
  char          *var;
  t_list	*tmp;
  int           name_len;

  tmp = shell->env;
  if (tab_size(cmd) != 2)
    printf("Unsetenv : wrong number of arguments\n");
  else
    {
      name_len = strlen(cmd[1]);
      var = init_unsetenv_var(name_len, cmd);
      while (tmp != NULL)
	{
	  if (tmp->data != NULL)
	    if (strncmp(tmp->data, var, (name_len + 1)) == 0)
	      {
		remove_from_list(tmp);
		return (0);
	      }
	  tmp = tmp->next;
	}
      fprintf(stderr, "%s : is not an environment variable\n", cmd[1]);
      free(var);
    }
  return (-1);
}

int		my_setenv(t_shell *shell, char **cmd)
{
  char          *var;
  t_list	*tmp;
  int           name_len;
  int           value_len;

  tmp = shell->env;
  if (tab_size(cmd) != 3)
    return (my_error("Setenv : wrong number of arguments\n"));
  else
    {
      name_len = strlen(cmd[1]);
      value_len = strlen(cmd[2]);
      var = my_xmalloc((name_len + value_len + 2) * sizeof(char));
      memset(var, '\0' , (name_len + value_len + 2));
      var = strcat(var, cmd[1]);
      var = strcat(var, "=");
      var = strcat(var, cmd[2]);
      if (already_here(tmp, var, (name_len + 1)) != 1)
	add_to_end(shell->env, var);
      else
	return (-1);
    }
  return (0);
}

int		my_pwd(t_shell *shell, char **cmd)
{
  char		*pwd;

  (void) cmd;
  if ((pwd = check_env_var(shell->env, "PWD=", 4)) == NULL)
    {
      fprintf(stderr, "Can't find PWD in env\n");
      return (-1);
    }
  printf("%s\n", pwd);
  return (0);
}
