/*
** mysql_3.c for 42 in /home/jobertomeu/Work/42sh/src/online
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun May 25 07:45:45 2014 Joris Bertomeu
** Last update Wed May 28 14:39:11 2014 Jeremy Mediavilla
*/

#include "my.h"
#include "online.h"

int	modify_sys(t_online *sys, char *user)
{
  sys->active = 1;
  sys->is_history = 1;
  sys->is_alias = 1;
  sys->is_prompt = 1;
  if ((sys->pseudo = my_xmalloc((strlen(user) + 2) * sizeof(char))) == NULL)
    return (-1);
  memset(sys->pseudo, 0, strlen(user) + 1);
  strcpy(sys->pseudo, user);
  return (1);
}

int	check_sql(char *user, char *pass, t_online *sys)
{
  int	res;

  res = check_account(user, pass, 0);
  if (res == -1)
    printf("\033[31mError connection server\t\t[ERROR]\033[00m\n");
  else if (res == 0)
    {
      printf("\033[H\033[2J");
      printf("\033[31mUser and/or password wrong\t\t[ERROR]\033[00m\n");
      return (connection(sys));
    }
  else
    {
      printf("\033[33mYou are now connected as %s\t\t[OK]\033[00m\n", user);
      if (modify_sys(sys, user) == -1)
	return (-1);
      modify_last(user);
      fetch_history(user, 0, 0, sys);
      fetch_friends(user, 0);
      modify_active(user, "1");
    }
  return (1);
}

int	add_user(char *user, char *pass, t_online *sys)
{
  MYSQL	mysql;
  char	*requete;

  mysql_init(&mysql);
  mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
  if (mysql_real_connect(&mysql, "10.16.253.124", "labelec",
			"epitech", "42", 0, NULL, 0))
    {
      if ((requete = my_xmalloc(150 * sizeof(char))) == NULL)
	return (-1);
      sprintf(requete, "INSERT INTO 42_user(id, user, pass, last)\
 VALUES('NULL', '%s', '%s', '' )", user, pass);
      mysql_query(&mysql, requete);
      mysql_close(&mysql);
      free(requete);
      add_cmd_history_mysql_manuel("Init OK", user);
      printf("\033[H\033[2J");
      printf("\033[33mYour account have been created as\
 %s\t\t[OK]\033[00m\n", user);
      return (connection(sys));
    }
  else
    printf("\033[31mError connection server\t\t[ERROR]\033[00m\n");
  return (-1);
}

int		check_user_exist(char *user, int flag)
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
	if (strcmp(row[1], user) == 0)
	  {
	    printf("\033[H\033[2J");
	    printf("\033[31mAn account\
 with this login already exists\t\t[ERROR]\033[00m\n");
	    flag = 1;
	  }
      mysql_close(&mysql);
      free(result);
    }
  else
    flag = -1;
  return (flag);
}

char			*getpassword()
{
  static struct termios oldt;
  static struct termios newt;
  int			i;
  int			c;
  char			*tmp;

  i = 0;
  tmp = my_xmalloc(4096 * sizeof(*tmp));
  memset(tmp, 0, 4096);
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  while ((c = getchar()) != '\n' && c != EOF && i < 4095)
    tmp[i++] = c;
  tmp[i] = '\0';
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return (tmp);
}
