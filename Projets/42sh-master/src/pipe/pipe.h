/*
** pipe.h for  in /home/mediav_j/mabm/42sh/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May 28 14:37:30 2014 Jeremy Mediavilla
** Last update Wed May 28 14:37:31 2014 Jeremy Mediavilla
*/

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
  int			total;
}			t_pipe;
