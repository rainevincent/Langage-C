/*
** pipe.c for  in /home/mediav_j/mabm/42sh/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May 28 14:37:02 2014 Jeremy Mediavilla
** Last update Wed May 28 14:37:03 2014 Jeremy Mediavilla
*/

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "pipe.h"

int	sub_exec_pipe_first(t_pipe *pipes)
{
  pipes->tmp = read(pipes->pipefd[0], pipes->t, 4096);
  close(pipes->pipefd[1]);
  close(pipes->pipefd[0]);
  if (pipe(pipes->pipefd) == -1)
    return (-1);
  if (pipe(pipes->pipefd2) == -1)
    return (-1);
  write(pipes->pipefd[1], pipes->t, pipes->tmp);
  close(pipes->pipefd[1]);
  return (1);
}

int	sub_exec_pipe_second(t_pipe *pipes)
{
  pipes->tmp = read(pipes->pipefd2[0], pipes->t, 4096);
  close(pipes->pipefd2[1]);
  close(pipes->pipefd2[0]);
  if (pipe(pipes->pipefd) == -1)
    return (-1);
  write(pipes->pipefd[1], pipes->t, pipes->tmp);
  close(pipes->pipefd[1]);
  return (1);
}

int	do_pipe_middle(t_pipe *pipes)
{
  if (sub_exec_pipe_first(pipes) == -1)
    return (-1);
  if ((pipes->pid = fork()) == 0)
    {
      if (dup2(pipes->pipefd[0], 0) == -1)
	printf("\nFAILED DUP2\n");
      if (dup2(pipes->pipefd2[1], 1) == -1)
	printf("\nFAILED DUP2\n");
      execvp(pipes->cmds[pipes->i][0], &(pipes->cmds[pipes->i][1]));
      perror("erreur from middle");
    }
  if (waitpid(pipes->pid, &(pipes->status), 0) == -1)
    printf("\nErreur Waitpid\n");
  if (sub_exec_pipe_second(pipes) == -1)
    return (-1);
  return (1);
}

int	do_pipe_first(t_pipe *pipes)
{
  if ((pipes->pid = fork()) == 0)
    {
      close(pipes->pipefd[0]);
      if (dup2(pipes->pipefd[1], 1) == -1)
	return (-1);
      execvp(pipes->cmds[pipes->i][0], &(pipes->cmds[pipes->i][1]));
    }
  if (waitpid(pipes->pid, &(pipes->status), 0) == -1)
    return (-1);
}

int	do_pipe_end(t_pipe *pipes)
{
  if (pipes->total == 2)
    {
      pipes->tmp = read(pipes->pipefd[0], pipes->t, 4096);
      close(pipes->pipefd[1]);
      close(pipes->pipefd[0]);
      if (pipe(pipes->pipefd2) == -1)
	return (-1);
      write(pipes->pipefd2[1], pipes->t, pipes->tmp);
      close(pipes->pipefd2[1]);
    }
  if ((pipes->pid = fork()) == 0)
    {
      if (dup2(pipes->pipefd[0], 0) == -1)
	return (-1);
      execvp(pipes->cmds[pipes->i][0], &(pipes->cmds[pipes->i][1]));
    }
  if (waitpid(pipes->pid, &(pipes->status), 0) == -1)
    return (-1);
  return (1);
}

int		do_pipe(t_pipe *pipes)
{
  pipes->i = 0;
  if (pipe(pipes->pipefd) == -1)
    return (-1);
  while (pipes->i < pipes->total)
    {
      if (pipes->i == 0)
	do_pipe_first(pipes);
      else if (pipes->i == pipes->total -1)
	if (do_pipe_end(pipes) == -1)
	  return (-1);
      else
	if (do_pipe_middle(pipes) == -1)
	  return (-1);
      pipes->i++;
    }
  return (1);
}

int	main(int ac, char *argv[])
{
  t_pipe	*pipe;

  pipe = malloc(sizeof(*pipe));
  pipe->cmds = malloc(5 * sizeof(char **));

  pipe->cmds[0] = malloc(10 * sizeof(char*));
  pipe->cmds[0][0] = malloc(128 * sizeof(char));
  strcpy(pipe->cmds[0][0], "/usr/bin/env");
  pipe->cmds[0][1] = malloc(128 * sizeof(char));
  strcpy(pipe->cmds[0][1], "env");
  pipe->cmds[0][2] = malloc(128 * sizeof(char));
  pipe->cmds[0][2] = NULL;

  pipe->cmds[1] = malloc(10 * sizeof(char*));
  pipe->cmds[1][0] = malloc(128 * sizeof(char));
  strcpy(pipe->cmds[1][0], "/bin/grep");
  pipe->cmds[1][1] = malloc(128 * sizeof(char));
  strcpy(pipe->cmds[1][1], "grep");
  pipe->cmds[1][2] = malloc(128 * sizeof(char));
  strcpy(pipe->cmds[1][2], "-e");
  pipe->cmds[1][3] = malloc(128 * sizeof(char));
  strcpy(pipe->cmds[1][3], "HOME");
  pipe->cmds[1][4] = malloc(128 * sizeof(char));
  pipe->cmds[1][4] = NULL;

  pipe->cmds[2] = malloc(10 * sizeof(char*));
  pipe->cmds[2][0] = malloc(128 * sizeof(char));
  strcpy(pipe->cmds[2][0], "/bin/less");
  pipe->cmds[2][1] = malloc(128 * sizeof(char));
  strcpy(pipe->cmds[2][1], "less");
  pipe->cmds[2][2] = malloc(128 * sizeof(char));
  pipe->cmds[2][2] = NULL;

  pipe->cmds[3] = malloc(10 * sizeof(char*));
  pipe->cmds[3][0] = malloc(128 * sizeof(char));
  strcpy(pipe->cmds[3][0], "/bin/cat");
  pipe->cmds[3][1] = malloc(128 * sizeof(char));
  strcpy(pipe->cmds[3][1], "cat");
  pipe->cmds[3][2] = malloc(128 * sizeof(char));
  pipe->cmds[3][2] = NULL;

  pipe->total = 2;

  if (do_pipe(pipe) != -1)
    printf("\t\t\t\t\t\t=> Infinite Pipe successed\n");
  else
    printf("\t\t\t\t\t\t=> Infinite Pipe failed\n");
}

