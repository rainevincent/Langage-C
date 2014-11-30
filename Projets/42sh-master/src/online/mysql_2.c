/*
** mysql_2.c for 42 in /home/jobertomeu/Work/42sh/src/online
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun May 25 07:44:52 2014 Joris Bertomeu
** Last update Wed May 28 14:38:51 2014 Jeremy Mediavilla
*/

#include "my.h"
#include "online.h"

int		add_alias_from_bdd(t_alias *alias, t_shell *shell)
{
  MYSQL		mysql;
  MYSQL_RES	*result;
  MYSQL_ROW	row;

  mysql_init(&mysql);
  mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
  if (mysql_real_connect(&mysql, "10.16.253.124", "labelec",
			"epitech", "42", 0, NULL, 0))
    {
      mysql_query(&mysql, "SELECT * FROM alias");
      result = mysql_store_result(&mysql);
      printf("\033[37mFetching Alias Initialisation\t\t\t[OK]\033[00m\n");
      while ((row = mysql_fetch_row(result)))
	if (strcmp(row[3], shell->online->pseudo) == 0)
	  {
	    printf("\033[33mFetching alias command\t\t\t[OK]\033[00m\n");
	    add_alias(alias, strdup(row[1]), strdup(row[2]));
	  }
      mysql_close(&mysql);
      free(result);
    }
  else
    return (-1);
  return (1);
}

int		fetch_friends(char *user, int flag)
{
  MYSQL		mysql;
  MYSQL_RES	*result;
  MYSQL_ROW	row;

  mysql_init(&mysql);
  mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
  if (mysql_real_connect(&mysql, "10.16.253.124", "labelec",
			"epitech", "42", 0, NULL, 0))
    {
      mysql_query(&mysql, "SELECT * FROM friends");
      result = mysql_store_result(&mysql);
      printf("\033[37mFetching friends Initialisation\t\t\t[OK]\033[00m\n");
      while ((row = mysql_fetch_row(result)))
	if (strcmp(row[1], user) == 0)
	  printf("\033[33mFetching friend %s\t\t\t[OK]\033[00m\n", row[2]);
      mysql_close(&mysql);
      free(result);
    }
  else
    printf("\033[31mError server connection\t\t[ERROR]\033[00m\n");
  return (flag);
}

void	modify_active(char *user, char *active)
{
  MYSQL	mysql;
  char	*requete;

  mysql_init(&mysql);
  mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
  if (mysql_real_connect(&mysql, "10.16.253.124", "labelec",
			"epitech", "42", 0, NULL, 0))
    {
      if ((requete = my_xmalloc((strlen(user) + 100) * sizeof(char))) == NULL)
	return;
      sprintf(requete, "UPDATE 42_user SET active = '%s' WHERE user = '%s'",
	      active, user);
      mysql_query(&mysql, requete);
      mysql_close(&mysql);
      free(requete);
      if (active[0] == '1')
	printf("\033[36mSet %s active .. \t\t\t[OK]\033[00m\n", user);
      else
	printf("\033[36mSet %s inactive .. \t\t\t[OK]\033[00m\n", user);
    }
  else
    printf("\033[31mError connection server\t\t[ERROR]\033[00m\n");
}

void		add_cmd_history_mysql(t_shell *shell, char *cmd)
{
  MYSQL		mysql;
  char		*requete;
  static int	i = 0;

  if (i >= shell->online->num_hist)
    {
      mysql_init(&mysql);
      mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
      if (mysql_real_connect(&mysql, "10.16.253.124", "labelec",
			    "epitech", "42", 0, NULL, 0))
	{
	  if ((requete = my_xmalloc((strlen(cmd) + 100) * sizeof(char))) == NULL)
	    return;
	  sprintf(requete, "INSERT INTO history(id, id_private,\
 user, command, date) VALUES('', '0', '%s', '%s', '00')",
		  shell->online->pseudo, cmd);
	  mysql_query(&mysql, requete);
	  mysql_close(&mysql);
	  free(requete);
	  printf("\033[36mHistory saved online .. \t\t\t[OK]\033[00m\n");
	}
      else
	printf("\033[31mError connection server\t\t[ERROR]\033[00m\n");
    }
  i++;
}

void		add_cmd_history_mysql_manuel(char *cmd, char *pseudo)
{
  MYSQL		mysql;
  char		*requete;

  mysql_init(&mysql);
  mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
  if(mysql_real_connect(&mysql, "10.16.253.124", "labelec",
			"epitech", "42", 0, NULL, 0))
    {
      if ((requete = my_xmalloc(150 * sizeof(char))) == NULL)
	return;
      sprintf(requete, "INSERT INTO history(id, id_private,\
 user, command, date) VALUES('', '0', '%s', '%s', '%s')",
	      pseudo, cmd, return_date());
      mysql_query(&mysql, requete);
      mysql_close(&mysql);
      free(requete);
      printf("\033[36mHistory saved online .. \t\t\t[OK]\033[00m\n");
    }
  else
    printf("\033[31mError connection server\t\t[ERROR]\033[00m\n");
}
