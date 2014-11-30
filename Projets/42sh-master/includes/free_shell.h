/*
** free_shell.h for free_shell in /home/merran_g/work/c_elem/42sh/src/free
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu May 22 23:46:29 2014 Geoffrey Merran
** Last update Sat May 24 22:39:43 2014 Geoffrey Merran
*/

#ifndef FREE_SHELL_
# define FREE_SHELL_
# include <stdlib.h>
# include "mysh.h"

void		free_tab(char **t);
void		free_history(t_history *history);
void		free_shell(t_shell *shell);
void		free_env(t_list	*env);
void		free_online(t_online *online);

#endif /* FREE_SHELL_ */
