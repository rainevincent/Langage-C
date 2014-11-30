/*
** my_list.h for  in /home/mediav_j/piscine/eval_expr
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Fri Oct 25 13:42:59 2013 Jeremy Mediavilla
** Last update Thu May 22 23:56:06 2014 Geoffrey Merran
*/

#ifndef MY_LIST_H
# define MY_LIST_H

typedef		struct s_list
{
  char			*data;
  struct s_list		*next;
  struct s_list		*prev;
}			t_list;

t_list		*create_list(char *);
void		add_after(t_list *, char *);
void		add_before(t_list *, char *);
void		remove_from_list(t_list *);
void		add_to_end(t_list *, char *);
void		debug_list(t_list *);
t_list		*get_first(t_list *);

#endif /* MY_LIST_H */
