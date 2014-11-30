/*
** get_true_pwd.c for 42sh in /home/martel_c/rendu/42sh
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Tue May 27 12:09:49 2014 martelliere
** Last update Wed May 28 04:48:35 2014 Geoffrey Merran
*/

#include "core.h"

void            *my_xrealloc(char *str, int size)
{
  char          *new_str;

  if (size == 0)
    return (str);
  new_str = my_xmalloc((strlen(str) + size + 1) * sizeof(char));
  *new_str = '\0';
  strcat(new_str, str);
  if (str == NULL)
    exit(EXIT_FAILURE);
  free(str);
  return (new_str);
}

int	dirlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '/' && str[i] != '\0')
    i++;
  return (i);
}

void	dircat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    i++;
  while (src[j] != '/' && src[j] != '\0')
    dest[i++] = src[j++];
  dest[i] = '/';
  dest[i + 1] = '\0';
}

char	*modif_path(char *true_pwd, char *path)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (path[i] != '\0')
    {
      if (strncmp(&path[i], "../", 3) == 0)
	{
	  j = strlen(true_pwd) - 2;
	  while (true_pwd[j] != '/')
	    true_pwd[j--] = '\0';
	  i += 3;
	}
      else
	{
	  true_pwd = my_xrealloc(true_pwd, dirlen(&path[i]) + 1);
	  dircat(true_pwd, &path[i]);
	  i += dirlen(&path[i]) + 1;
	}
    }
  return (true_pwd);
}
