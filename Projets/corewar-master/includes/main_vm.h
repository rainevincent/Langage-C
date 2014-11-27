/*
** main_vm.h for main_vm.h in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Mar 25 17:19:00 2014 Geoffrey Merran
** Last update Sat Apr 12 18:05:22 2014 Geoffrey Merran
*/

#ifndef MAIN_VM_
# define MAIN_VM_
# define VM_USAGE "Usage : ./corewar [-dump nbr_cycle]"
# define VM_USAGE2 " [[-n prog_number] [-a load_address ] prog_name]\n"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "my.h"
# include "my_printf.h"
# include "my_free.h"
# include "vm_parser.h"
# include "vm_corewar.h"
# include "vm_arena.h"
# include "vm_init.h"

#endif /* MAIN_VM_ */
