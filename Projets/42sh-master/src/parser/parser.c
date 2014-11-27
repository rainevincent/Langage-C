/*
** parser.c for parser in /home/merran_g/work/c_elem/42sh
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed May 28 02:53:09 2014 Geoffrey Merran
** Last update Wed May 28 14:42:24 2014 Jeremy Mediavilla
*/

#include "parser.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

char	*my_read_inf(int fd);

int		wait_father(pid_t pid)
{
  int		status;

  while (pid != wait4(pid, &status, WNOHANG, 0))
    {
    }
  return (status);
}

void	right_redirect(char *left, char *right)
{
  int	fd;

  if ((fd = open(right, O_WRONLY | O_TRUNC | O_CREAT, 0666)) == -1)
    perror("Erreur : ");
  write(fd, left, strlen(left));
}

void	right_redirect_double(char *left, char *right)
{
  int	fd;

  if ((fd = open(right, O_WRONLY | O_CREAT | O_APPEND, 0666)) == -1)
    perror("Erreur : ");
  write(fd, left, strlen(left));
}

int	exec_cmd_lr(int fd, char **cmd, t_shell *shell)
{
  int	pipefd[2];
  char	*s;

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
      if (check_builtin(shell, cmd) == -2)
	if (my_exec_without_fork(shell, cmd) == -1)
	  exit(-1);
      close(pipefd[0]);
    }
  else
    wait(NULL);
  return (1);
}

int	start_left_redirect(char **cmd1, char **cmd2, t_shell *shell)
{
  int	fd;

  if (access(cmd2[0], F_OK) == -1)
    {
      fprintf(stderr, "42sh: Redirection: can't access %s\n", cmd2[0]);
      return (-1);
    }
  if (access(cmd2[0], R_OK) == -1)
    {
      fprintf(stderr, "42sh: Redirection: can't read redirection file. \
Check your rights.\n");
      return (-1);
    }
  if ((fd = open(cmd2[0], O_RDONLY)) == -1)
    return (-1);
  if (exec_cmd_lr(fd, cmd1, shell) == -1)
    return (-1);
  return (1);
}

int	do_under_doublel(int *pipefd, t_shell *shell, char **cmd1)
{
  close(pipefd[1]);
  if (fork() == 0)
    {
      if (dup2(pipefd[0], 0) == -1)
	return (-1);
      if (check_builtin(shell, cmd1) == -2)
	if (my_exec_without_fork(shell, cmd1) == -1)
	  exit(-1);
      close(pipefd[0]);
    }
  else
    wait(NULL);
  return (1);
}

