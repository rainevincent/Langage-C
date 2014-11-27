/*
** vm_proc.c for vm_proc in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Mon Apr  7 13:26:57 2014 Geoffrey Merran
** Last update Sat Apr 12 17:47:47 2014 Geoffrey Merran
*/

#include "vm_proc.h"

void		add_proc(t_proc **proc, t_champ *champ)
{
  t_proc	*tmp;
  int		i;

  tmp = my_xmalloc(sizeof(*tmp));
  tmp->id = champ->id;
  tmp->pc = champ->address;
  tmp->carry = 0;
  tmp->alive = 0;
  tmp->cycle_dodo = 0;
  i = 0;
  while (i < REG_NUMBER)
    tmp->reg[i++] = 0;
  tmp->reg[0] = tmp->id;
  tmp->next = *proc;
  tmp->prev = NULL;
  if (*proc != NULL)
    (*proc)->prev = tmp;
  *proc = tmp;
}

t_proc		*del_proc(t_proc *proc, t_proc **start)
{
  t_proc	*tmp;
  t_proc	*next;
  t_proc	*prev;

  next = proc->next;
  prev = proc->prev;
  if (next != NULL || prev != NULL)
    {
      if (next != NULL)
	next->prev = prev;
      if (prev != NULL)
	prev->next = next;
    }
  tmp = proc;
  if (tmp == *start)
    *start = next;
  proc = next;
  free(tmp);
  return (proc);
}

int		get_nb_proc(t_proc *proc)
{
  t_proc	*tmp;
  int		i;

  i = 0;
  tmp = proc;
  while (tmp)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

void		init_proc(t_proc **proc, t_champ *champ)
{
  t_champ	*tmp;

  *proc = NULL;
  tmp = champ;
  while (tmp)
    {
      add_proc(proc, tmp);
      tmp = tmp->next;
    }
}

void		add_proc_vm(t_proc *proc, int addr)
{
  t_proc	*tmp;
  int		i;

  tmp = my_xmalloc(sizeof(*tmp));
  tmp->id = proc->id;
  tmp->pc = addr;
  tmp->carry = proc->carry;
  tmp->alive = 0;
  tmp->cycle_dodo = op_tab[11].nbr_cycles;
  i = -1;
  while (++i < REG_NUMBER)
    tmp->reg[i] = proc->reg[i];
  tmp->next = proc->next;
  if (proc->next != NULL)
    proc->next->prev = tmp;
  tmp->prev = proc;
  proc->next = tmp;
}
