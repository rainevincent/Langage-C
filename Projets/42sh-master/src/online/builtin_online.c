/*
** builtin_online.c for 42SH in /home/jobertomeu/Work/42sh
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed May 21 16:58:05 2014 Joris Bertomeu
** Last update Wed May 28 14:41:24 2014 Jeremy Mediavilla
*/

#include "core.h"
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <mysql.h>
#include <my_global.h>
#include <time.h>
#include <termios.h>

int	check_user_exist_friend(char *user, int flag)
{
  MYSQL		mysql;
  MYSQL_FIELD	*field;
  MYSQL_RES	*result = NULL;
  MYSQL_ROW	row;
  unsigned int	num_champs = 0;

  mysql_init(&mysql);
  mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
  if (mysql_real_connect(&mysql, "mysql1.alwaysdata.com", "labelec",
			"epitech42", "labelec_epibot", 0, NULL, 0))
    {
      mysql_query(&mysql, "SELECT * FROM 42_user");
      result = mysql_store_result(&mysql);
      num_champs = mysql_num_fields(result);
      while ((row = mysql_fetch_row(result)))
	if (strcmp(row[1], user) == 0)
	  flag = 1;
      mysql_close(&mysql);
    }
  else
    flag = -1;
  free(result);
  return (flag);
}

int	check_friend_with(char *user, char *friend, int flag)
{
  MYSQL		mysql;
  MYSQL_FIELD	*field;
  MYSQL_RES	*result = NULL;
  MYSQL_ROW	row;
  unsigned int	num_champs = 0;

  mysql_init(&mysql);
  mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
  if (mysql_real_connect(&mysql, "mysql1.alwaysdata.com", "labelec",
			"epitech42", "labelec_epibot", 0, NULL, 0))
    {
      mysql_query(&mysql, "SELECT * FROM friends");
      result = mysql_store_result(&mysql);
      num_champs = mysql_num_fields(result);
      while ((row = mysql_fetch_row(result)))
	if (strcmp(row[1], user) == 0 && strcmp(row[2], friend) == 0)
	  flag = 1;
      mysql_close(&mysql);
    }
  else
    flag = -1;
  free(result);
  return (flag);
}

void	add_friend_valid(char *user, char *friend)
{
  MYSQL	mysql;
  char	*requete;

  mysql_init(&mysql);
  mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
  if (mysql_real_connect(&mysql, "mysql1.alwaysdata.com", "labelec",
			"epitech42", "labelec_epibot", 0, NULL, 0))
    {
      requete = malloc(150 * sizeof(char));
      sprintf(requete, "INSERT INTO request(id, from_user, for, date)\
 VALUES('NULL', '%s', '%s', '%s')", user, friend, return_date());
      printf("REQUETE : %s\n", requete);
      mysql_query(&mysql, requete);
      mysql_close(&mysql);
      free(requete);
      printf("Friend request for %s have been sent\n", friend);
    }
  else
    printf("Error connection server\n");
}

char	*cut_arg(char *cmd)
{
  int	i;
  char	*tmp;

  tmp = malloc(strlen(cmd) * sizeof(*tmp));
  memset(tmp, 0, strlen(cmd));
  i = 0;
  while (cmd[i] != ' ' && cmd[i])
    i++;
  strcpy(tmp, &cmd[i + 1]);
  return (tmp);
}

void	my_add_friend(t_list *list, char *cmd)
{
  char	*pseudo = "jobertomeu";
  char	*friend;

  friend = cut_arg(cmd);
  (void) list;

  if (check_user_exist_friend(friend, 0) == 1
      && check_friend_with(pseudo, friend, 0) != 1)
    add_friend_valid(pseudo, friend);
  else
    printf("%s is not an user available or your \
are friend with yet\n", friend);
}
