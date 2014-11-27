/*
** left_redirect.c for 42 in /home/jobertomeu/Work/42sh/src/pipe
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun May 25 04:15:38 2014 Joris Bertomeu
** Last update Wed May 28 14:42:58 2014 Jeremy Mediavilla
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int	exec_cmd(int fd, char *cmd)
{
  int	pipefd[2];
  int	i;
  char	*tab[] = {"wc", "-l", NULL};
  char	*s;

  i = 0;
  if (pipe(pipefd) == -1)
    return (-1);
  while ((s = get_next_line(fd)) != NULL)
    {
      write(pipefd[1], s, strlen(s));
      write(pipefd[1], "\n", 1);
      free(s);
    }
  close(pipefd[1]);
  if (fork() == 0)
    {
      if (dup2(pipefd[0], 0) == -1)
	return (-1);
      execvp("/usr/bin/wc", tab);
      perror("Error : ");
      close(pipefd[0]);
    }
  else
    wait(NULL);
}

int	start_left_redirect(char **cmd)
{
  int	fd;
  char	**final;

  if (access(cmd[1], F_OK) == -1)
    {
      fprintf(stderr, "42sh: Redirection: can't access %s\n", cmd[1]);
      return (-1);
    }
  if (access(cmd[1], R_OK) == -1)
    {
      fprintf(stderr, "42sh: Redirection: can't read redirection file. \
Check your rights.\n");
      return (-1);
    }
  if ((fd = open(cmd[1], O_RDONLY)) == -1)
    return (-1);
  if (exec_cmd(fd, cmd[0]) == -1)
    return (-1);
}
int	main()
{
  char	**cmd;

  cmd = malloc(2 * sizeof(char*));
  cmd[0] = malloc(128 * sizeof(char));
  cmd[1] = malloc(128 * sizeof(char));
  strcpy(cmd[0], "cat");
  strcpy(cmd[1], "test.txt");
  start_left_redirect(cmd);
}
