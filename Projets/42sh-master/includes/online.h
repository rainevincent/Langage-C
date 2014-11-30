/*
** online.h for online in /home/merran_g/work/c_elem/42sh
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sat May 24 05:46:56 2014 Geoffrey Merran
** Last update Sun May 25 17:17:45 2014 Geoffrey Merran
*/

#ifndef ONLINE_
# define ONLINE_
# include <stdlib.h>
# include <stdio.h>
# include <curses.h>
# include <mysql.h>
# include <my_global.h>
# include <time.h>
# include <termios.h>
# include "aliasing.h"
# include "mysh.h"

# define modeCANON    0
# define modeNonCANON 1

int	connection(t_online *sys);
void   	add_cmd_history_mysql(t_shell *shell, char *cmd);
void	modify_active(char *user, char *active);
int	add_alias_from_bdd(t_alias *alias, t_shell *shell);
int	fetch_friends(char *user, int flag);
void	modify_active(char *user, char *active);
void	add_cmd_history_mysql(t_shell *shell, char *cmd);
void	add_cmd_history_mysql_manuel(char *cmd, char *pseudo);
int	modify_sys(t_online *sys, char *user);
int	check_sql(char *user, char *pass, t_online *sys);
int	add_user(char *user, char *pass, t_online *sys);
int	check_user_exist(char *user, int flag);
char	*getpassword();
char	*clean(char *str);
int	create_user(t_online *sys);
int	check_account(char *user, char *pass, int flag);
char	*return_date();
void	modify_last(char *user);
void	do_cop(t_online *sys, char *row, int i);
int	fetch_history(char *user, int i, int flag, t_online *sys);
int	aff_bdd_error(char *msg);

#endif /* ONLINE_ */
