/*
** read_inf.c for  in /home/mediav_j/piscine/colles/colle3
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sat Oct 26 18:03:57 2013 Jeremy Mediavilla
** Last update Sun Jun  8 11:21:15 2014 Jeremy Mediavilla
*/

#include "core.h"
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
      if (tmp->data == NULL)
	{
	  fprintf(stderr, "File corrupted, exiting\n");
	  exit(EXIT_FAILURE);
	}
      len = len + strlen(tmp->data);
      tmp = tmp->next;
    }
  final = my_xmalloc((len + 1) * sizeof(char));
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
  int		val;

  list = NULL;
  memset(buff, '\0', SIZE + 1);
  while ((val = read(fd, buff, SIZE)) != 0)
    {
      if (val == -1)
	{
	  fprintf(stderr, "Read Error\n");
	  exit(0);
	}
      if (list == NULL)
	list = create_list(strdup(buff));
      else
	add_to_end(list, strdup(buff));
      memset(buff, '\0', SIZE + 1);
    }
  final = cat_list(list);
  return (final);
}
