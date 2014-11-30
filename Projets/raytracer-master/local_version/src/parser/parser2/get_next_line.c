/*
** get_next_line.c for get_next_line in /home/martel_c/rendu/get_next_line-2013-martel_c
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Mon Nov 18 13:44:17 2013 martelliere
** Last update Mon Jun  2 13:33:21 2014 martelliere
*/

#include "get_next_line.h"
#include "parser.h"

int		my_strlen_line(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char		*my_strcat(char *dest, char *src)
{
  int		dest_length;
  int		i;

  dest_length = my_strlen_line(dest);
  i = 0;
  while (src[i] != '\0')
    {
      dest[dest_length + i] = src[i];
      i = i + 1;
    }
  dest[dest_length + i] = '\0';
  return (dest);
}

void            *my_xmalloc_line(char *str, int size, int flag)
{
  char          *new_str;

  if (flag == 1)
    {
      new_str = malloc(size);
      if (new_str == NULL)
	return (NULL);
    }
  else
    {
      if (size == 0)
	return (str);
      new_str = my_xmalloc_line(str, (my_strlen_line(str) + size + 1) *
				sizeof(char), 1);
      if (new_str == 0)
	exit(1);
      *new_str = '\0';
      my_strcat(new_str, str);
      *str = '\0';
      free(str);
    }
  return (new_str);
}

int             check_line(char *line, char *tmp)
{
  int           i;

  i = 0;
  while (line[i] != '\0')
    {
      if (line[i] == '\n')
        {
          line[i] = '\0';
          *tmp = '\0';
          my_strcat(tmp, &line[i + 1]);
          return (-1);
        }
      i++;
    }
  *tmp = '\0';
  return (0);
}

char            *get_next_line(const int fd)
{
  int           i;
  char          *line;
  static char   tmp[NB_CHAR_READ];

  line = NULL;
  line = my_xmalloc_line(line, NB_CHAR_READ * sizeof(char), 1);
  if (fd < 0 || line == 0)
    return (NULL);
  *line = '\0';
  my_strcat(line, tmp);
  *tmp = '\0';
  i = NB_CHAR_READ;
  while (check_line(line, tmp) != -1 && i == NB_CHAR_READ)
    {
      i = read(fd, tmp, NB_CHAR_READ);
      if (i == -1)
        return (NULL);
      tmp[i] = '\0';
      line = my_xmalloc_line(line, i, 0);
      my_strcat(line, tmp);
    }
  if (*line == '\0' && my_strlen_line(tmp) == 0 && i != NB_CHAR_READ)
    return (0);
  return (line);
}
