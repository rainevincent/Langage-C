/*
** parser.c for  in /home/mediav_j/mabm/42sh/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May  7 17:42:35 2014 Jeremy Mediavilla
** Last update Wed May 28 14:42:08 2014 Jeremy Mediavilla
*/

#include "parser.h"

/* int		is_sorted(int **mtab, int size) */
/* { */
/*   int		i; */

/*   i = 0; */
/*   while (i < (size - 1)) */
/*     { */
/*       if (mtab[i][1] < mtab[i + 1][1]) */
/* 	return (-1); */
/*       i++; */
/*     } */
/*   return (1); */
/* } */

/* void		my_sort_tab(int ***mtab, int size) */
/* { */
/*   int		i; */
/*   int		tmp; */
/*   int		tmp2; */

/*   i = 0; */
/*   while (i < (size - 1)) */
/*     { */
/*       if ((*mtab)[i][1] < (*mtab)[i + 1][1]) */
/* 	{ */
/* 	  tmp = (*mtab)[i][0]; */
/* 	  tmp2 = (*mtab)[i][1]; */
/* 	  (*mtab)[i][0] = (*mtab)[i + 1][0]; */
/* 	  (*mtab)[i][1] = (*mtab)[i + 1][1]; */
/* 	  (*mtab)[i + 1][0] = tmp; */
/* 	  (*mtab)[i + 1][1] = tmp2; */
/* 	  i = 0; */
/* 	} */
/*       i++; */
/*     } */
/*   if (is_sorted((*mtab), size) == -1) */
/*     my_sort_tab((*mtab), size); */
/* } */

int		**init_tab_priority()
{
  int		**mtab;
  int		i;

  i = 0;
  mtab = malloc(7 * sizeof(int *));
  while (i < 7)
    {
      mtab[i] = malloc(2 * sizeof(int));
      i++;
    }
  mtab[0][0] = PIPE;
  mtab[0][1] = 2;
  mtab[1][0] = OR;
  mtab[1][1] = 1;
  mtab[2][0] = DOUBLE_AND;
  mtab[2][1] = 1;
  mtab[3][0] = R_CHEV;
  mtab[3][1] = 0;
  mtab[4][0] = RR_CHEV;
  mtab[4][1] = 0;
  mtab[5][0] = L_CHEV;
  mtab[5][1] = 0;
  mtab[6][0] = LL_CHEV;
  mtab[6][1] = 0;
  return (mtab);
}

int		is_special_sep(int sep, int **mtab)
{
  int		i;

  i = 0;
  while (i < 7)
    {
      if (sep == mtab[i][0])
	return (mtab[i][1]);
      i++;
    }
  return (-1);
}

t_link		*get_pos_link(t_link *list, int pos)
{
  t_link	*tmp;
  int		i;

  i = -1;
  tmp = list;
  while (tmp != NULL)
    {
      if (i == pos)
	return (tmp);
      i++;
      tmp = tmp->next;
    }
  return (NULL);
}

void	exec_cmd_from_parser(char *left, char *right, int type)
{
  /* if (type == 11) */
  /*   do_pipestart(listepipe, nb_cmd); */
  printf("On exécute %s %d %s\n", left, type, right);
}

int		my_parser(t_link *list)
{
  t_link	*tmp;
  int		**my_tab;
  int		priority;
  int		i;
  int		j;
  int		**priority_tab;

  i = 0;
  j = 0;
  tmp = list;
  my_tab = init_tab_priority();
  if (tmp->next != NULL && tmp->type == -1)
    tmp = tmp->next;
  while (tmp != NULL)
    {
      if ((priority = is_special_sep(tmp->type, my_tab)) != -1)
	{
	  if (j == 0)
	    {
	      priority_tab = malloc(1 * sizeof(int *));
	      priority_tab[0] = malloc(3 * sizeof(int));
	      printf("First pass\n");
	    }
	  else
	    {
	      priority_tab = realloc(priority_tab, (j + 1) * sizeof(int *));
	      priority_tab[j] = malloc(3 * sizeof(int));
	    }
	  priority_tab[j][0] = tmp->type;
	  priority_tab[j][1] = priority;
	  priority_tab[j][2] = i;
	  j++;
	}
      tmp = tmp->next;
      i++;
    }
  i = 0;
  printf("J = %d\n", j);
  int	flag = -1;
  if (j == 1)
    exec_cmd_from_parser(get_pos_link(list, (priority_tab[0][2] - 1))->data,
			 get_pos_link(list, (priority_tab[0][2] + 1))->data,
			 priority_tab[0][0]);
  else
    {
      while (i < j)
	{
	  printf("==> type = [%i] - Priorite = [%i] - Position = %d\n",
		 priority_tab[i][0], priority_tab[i][1], priority_tab[i][2]);

	  /* printf("On execute : %s %i %s\n", */
	  /* 	     get_pos_link(list, (priority_tab[i][0] -1))->data, */
	  /* 	     get_pos_link(list, priority_tab[i][0])->type, */
	  /* 	     get_pos_link(list, (priority_tab[i][0] -1))->data); */
	  i++;
	}
    }
  return (0);
}

int		my_parser_check(t_link *list, char *cmd)
{
  t_tree	*tree;
  t_link	*tmp;

  tmp = list;
  printf("\n%s\n\n", cmd);
  if ((tree = init_access()) == NULL)
    return (-1);
  while (tmp != NULL)
    {
      if (tmp != NULL && (int)tmp->type != -1)
	if (check_token_succession(tmp, tree) == -1)
	  remove_unvalid_links(&tmp);
      if (tmp != NULL)
	tmp = tmp->next;
    }
  free_tree(tree);
  tmp = list;
  remove_old_links(&tmp, &list);
  aff_my_list(list);
  my_parser(list);
  return (0);
}

int		my_lexer(char *cmd)
{
  int		i;
  int		len;
  t_link	*list;

  if (cmd == NULL)
    {
      my_puterr("Lexer error : param is equal to NULL\n");
      return (-1);
    }
  if ((list = init_list(NULL, -1)) == NULL)
    return (-1);
  i = 0;
  len = strlen(cmd);
  while (i < len)
    {
      if (cmd[i] == ' ' || cmd[i] == '\n' || cmd[i] == '\t')
	i++;
      else
	if (check_token(cmd, &i, list) == -1)
	  return (-1);
    }
  if (my_parser_check(list, cmd) == -1)
    return (-1);
  return (0);
}
