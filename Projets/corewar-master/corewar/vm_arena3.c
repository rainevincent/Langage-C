/*
** opt_dump.c for  in /home/nicolas/Workspace/Corewar/corewar
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sun Apr 13 07:24:08 2014 Nicolas Ades
** Last update Mon Apr 14 16:31:51 2014 Nicolas Ades
*/

#include "vm_arena.h"

void		dump_arena(unsigned char *arena, int cycle_max)
{
  int		i;

  i = 0;
  my_printf("\n== DUMPING MEMORY ==\n");
  while (i < MEM_SIZE)
    {
      if (arena[i] < 16)
	my_putchar('0');
      my_printf("%X", arena[i]);
      if (((i + 1) % 32) == 0)
	my_putchar('\n');
      i++;
    }
  my_printf("\nMemory was dumped at %d cycle\n", cycle_max);
}
