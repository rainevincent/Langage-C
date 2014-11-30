/*
** load_alias.c for load_alias in /home/merran_g/work/c_elem/42sh
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sat May 24 05:06:34 2014 Geoffrey Merran
** Last update Sat May 24 17:10:20 2014 Joris Bertomeu
*/

#include "aliasing.h"

int		get_alias_content(char *alias, char **content)
{
  int		i;

  i = 0;
  if (alias[i++] != '\'')
    return (-1);
  while (alias[i] && alias[i] != '\'')
    i++;
  if (alias[i] == '\0' || i == 1)
    return (-1);
  *content = my_xmalloc(i * sizeof(char));
  if (*content == NULL)
    return (-1);
  memset(*content, 0, i);
  strncpy(*content, &alias[1], i - 1);
  return (0);
}

int		get_alias_things(char *alias, char **name, char **content)
{
  int		i;

  i = 0;
  while (alias[i] && alias[i] != '=')
    i++;
  if (alias[i] == '\0' || i == 0)
    return (-1);
  *name = my_xmalloc((i + 1) * sizeof(char));
  if (*name == NULL)
    return (-1);
  memset(*name, 0, (i + 1));
  strncpy(*name, alias, i);
  if (get_alias_content(&alias[i + 1], content) == -1)
    {
      free(*name);
      return (-1);
    }
  return (0);
}

int		load_alias(t_alias *alias, int fd, t_shell *shell, int active)
{
  char		*s;
  char		*name;
  char		*content;

  if (active == 0)
    while ((s = get_next_line(fd)) != NULL)
      {
	if (strncmp("alias ", s, 6) == 0)
	  {
	    if (get_alias_things(&s[6], &name, &content) != -1)
	      add_alias(alias, name, content);
	  }
	free(s);
      }
  else
    add_alias_from_bdd(alias, shell);
  return (0);
}

