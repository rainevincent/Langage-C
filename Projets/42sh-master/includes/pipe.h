typedef struct		s_pipe
{
  int			i;
  char			buff[4096];
  int			status;
  int			pipefd[2];
  int			pipefd2[2];
  char			t[4096];
  int			pid;
  int			tmp;
  char			***cmds;
}			t_pipe;

int		do_pipe(t_pipe *);
int		my_exec_without_fork(t_shell *, char **);
