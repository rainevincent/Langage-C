/*
** gnl.h for gnl in /home/merran_g/work/c_elem/lem-in/lem_in/includes
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun Apr 27 16:43:28 2014 Geoffrey Merran
** Last update Sun Apr 27 16:44:58 2014 Geoffrey Merran
*/

#ifndef GNL_H
# define GNL_H
# define BUF_SIZE 5000
# define BUF_READ 5000

typedef struct	s_var
{
  char		*buffer;
  int		i;
  int	        pos;
  int		nb_read;
}		t_var;

char        *get_next_line(const int fd);

#endif /* GNL_H */
