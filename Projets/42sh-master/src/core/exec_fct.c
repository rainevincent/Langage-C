/*
** exec_fct.c for exec in /home/merran_g/work/c_elem/42sh
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue May 27 23:45:49 2014 Geoffrey Merran
** Last update Wed May 28 10:07:14 2014 Joris Bertomeu
*/

#include "core.h"

int		list_size(t_list *list)
{
  int		i;
  t_list	*tmp;

  tmp = list;
  i = 0;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

char		**env_in_tab(t_list *list)
{
  char		**mtab;
  int		size;
  int		i;
  int		len;
  t_list	*tmp;

  i = 0;
  size = list_size(list);
  mtab = my_xmalloc((size + 1) * sizeof(char *));
  tmp = list->next;
  while (tmp != NULL)
    {
      len = strlen(tmp->data) + 1;
      mtab[i] = my_xmalloc(len * sizeof(char));
      memset(mtab[i], '\0', len);
      mtab[i] = tmp->data;
      tmp = tmp->next;
      i++;
    }
  mtab[i - 1] = NULL;
  return (mtab);
}
