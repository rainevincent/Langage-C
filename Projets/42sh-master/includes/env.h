/*
** env.h for  in /home/nicolas/Workspace/42sh/includes
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Mon Apr 28 13:49:50 2014 Nicolas Ades
** Last update Mon Apr 28 15:22:50 2014 Nicolas Ades
*/

#ifndef ENV_H_
# define ENV_H_
# include "main.h"

typedef struct	s_env
{
  char		**env;
  char		**path;
}		t_env;

#endif /* ENV_H_ */
