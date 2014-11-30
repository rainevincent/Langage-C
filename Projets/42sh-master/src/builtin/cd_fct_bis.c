/*
** cd_fct_bis.c for  in /home/nicolas/Workspace/Unix/42sh/src/builtin
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Wed May 21 08:37:45 2014 Nicolas Ades
** Last update Wed May 28 04:36:10 2014 Geoffrey Merran
*/

#include "core.h"

int		create_oldpwd(t_shell *shell, char *new)
{
  char		*tmp;
  t_list	*list;

  list = shell->env;
  if (is_in_env(list, "PWD=") == 0)
    {
      fprintf(stderr, "CD : PWD missing, can't create OLDPWD\n");
      return (-1);
    }
  if ((tmp = check_env_var(shell->env, "PWD=", 4)) == NULL)
    return (-1);
  while (list != NULL)
    list = list->next;
  if ((tmp = my_xmalloc((strlen(new) + 8) * sizeof(*tmp))) == NULL)
    return (-1);
  memset(tmp, 0, (strlen(new) + 8));
  tmp = strcat(tmp, "OLDPWD=");
  tmp = strcat(tmp, new);
  add_to_end(list, tmp);
  return (0);
}

int		create_pwd(t_shell *shell, char *new)
{
  char		*tmp;
  t_list	*list;

  list = shell->env;
  while (list != NULL)
    list = list->next;
  if ((tmp = my_xmalloc((strlen(new) + 5) * sizeof(*tmp))) == NULL)
    return (-1);
  memset(tmp, 0, (strlen(new) + 5));
  tmp = strcat(tmp, "PWD=");
  tmp = strcat(tmp, new);
  add_to_end(list, tmp);
  return (0);
}
