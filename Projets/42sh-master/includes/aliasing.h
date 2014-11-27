/*
** aliasing.h for aliasing in /home/martel_c/rendu/42sh/aliasing
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Mon May 12 16:06:42 2014 martelliere
** Last update Sat May 24 21:53:08 2014 Geoffrey Merran
*/

#ifndef ALIASING_H_
# define ALIASING_H_
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include "mysh.h"
# include "online.h"
# include "gnl.h"
# include "my.h"

/*
** Built in Alias
*/

int	builtin_alias(t_shell *shell, char **cmd);
int	add_shell_alias(t_shell *shell, char *name);
int	display_alias(t_alias *alias, char *name);
int    	display_all_alias(t_alias *alias);

/*
** Parsing & Initialisation alias
*/

int 	add_alias(t_alias *alias, char *name, char *content);
int    	get_alias(t_alias *alias, t_shell *shell);
int    	get_alias_content(char *alias, char **content);
int    	get_alias_things(char *alias, char **name, char **content);
int    	load_alias(t_alias *alias, int fd, t_shell *shell, int active);
int    	init_aliasing(t_shell **shell);

#endif /* _ALIASING_H_ */
