/*
** double_right_redirect.c for 42 in /home/jobertomeu/Work/42sh/src/pipe
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun May 25 06:45:20 2014 Joris Bertomeu
** Last update Sun May 25 07:42:38 2014 Joris Bertomeu
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int	start_double_right_redirect(char **cmd)
{
  int	fd;
  int	pipefd[2];
  int	i;
  char	*tab[] = {"ls", "-l", NULL};
  char	*s;
  char	buff[4096];

  i = 0;
  if (pipe(pipefd) == -1)
    return (-1);
  if (fork() == 0)
    {
      if (dup2(pipefd[1], 1) == -1)
	return (-1);
      execvp("/bin/ls", tab);
      perror("Error : ");
      close(pipefd[0]);
    }
  else
    wait(NULL);
  if ((fd = open(cmd[1], O_WRONLY | O_CREAT | O_APPEND, 0666)) == -1)
    return (-1);
  if (read(pipefd[0], buff, 4096) <= 0)
    return (-1);
  close(pipefd[0]);
  write(fd, buff, strlen(buff));
}

int	main()
{
    char	**cmd;

  cmd = malloc(2 * sizeof(char*));
  cmd[0] = malloc(128 * sizeof(char));
  cmd[1] = malloc(128 * sizeof(char));
  strcpy(cmd[0], "cat");
  strcpy(cmd[1], "test2.txt");
  start_double_right_redirect(cmd);
}
