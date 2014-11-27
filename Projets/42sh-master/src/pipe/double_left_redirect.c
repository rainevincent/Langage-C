/*
** double_left_redirect.c for 42 in /home/jobertomeu/Work/42sh/src/pipe
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun May 25 05:02:01 2014 Joris Bertomeu
** Last update Tue May 27 12:36:16 2014 Joris Bertomeu
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int	do_under_doublel(int *pipefd)
{
  char	*tab[] = {"wc", "-l", NULL};

  close(pipefd[1]);
  if (fork() == 0)
    {
      if (dup2(pipefd[0], 0) == -1)
	return (-1);
      execvp("/usr/bin/wc", tab);
      close(pipefd[0]);
    }
  else
    wait(NULL);
  return (1);
}

int	start_double_left_redirect(char **cmd)
{
  char	*s;
  int	pipefd[2];

  if (pipe(pipefd) == -1)
    return (-1);
  write(1, "> ", 3);
  while ((s = get_next_line(0)) != NULL)
    {
      if (strcmp(s, cmd[1]) == 0)
	{
	  free(s);
	  break;
	}
      else
	{
	  write(pipefd[1], s, strlen(s));
	  write(pipefd[1], "\n", 1);
	}
      free(s);
      write(1, "> ", 3);
    }
  return (do_under_doublel(pipefd));
}

int	main()
{
  char	**cmd;

  cmd = malloc(2 * sizeof(char*));
  cmd[0] = malloc(128 * sizeof(char));
  cmd[1] = malloc(128 * sizeof(char));
  strcpy(cmd[0], "wc -l");
  strcpy(cmd[1], "FIN");

  start_double_left_redirect(cmd);
}