int	start_double_left_redirect(char **cmd1, char **cmd2, t_shell *shell)
{
  char	*s;
  int	pipefd[2];

  if (pipe(pipefd) == -1)
    return (-1);
  write(1, "> ", 3);
  while ((s = get_next_line(0)) != NULL)
    {
      if (strcmp(s, cmd2[0]) == 0)
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
  return (do_under_doublel(pipefd, shell, cmd1));
}

void	do_lr(char **cmd1, char **cmd2, t_shell *shell, int **pipefd)
{
  start_left_redirect(cmd1, cmd2, shell);
  pipe(*pipefd);
  write((*pipefd)[1], "\n", 1);
}

void	do_dlr(char **cmd1, char **cmd2, t_shell *shell, int **pipefd)
{
  pipe(*pipefd);
  start_double_left_redirect(cmd1, cmd2, shell);
  write((*pipefd)[1], "\n", 1);
}

void	do_cmd1_cmd2(char **cmd1, t_shell *shell, int **pipefd)
{
  pipe(*pipefd);
  if (fork() == 0)
    {
      dup2((*pipefd)[1], 1);
      if (check_builtin(shell, cmd1) == -2)
	my_exec_without_fork(shell, cmd1);
      exit(-1);
    }
  wait(NULL);
}

char	*middle_op(int **pipefd, int *t)
{
  char	*tmp;

  tmp = malloc(4096 * sizeof(char));
  memset(tmp, 0, 4096);
  *t = read((*pipefd)[0], tmp, 4096);
  close((*pipefd)[1]);
  close((*pipefd)[0]);
  pipe(*pipefd);
  write((*pipefd)[1], tmp, *t);
  close((*pipefd)[1]);
  return (tmp);
}

void	do_11(int **pipefd2, int **pipefd, char **cmd2, t_shell *shell)
{
  int	t;
  char	tmp[4096];

  pipe(*pipefd2);
  if (fork() == 0)
    {
      dup2((*pipefd)[0], 0);
      dup2((*pipefd2)[1], 1);
      if (check_builtin(shell, cmd2) == -2)
	my_exec_without_fork(shell, cmd2);
      exit(-1);
    }
  wait(NULL);
  t = read((*pipefd2)[0], tmp, 4096);
  close((*pipefd2)[0]);
  close((*pipefd2)[1]);
  pipe(*pipefd);
  write((*pipefd)[1], tmp, t);
}

void	do_13(int **pipefd, char *tmp, char **cmd2)
{
  right_redirect(tmp, cmd2[0]);
  pipe(*pipefd);
  write((*pipefd)[1], "\n", 1);
}

void	do_14(char *tmp, char **cmd2, int **pipefd)
{
  right_redirect_double(tmp, cmd2[0]);
  pipe(*pipefd);
  write((*pipefd)[1], "\n", 1);
}

void	choose_exec(char **cmd1, int sep, char **cmd2,
		    int **pipefd, t_shell *shell)
{
  int	*pipefd2;
  char	*tmp;
  int	t;

  tmp = malloc(4096 * sizeof(char));
  pipefd2 = malloc(2 * sizeof(int));
  if (sep == 15)
    do_lr(cmd1, cmd2, shell, pipefd);
  else if (sep == 16)
    do_dlr(cmd1, cmd2, shell, pipefd);
  else
    {
      if (cmd1 != NULL && cmd2 != NULL)
	do_cmd1_cmd2(cmd1, shell, pipefd);
      tmp = middle_op(pipefd, &t);
      if (sep == 11)
	do_11(&pipefd2, pipefd, cmd2, shell);
      else if (sep == 13)
	do_13(pipefd, tmp, cmd2);
      else if (sep == 14)
	do_14(tmp, cmd2, pipefd);
      close((*pipefd)[1]);
    }
}

void	first_step(t_link *tmp, char ***cmd1, int *sep)
{
  if (tmp->type == 0)
    {
      *cmd1 = get_cmd(tmp);
      while (tmp && tmp->type == 0)
	tmp = tmp->next;
    }
  if (tmp && tmp->type != 0)
    {
      *sep = tmp->type;
      tmp = tmp->next;
    }
}

int	second_step(t_link *tmp, char ***cmd2, t_shell *shell, char ***cmd1)
{
  int	pid;

  if (tmp && tmp->type == 0)
    {
      *cmd2 = get_cmd(tmp);
      while (tmp && tmp->type == 0)
	tmp = tmp->next;
    }
  if (*cmd2 == NULL)
    {
      if (check_builtin(shell, *cmd1) != -2)
	return (1);
      if ((pid = fork()) == 0)
	{
	  my_exec_without_fork(shell, *cmd1);
	  exit(-1);
	}
      wait(NULL);
      return (1);
    }
  return (0);
}

void		check_type(t_link **tmp, char ***cmd1, int *sep)
{
  if ((*tmp)->type == 0)
    {
      *cmd1 = get_cmd(*tmp);
      while (*tmp && (*tmp)->type == 0)
	*tmp = (*tmp)->next;
    }
  if (*tmp && (*tmp)->type != 0)
    {
      *sep = (*tmp)->type;
      *tmp = (*tmp)->next;
    }
}

void		check_type_2(t_link **tmp, char ***cmd2, int sep, char **tmps)
{
  if ((*tmp) && (*tmp)->type == 0)
    {
      *cmd2 = get_cmd((*tmp));
      while ((*tmp) && (*tmp)->type == 0)
	(*tmp) = (*tmp)->next;
    }
  else if (sep == 11)
    {
      write(1, "> ", 3);
      memset(*tmps, 0, 4096);
      read(0, *tmps, 4096);
      *cmd2 = my_strd_to_wordtab(*tmps, " ");
    }
}

int		second_cmd_null(t_shell **shell, char ***cmd1, char **cmd2)
{
  pid_t		pid;

  if (cmd2 == NULL)
    {
      if (check_builtin(*shell, *cmd1) != -2)
	return (1);
      if ((pid = fork()) == 0)
	my_exec_without_fork(*shell, *cmd1);
      wait(NULL);
      return (1);
    }
  return (0);
}

void		closepipe(char **tmps, int **pipefd)
{
  memset(*tmps, 0, 4096);
  read((*pipefd)[0], *tmps, 4096);
  close((*pipefd)[0]);
  close((*pipefd)[1]);
  write(1, *tmps, 4096);
}

int		my_parser(t_link *list, t_shell *shell)
{
  t_link	*tmp;
  int		sep;
  int		*pipefd;
  char		**cmd1;
  char		**cmd2;
  char		*tmps;

  tmps = my_xmalloc(4096);
  sep = 0;
  tmp = list;
  pipefd = malloc(2 * sizeof(int));
  if (tmp->next != NULL && tmp->type == -1)
    tmp = tmp->next;
  while (tmp != NULL)
    {
      cmd1 = NULL;
      cmd2 = NULL;
      check_type(&tmp, &cmd1, &sep);
      check_type_2(&tmp, &cmd2, sep, &tmps);
      if (second_cmd_null(&shell, &cmd1, cmd2) == 1)
	return (1);
      choose_exec(cmd1, sep, cmd2, &pipefd, shell);
    }
  closepipe(&tmps, &pipefd);
  return (0);
}

int		my_parser_check(t_link *list, char *cmd, t_shell *shell)
{
  t_tree	*tree;
  t_link	*tmp;

  (void)cmd;
  tmp = list;
  if ((tree = init_access()) == NULL)
    return (-1);
  while (tmp != NULL)
    {
      if (tmp != NULL && (int)tmp->type != -1)
	if (check_token_succession(tmp, tree) == -1)
	  remove_unvalid_links(&tmp);
      if (tmp != NULL)
	tmp = tmp->next;
    }
  free_tree(tree);
  tmp = list;
  remove_old_links(&tmp, &list);
  my_parser(list, shell);
  return (0);
}

int		my_lexer(char *cmd, t_shell *shell)
{
  int		i;
  int		len;
  t_link	*list;

  if (cmd == NULL)
    {
      my_puterr("Lexer error : param is equal to NULL\n");
      return (-1);
    }
  if ((list = init_list(NULL, -1)) == NULL)
    return (-1);
  i = 0;
  len = strlen(cmd);
  while (i < len)
    {
      if (cmd[i] == ' ' || cmd[i] == '\n' || cmd[i] == '\t')
	i++;
      else
	if (check_token(cmd, &i, list) == -1)
	  return (-1);
    }
  if (my_parser_check(list, cmd, shell) == -1)
    return (-1);
  return (0);
}

