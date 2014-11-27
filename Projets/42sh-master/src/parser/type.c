/*
** type.c for  in /home/mediav_j/mabm/42sh/src/parser
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Fri May 23 14:22:12 2014 Jeremy Mediavilla
** Last update Sun May 25 11:30:24 2014 Jeremy Mediavilla
*/

#include "parser.h"

void		aff_type_error(int type1, int type2)
{
  char		*type_names[19];

  type_names[WORD] = "a word";
  type_names[END] = "';'";
  type_names[DOLL] = "'$'";
  type_names[EXCL] = "'!'";
  type_names[INTERR] = "'?'";
  type_names[STAR] = "'*'";
  type_names[AT] = "'@'";
  type_names[O_PAR] = "'('";
  type_names[C_PAR] = "')'";
  type_names[O_HOOK] = "'['";
  type_names[C_HOOK] = "']'";
  type_names[PIPE] = "'|'";
  type_names[OR] = "'||'";
  type_names[R_CHEV] = "'>'";
  type_names[RR_CHEV] = "'>>'";
  type_names[L_CHEV] = "'<'";
  type_names[LL_CHEV] = "'<<'";
  type_names[AND] = "'&'";
  type_names[DOUBLE_AND] = "'&&'";
  type_names[19] = "the end of a command";
  fprintf(stderr, "\nError in command !\n");
  fprintf(stderr, "You can't have %s after %s\nCommand ignored\n\n"
	  , type_names[type2], type_names[type1]);
}
