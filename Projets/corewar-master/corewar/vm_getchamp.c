/*
** vm_getchamp.c for vm_getchamp in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Mar 26 11:51:37 2014 Geoffrey Merran
** Last update Tue Apr  8 23:36:19 2014 Geoffrey Merran
*/

#include "vm_getchamp.h"

void		fill_champ(t_champ *champ, int fd, t_arena *arena)
{
  unsigned char	*buffer;
  int		ret;

  buffer = my_xmalloc(BUFFER_SIZE * sizeof(char));
  my_memset((char *) buffer, 0, BUFFER_SIZE);
  if ((ret = xread(fd, buffer, (BUFFER_SIZE - 1))) > 0)
    {
      champ->header.magic = get_magic(buffer);
      champ->header.prog_size = get_size(buffer);
      get_name(buffer, champ->header.prog_name);
      get_comment(buffer, champ->header.comment);
      write_champ_in(buffer, champ, arena, ret);
      free(buffer);
      if ((ret = xread(fd, NULL, 0)) > 0)
	my_error("Champ error : Program too big\n");
      else
	my_printf("Done !\n");
    }
}

void		load_champs(t_champ **champs, t_arena *arena)
{
  t_champ	*tmp;
  int		fd;

  tmp = *champs;
  while (tmp != NULL)
    {
      my_printf("\nLoading champion n°%d\n\n", tmp->id);
      fd = xopen(tmp->path, O_RDONLY, 0);
      fill_champ(tmp, fd, arena);
      close(fd);
      tmp = tmp->next;
    }
}

void		create_champ(t_champ **champ)
{
  t_champ	*tmp;

  tmp = my_xmalloc(sizeof(*tmp));
  tmp->id = 0;
  tmp->address = -1;
  tmp->path = NULL;
  tmp->live = -1;
  tmp->next = *champ;
  tmp->prev = NULL;
  if (*champ != NULL)
    (*champ)->prev = tmp;
  *champ = tmp;
}

int		get_nb_champs(t_champ *champs)
{
  t_champ	*tmp;
  int		i;

  i = 0;
  tmp = champs;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i++;
    }
  return (i);
}

void	add_champ(t_champ **champ)
{
  if ((*champ) == NULL || (*champ)->live == 0)
    create_champ(champ);
}
