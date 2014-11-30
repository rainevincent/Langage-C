/*
** lem_in.h for lem_in in /home/merran_g/work/c_elem/lem-in/lem_in/includes
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr 22 14:58:46 2014 Geoffrey Merran
** Last update Sun May  4 18:26:00 2014 Geoffrey Merran
*/

#ifndef LEM_IN_
# define LEM_IN_

typedef	struct		s_access
{
  char			*name;
  struct s_access	*next;
}			t_access;

typedef struct	s_room
{
  int		val;
  char		*name;
  t_access	*access;
  struct s_room	*next;
  struct s_room *prev;
}		t_room;

typedef struct	s_map
{
  int		nb_ants;
  int		nb_room;
  t_room	*start;
  t_room	*end;
  t_room	*head;
  t_room	*tail;
}		t_map;

typedef struct	s_info
{
  int		type;
  int		command;
}		t_info;

typedef struct	s_way
{
  char		**path;
  int		size;
  struct s_way	*next;
  struct s_way	*prev;
}		t_way;

typedef struct	s_path
{
  t_access	*access;
  t_way		*way;
}		t_path;

typedef struct	s_ant
{
  int		id;
  int		room;
  t_way		*way;
  struct s_ant 	*next;
  struct s_ant 	*prev;
}		t_ant;

typedef	struct	s_anthill
{
  t_ant		*head;
  t_ant		*tail;
  int		nb_ants;
}		t_anthill;

#endif /* LEM_IN_ */
