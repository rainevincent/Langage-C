/*
** curse.c for curse in /home/merran_g/work/c_elem/42sh
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sat May 24 05:47:33 2014 Geoffrey Merran
** Last update Sun May 25 07:56:52 2014 Joris Bertomeu
*/

#include "my.h"
#include "online.h"

int	connection(t_online *sys)
{
  char	user[4096];
  char	*pass;

  memset(user, 0, 4096);
  printf("If you doesn't have an account, type 'create'\
in \"Username\" input\n\n");
  write(1, "Username : ", 12);
  if (read(0, user, 4096) <= 0)
    return (aff_bdd_error("Error Read\n"));
  if (strncmp(user, "create", 6) == 0)
    return (create_user(sys));
  else
    {
      write(1, "Password : ", 12);
      pass = getpassword();
      printf("\nConnecting %s ...\t\t\t[OK]\n", clean(user));
      return (check_sql(clean(user), clean(pass), sys));
      free(pass);
    }
  return (1);
}

void	aff_pres()
{
  printf("o----------------o\n");
  printf("|   42SH MODE ?  |\n");
  printf("| 'y' -> Online  |\n");
  printf("| 'n' -> Offline |\n");
  printf("o----By_mabm-----o\n\n");
}

int	init_struct(t_online *sys)
{
  sys->active = 0;
  sys->is_history = 0;
  sys->is_alias = 0;
  sys->is_prompt = 0;
  if ((sys->history = my_xmalloc(4096 * sizeof(char*))) == NULL)
    return (-1);
  return (1);
}

t_online	*online_mode()
{
  char		buff[4096];
  t_online	*sys;

  if ((sys = my_xmalloc(sizeof(*sys))) == NULL)
    return (NULL);
  if (init_struct(sys) == -1)
    return (NULL);
  aff_pres();
  memset(buff, 0, 4096);
  write(1, "Your choice : ", 15);
  if (read(0, buff, 4096) <= 0)
    printf("Read error\n");
  if (buff[0] == 'y')
    {
      if (connection(sys) == -1)
	return (NULL);
      return (sys);
    }
  else
    return (sys);
  return (sys);
}
