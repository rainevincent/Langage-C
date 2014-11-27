/*
** get_next_line.h for get_next_line in /home/martel_c/rendu/get_next_line-2013-martel_c
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Mon Nov 18 13:32:24 2013 martelliere
** Last update Wed Apr  2 18:08:17 2014 martelliere
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define NB_CHAR_READ (80)

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

void *my_xmalloc_line(char *str, int size, int flag);
char *my_strcat(char *dest, char *src);
char *get_next_line(const int fd);
int my_is_ret(char *line, char *tmp);
int my_strlen_line(char *str);
void my_stock_line(int *i, char *line, char *tmp, const int *fd);

#endif /* GET_NEXT_LINE_H_ */
