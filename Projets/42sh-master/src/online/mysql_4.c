/*
** mysql_4.c for 42 in /home/jobertomeu/Work/42sh/src/online
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun May 25 07:46:54 2014 Joris Bertomeu
** Last update Sun May 25 07:51:51 2014 Joris Bertomeu
*/

#include "my.h"
#include "online.h"

char	*clean(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\n' && str[i])
    i++;
  str[i] = 0;
  return (str);
}

int	create_user(t_online *sys)
{
  char	user[4096];
  char	*pass;

  memset(user, 0, 4096);
  write(1, "Desired username : ", 20);
  if (read(0, user, 4096) <= 0)
    return (-1);
  write(1, "Password : ", 12);
  pass = getpassword();
  if (check_user_exist(clean(user), 0) != 1)
    return (add_user(clean(user), pass, sys));
  else
    return (create_user(sys));
  return (1);
}

int	aff_bdd_error(char *msg)
{
  fprintf(stderr, "%s", msg);
  return (-1);
}
