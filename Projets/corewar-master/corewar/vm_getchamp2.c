/*
** vm_getchamp2.c for vm_getchamp2 in /home/merran_g/work/c_elem/corewar/vm
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Apr  2 10:48:31 2014 Geoffrey Merran
** Last update Tue Apr  8 23:41:13 2014 Geoffrey Merran
*/

#include "vm_getchamp.h"

int	get_magic(unsigned char *buffer)
{
  int	i;
  int	magic;

  i = 0;
  magic = 0;
  while (i < 4)
    magic += buffer[i++];
  if (magic == MAGIC_NUMBER)
    {
      my_printf("Magic number ok!\n");
      return (magic);
    }
  my_error("Champion error : Wrong magic number. USE OUR ASM FAGG !\n");
  return (-1);
}

int		get_size(unsigned char *buffer)
{
  int		i;
  t_conv	conv;

  i = 4;
  while (i < 8)
    {
      conv.octet[7 - i] = buffer[i];
      i++;
    }
  my_printf("Size ok !\n");
  return (conv.integer);
}

void	get_name(unsigned char *buffer, char prog_name[])
{
  int	i;

  i = 8;
  while (i < (PROG_NAME_LENGTH + 8))
    {
      prog_name[i - 8] = buffer[i];
      i++;
    }
  prog_name[PROG_NAME_LENGTH] = '\0';
  if (prog_name[0] == '\0')
    my_error("Champion error : No name found. USE OUR ASM FAGG !\n");
  my_printf("Name ok !\n");
}

void	get_comment(unsigned char *buffer, char comment[])
{
  int	i;
  int	pos;

  pos = 8 + PROG_NAME_LENGTH;
  i = pos;
  while (i < (pos + COMMENT_LENGTH))
    {
      comment[i - pos] = buffer[i];
      i++;
    }
  comment[COMMENT_LENGTH] = '\0';
  my_printf("Comment ok !\n");
}

void	write_champ_in(unsigned char *buffer, t_champ *champ,
		       t_arena *arena, int size)
{
  int	i;
  int	address;

  address = champ->address;
  i = 8 + PROG_NAME_LENGTH + COMMENT_LENGTH;
  while (i < size)
    {
      arena->color[address] = champ->id;
      arena->arena[address++] = buffer[i++];
    }
}
