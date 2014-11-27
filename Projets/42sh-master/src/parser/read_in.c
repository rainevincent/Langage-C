/*
** read_inf.c for  in /home/mediav_j/piscine/colles/colle3
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sat May 27 18:03:57 2016 Jeremy Mediavision
** Last update Wed May 28 04:32:28 2014 Joris Bertomeu
*/

#include "core.h"
#include "parser.h"
# define SIZE (4096)

char		*cat_list(t_list *list)
{
  t_list	*tmp;
  char		*final;
  int		len;

  tmp = list;
  len = 0;
  while (tmp != NULL)
    {
      len = len + strlen(tmp->data);
      tmp = tmp->next;
    }
  if ((final = my_xmalloc((len + 1) * sizeof(char))) == NULL)
    return (NULL);
  memset(final, '\0', len + 1);
  while (list != NULL)
    {
      final = strcat(final, list->data);
      list = list->next;
    }
  return (final);
}

char		*my_read_inf(int fd)
{
  char		*final;
  char		buff[SIZE + 1];
  t_list	*list;

  list = NULL;
  memset(buff, '\0', SIZE + 1);
  while (read(fd, buff, SIZE) != 0)
    {
      if (list == NULL)
	list = create_list(strdup(buff));
      else
	add_to_end(list, strdup(buff));
      memset(buff, '\0', SIZE + 1);
    }
  final = cat_list(list);
  return (final);
}
