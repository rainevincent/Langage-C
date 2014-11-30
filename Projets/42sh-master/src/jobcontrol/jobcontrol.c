/*
** jobcontrol.c for jobcontrol in /home/merran_g/work/c_elem/42sh/src/jobcontrol
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue May 27 15:35:36 2014 Geoffrey Merran
** Last update Wed May 28 14:41:33 2014 Jeremy Mediavilla
*/

#define _BSD_SOURCE
#include "jobcontrol.h"

int		builtin_jobs(t_shell *shell, char **cmd)
{
  t_blist      	*tmp;

  (void) cmd;
  tmp = shell->bg->list;
  while (tmp)
    {
      printf("[%d] %s\n", tmp->pid, tmp->cmd);
      tmp = tmp->next;
    }
  return (0);
}

int		restaure_jobs(t_bg *bg, t_blist *job)
{
  t_blist	*tmp;
  int		pid;

  if (job == bg->list)
    bg->list = job->next;
  else
    {
      tmp = bg->list;
      while (tmp->next != job)
	tmp = tmp->next;
      tmp->next = job->next;
    }
  pid = job->pid;
  free(job->cmd);
  free(job);
  bg->nb--;
  if (kill(pid, SIGCONT) == -1)
    {
      my_puterr("42sh: jobs: can't restaure a job. kill error\n");
      return (-1);
    }
  return (0);
}

int		builtin_fg(t_shell *shell, char **cmd)
{
  int		pid;
  t_blist	*tmp;

  pid = 0;
  if (shell->bg->list == NULL)
    return (my_error("42sh: jobs: no jobs.\n"));
  if (my_strlen_tabs(cmd) == 2)
    pid = my_getnbr(cmd[1]);
  if (pid == 0)
    return (restaure_jobs(shell->bg, shell->bg->list));
  else
    {
      tmp = shell->bg->list;
      while (tmp)
	{
	  if (pid == tmp->pid)
	    return (restaure_jobs(shell->bg, tmp));
	  tmp = tmp->next;
	}
      my_puterr("42sh: jobs: job pid don't exist\n");
    }
  return (-1);
}

int		add_job(int pid, char **cmd, t_bg **bg)
{
  t_blist	*new;

  if ((new = my_xmalloc(sizeof(*new))) == NULL)
    return (-1);
  new->pid = pid;
  new->cmd = strdup(cmd[0]);
  new->next = (*bg)->list;
  (*bg)->list = new;
  (*bg)->nb = (*bg)->nb + 1;
  return (0);
}

int	init_jobcontrol(t_shell **shell)
{
  if (((*shell)->bg = my_xmalloc(sizeof(*(*shell)->bg))) == NULL)
    return (-1);
  (*shell)->bg->nb = 0;
  (*shell)->bg->list = NULL;
  return (0);
}
