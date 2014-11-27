/*
** my_exit.c for  in /home/nicolas/Workspace/Unix/42sh/src/builtin
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Mon May 26 07:11:03 2014 Nicolas Ades
** Last update Wed May 28 06:40:35 2014 Geoffrey Merran
*/

#include "core.h"

int		my_exit(t_shell *shell, char **cmd)
{
  int		val;

  if (my_strlen_tabs(cmd) > 1)
    val = my_getnbr(cmd[1]);
  shell->end = 1;
  shell->exit_val = val;
  return (val);
}
