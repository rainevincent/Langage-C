/*
** debug.h for debug in /home/merran_g/work/c_elem/lem-in/lem_in
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri May  2 18:39:11 2014 Geoffrey Merran
** Last update Fri May  2 18:41:54 2014 Geoffrey Merran
*/

#ifndef DEBUG_
# define DEBUG_
# include <stdio.h>
# include "lem_in.h"
# include "my.h"

void		aff_map(t_map *map);
void		aff_access(t_access *access);
void		aff_way(t_way *way);
void		aff_path(t_access *path);
void		aff_tiret(int val);

#endif /* DEBUG_ */
