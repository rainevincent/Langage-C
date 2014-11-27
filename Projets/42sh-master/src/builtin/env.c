/*
** env.c for  in /home/mediav_j/mabm/42sh/src/builtin
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May  7 17:45:44 2014 Jeremy Mediavilla
** Last update Wed May 28 14:36:32 2014 Jeremy Mediavilla
*/

#include "core.h"

int             is_in_env(t_list *tmp, char *var)
{
  int           size;
  t_list	*list;

  list = tmp;
  size = strlen(var);
  while (list != NULL)
    {
      if (list->data != NULL)
        if (strncmp(list->data, var, size) == 0)
          return (1);
      list = list->next;
    }
  return (0);
}

char            *get_env_var(char *var, int len)
{
  char          *value;
  int           size;
  int           i;

  i = 0;
  size = strlen(var);
  if ((value = my_xmalloc((size - len + 1) * sizeof(char))) == NULL)
    return (NULL);
  memset(value, '\0', (size - len + 1));
  while (var[len])
    {
      value[i] = var[len];
      len++;
      i++;
    }
  return (value);
}

char            *check_env_var(t_list *list, char *name, int len)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->data != NULL)
        if (strncmp(tmp->data, name, len) == 0)
	  return (get_env_var(tmp->data, len));
      tmp = tmp->next;
    }
  return (NULL);
}

int		aff_env(t_shell *shell, char **cmd)
{
  t_list	*tmp;

  (void) cmd;
  tmp = shell->env;
  while (tmp != NULL)
    {
      if (tmp->data != NULL)
	printf("%s\n", tmp->data);
      tmp = tmp->next;
    }
  return (0);
}

void		get_all_env(t_list *list, char **env)
{
  int		i;

  i = 0;
  while (env[i])
    {
      add_to_end(list, strdup(env[i]));
      i++;
    }
}
