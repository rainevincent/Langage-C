/*
** core.h for core in /home/merran_g/work/c_elem/lem-in
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun May  4 15:13:55 2014 Geoffrey Merran
** Last update Sun May  4 19:17:13 2014 Geoffrey Merran
*/

#ifndef CORE_
# define CORE_
# include "lem_in.h"
# include "parser.h"
# include "debug.h"

/*
** Finds ways to end
*/

t_path		*find_ways(t_map *map);
void		travel_rooms(t_map *map, t_room *current, int value, t_path *path);
t_room		*find_room(t_map *map, char *room_name);
void		init_path(t_path **path);
void		get_path(t_path *path, int size_path);
void		fill_path(char ***path, t_access *access);
void		put_in_path(t_way **ways, t_way *new);
void		remove_last_access(t_access **access);

/*
** Push ants to the end
*/

void		init_anthill(t_anthill **anthill);
void		add_ant(t_anthill *anthill, int id, t_way *way);
void		push_ants(t_map *map, t_anthill *anthill);
int		move_next_room(t_map *map, t_ant *ant, int esp);
void		create_ants(t_map *map, t_anthill *anthill, t_way *way);
t_ant		*remove_ant(t_ant *ant, t_anthill *anthill);

/*
** Lem_in
*/

void		lem_in_take_a_selfie(t_map *map, t_way *way);
void		lem_in();

/*
** Free
*/

void		free_access(t_access *access);
void		free_map(t_map *map);
void		free_ways(t_way *ways);

#endif /* CORE_ */
