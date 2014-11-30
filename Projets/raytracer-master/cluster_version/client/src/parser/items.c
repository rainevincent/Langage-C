/*
** items.c for items in /home/merran_g/work/c_igraph/rtv1
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun Mar 16 01:54:50 2014 Geoffrey Merran
** Last update Sun Jun  8 15:57:47 2014 Jeremy Mediavilla
*/

#include "parser.h"

void		add_item(t_node **list, t_item new)
{
  t_node	*tmp;

  tmp = my_xmalloc(sizeof(*tmp));
  tmp->item.pos = new.pos;
  tmp->item.angle = new.angle;
  tmp->item.qua = new.qua;
  tmp->item.type = new.type;
  tmp->item.rayon = new.rayon;
  tmp->item.color = new.color;
  tmp->item.brillance = new.brillance;
  tmp->item.transparence = new.transparence;
  tmp->item.reflexion = new.reflexion;
  tmp->item.effect = new.effect;
  tmp->next = *list;
  *list = tmp;
}

int		get_type_effect_val(char *balise, char **conf, int i)
{
  int		len;
  int		val;

  len = strlen(balise);
  val = 0;
  while (conf[i] && strncmp(conf[i], balise, len) != 0)
    i++;
  if (conf[i])
    {
      val = (int)get_effects_val2(balise, conf, i);
      if (val < 0 || val > 2)
	{
	  fprintf(stderr, "Error on line %i : effect value \
must be between 0 and 2\n", i);
	  exit(0);
	}
    }
  return (val);
}
