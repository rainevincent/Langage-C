/*
** my_putchar.c for my_putchar in /home/merran_g/rendu/Piscine-C-lib/my
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Mon Oct 21 11:10:28 2013 Geoffrey Merran
** Last update Fri May 23 07:58:19 2014 Nicolas Ades
*/

#include <unistd.h>
#include <stdlib.h>

void	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return;
}
