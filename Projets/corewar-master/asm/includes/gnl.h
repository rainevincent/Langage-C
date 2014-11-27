/*
** gnl.h for  in /home/mediav_j/corewar/assembleur
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Thu Mar 27 17:04:24 2014 Jeremy Mediavilla
** Last update Sun Apr 13 13:36:06 2014 Joris Bertomeu
*/

#ifndef        __GNL_H__
# define    __GNL_H__
# include <string.h>
# include "assembleur.h"
# define        BUF_SIZE 5000
# define        BUF_READ 5000

typedef struct    s_var
{
  char       *buffer;
  int        i;
  int        pos;
  int        nb_read;
}        t_var;

char        *get_next_line(const int fd, t_system *sys);

#endif        /*__GNL_H__*/
