/*
** mysql_1.c for 42 in /home/jobertomeu/Work/42sh
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun May 25 07:53:45 2014 Joris Bertomeu
** Last update Wed May 28 14:39:35 2014 Jeremy Mediavilla
*/

#include "my.h"
#include "online.h"

int		check_account(char *user, char *pass, int flag)
{
  MYSQL		mysql;
  MYSQL_RES	*result;
  MYSQL_ROW	row;

  mysql_init(&mysql);
  mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
  if (mysql_real_connect(&mysql, "10.16.253.124", "labelec",
			"epitech", "42", 0, NULL, 0))
    {
      mysql_query(&mysql, "SELECT * FROM 42_user");
      result = mysql_store_result(&mysql);
      while ((row = mysql_fetch_row(result)))
	if (strcmp(row[1], user) == 0 && strcmp(row[2], pass) == 0)
	  {
	    printf("Last connection : %s\n", row[3]);
	    flag = 1;
	  }
      mysql_close(&mysql);
      free(result);
    }
  else
    flag = -1;
  return (flag);
}

char		*return_date()
{
  char		*buffer;
  time_t	timestamp;

  buffer = malloc(256 * sizeof(*buffer));
  memset(buffer, 0, 256);
  timestamp = time(NULL);
  strftime(buffer, 256, "%x %H:%M", localtime(&timestamp));
  return (buffer);
}

void	modify_last(char *user)
{
  MYSQL	mysql;
  char	*requete;

  mysql_init(&mysql);
  mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
  if (mysql_real_connect(&mysql, "10.16.253.124", "labelec",
			"epitech", "42", 0, NULL, 0))
    {
      if ((requete = my_xmalloc(150 * sizeof(char))) == NULL)
	return;
      sprintf(requete, "UPDATE 42_user SET last = '%s' WHERE user = '%s'",
	      return_date(), user);
      mysql_query(&mysql, requete);
      mysql_close(&mysql);
      free(requete);
      printf("\033[36mLast connection modification .. \t\t[OK]\033[00m\n");
    }
  else
    printf("\033[31mError connection server\t\t[ERROR]\033[00m\n");
}

void	do_cop(t_online *sys, char *row, int i)
{
  sys->history[i] = malloc((strlen(row) + 1) * sizeof(char));
  strcpy(sys->history[i], row);
}

int		fetch_history(char *user, int i, int flag, t_online *sys)
{
  MYSQL		mysql;
  MYSQL_RES	*result;
  MYSQL_ROW	row;

  mysql_init(&mysql);
  mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
  if (mysql_real_connect(&mysql, "10.16.253.124", "labelec",
			"epitech", "42", 0, NULL, 0))
    {
      mysql_query(&mysql, "SELECT * FROM history");
      result = mysql_store_result(&mysql);
      printf("\033[37mFetching history Initialisation\t\t\t[OK]\033[00m\n");
      while ((row = mysql_fetch_row(result)))
	if (strcmp(row[2], user) == 0)
	  do_cop(sys, row[3], i++);
      sys->num_hist = i;
      sys->history[i] = NULL;
      mysql_close(&mysql);
      free(result);
    }
  else
    flag = -1;
  return (flag);
}
