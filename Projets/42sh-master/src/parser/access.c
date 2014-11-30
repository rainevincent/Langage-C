/*
** test.c for  in /home/mediav_j/mabm/42sh/src/parser
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May 21 15:56:54 2014 Jeremy Mediavilla
** Last update Sun May 25 18:47:13 2014 Jeremy Mediavilla
*/

#include "parser.h"

void		print_access(int *access)
{
  int		i;

  i = 0;
  while (access[i] != -1)
    {
      printf("%i ", access[i]);
      i++;
    }
  printf("\n");
}

int		*fill_access(char **tmp, int size)
{
  int		*final;
  int		i;

  i = 0;
  if ((final = my_xmalloc(size * sizeof(final))) == NULL)
    return (NULL);
  size--;
  while (i < size)
    {
      final[i] = my_getnbr(tmp[i]);
      i++;
    }
  final[i] = -1;
  return (final);
}

int		*get_access(char *cmd)
{
  char		**tmp;
  int		size;
  int		*final;

  size = 0;
  tmp = my_strd_to_wordtab(cmd, "-");
  while (tmp[size])
    size++;
  if ((final = fill_access(tmp, (size + 1))) == NULL)
    {
      free_tab(tmp);
      return (NULL);
    }
  free_tab(tmp);
  return (final);
}

void		print_tree(t_tree *tree)
{
  printf("\n\nTREE :\n\n");
  while (tree->prev != NULL)
    tree = tree->prev;
  while (tree != NULL)
    {
      if (tree->curr_type != -1)
	{
	  printf("Type : %i\naccess : ", tree->curr_type);
	  print_access(tree->access);
	}
      tree = tree->next;
    }
}

t_tree		*init_access()
{
  t_tree	*tree;

  if ((tree = init_tree(-1, NULL)) == NULL)
    return (NULL);
  add_to_tree_end(tree, WORD, get_access(WORD_ACCESS));
  add_to_tree_end(tree, END, get_access(END_ACCESS));
  add_to_tree_end(tree, DOLL, get_access(DOLL_ACCESS));
  add_to_tree_end(tree, EXCL, get_access(EXCL_ACCESS));
  add_to_tree_end(tree, INTERR, get_access(INTERR_ACCESS));
  add_to_tree_end(tree, STAR, get_access(STAR_ACCESS));
  add_to_tree_end(tree, AT, get_access(AT_ACCESS));
  add_to_tree_end(tree, O_PAR, get_access(O_PAR_ACCESS));
  add_to_tree_end(tree, C_PAR, get_access(C_PAR_ACCESS));
  add_to_tree_end(tree, O_HOOK, get_access(O_HOOK_ACCESS));
  add_to_tree_end(tree, C_HOOK, get_access(C_HOOK_ACCESS));
  add_to_tree_end(tree, PIPE, get_access(PIPE_ACCESS));
  add_to_tree_end(tree, OR, get_access(OR_ACCESS));
  add_to_tree_end(tree, R_CHEV, get_access(R_CHEV_ACCESS));
  add_to_tree_end(tree, RR_CHEV, get_access(RR_CHEV_ACCESS));
  add_to_tree_end(tree, L_CHEV, get_access(L_CHEV_ACCESS));
  add_to_tree_end(tree, LL_CHEV, get_access(LL_CHEV_ACCESS));
  add_to_tree_end(tree, AND, get_access(AND_ACCESS));
  add_to_tree_end(tree, DOUBLE_AND, get_access(DOUBLE_AND_ACCESS));
  return (tree);
}
