/*
** conf.h for conf in /home/merran_g/work/c_elem/42sh/src/conf
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu May 15 21:06:01 2014 Geoffrey Merran
** Last update Tue May 27 23:14:07 2014 Jeremy Mediavilla
*/

#ifndef CONF_
# define CONF_
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "gnl.h"
# include "mysh.h"
# include "my.h"

/*
** Load conf
*/

int	load_conf(t_shell **shell, char *path);
int	parse_conf(t_shell **shell, char **line);
int	get_conf(t_shell **shell, int fd);
void	free_tab(char **t);

/*
** Get Default conf
*/

int	default_conf(t_shell **shell);

#endif /* CONF_ */
