/*
** parser.h for parser in /home/merran_g/work/c_elem/42sh
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed May 28 02:35:28 2014 Geoffrey Merran
** Last update Wed May 28 06:44:29 2014 Geoffrey Merran
*/

#ifndef PARSER_H_
# define PARSER_H_

# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "main.h"
# include "my.h"
# include "mysh.h"
# include "pipe.h"
# include "core.h"

# define ALPHA_NUM "abcdefghijklmnopqrstuvwxyz\
ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_\\/.,+*="
# define WORD_ACCESS "0-1-2-4-5-6-7-8-9-10-11-12-13-14-15-16-17-18-19"
# define END_ACCESS "0-2-3-4-5-7-13-14-15-16-19"
# define DOLL_ACCESS "0-4-5-6-7"
# define EXCL_ACCESS "0-1-2-3-5-13-14"
# define INTERR_ACCESS "0"
# define STAR_ACCESS "0"
# define AT_ACCESS "0"
# define O_PAR_ACCESS "0-2-3-4-5-7-8-9-15-16"
# define C_PAR_ACCESS "0-1-7-8-9-10-11-12-13-14-15-16-17-18-19"
# define O_HOOK_ACCESS "0-2-3-4-5-7-8-9-15-16"
# define C_HOOK_ACCESS "0-1-7-8-9-10-11-12-13-14-15-16-17-18-19"
# define PIPE_ACCESS "0-2-3-4-5-7-9-13-14-15-16-19"
# define OR_ACCESS "0-2-3-4-5-7-9-11-13-14-15-16"
# define R_CHEV_ACCESS "0-2-3-4-5"
# define RR_CHEV_ACCESS "0-2-3-4-5"
# define L_CHEV_ACCESS "0-2-3-4-5"
# define LL_CHEV_ACCESS "0-2-3-4-5"
# define AND_ACCESS "19-1"
# define DOUBLE_AND_ACCESS "0-2-3-4-5-7-9-11-13-14-15-16"

typedef enum	e_type
  {
    WORD,
    END,
    DOLL,
    EXCL,
    INTERR,
    STAR,
    AT,
    O_PAR,
    C_PAR,
    O_HOOK,
    C_HOOK,
    PIPE,
    OR,
    R_CHEV,
    RR_CHEV,
    L_CHEV,
    LL_CHEV,
    AND,
    DOUBLE_AND
  }		t_type;

typedef struct		s_tree
{
  int			curr_type;
  int			*access;
  struct s_tree		*next;
  struct s_tree		*prev;
}			t_tree;

typedef struct		s_special
{
  char			open;
  char			close;
  int			o_type;
  int			c_type;
}			t_special;

typedef struct		s_link
{
  char			*data;
  int			type;
  struct s_link		*next;
  struct s_link		*prev;
}			t_link;

/* fonctions dans parser.c */
int		my_parser(t_link *, t_shell *);
int		my_parser_check(t_link *, char *, t_shell *);
int		my_lexer(char *, t_shell *);

/* fonctions dans list2.c */
t_link		*init_list(char *, t_type);
void		add_link_after(t_link *, char *, t_type);
void		add_link_before(t_link *, char *, t_type);
void		remove_link(t_link *);
void		link_to_end(t_link *, char *, t_type);

/* fonctions dans tree.c */
t_tree		*init_tree(int, int *);
void		add_tree_after(t_tree *, int, int *);
void		remove_tree(t_tree *);
void		add_to_tree_end(t_tree *, int, int *);

/* fonctions dans access.c */
int		*fill_access(char **, int);
int		*get_access(char *);
void		print_access(int *);
void		print_tree(t_tree *);
t_tree		*init_access();

/* fonctions dans type.c */
void		aff_type_error(int, int);

/* fonctions dans remove.c */
void		remove_useless_links(t_link *);
void		remove_link_custom(t_link **, t_link **);
void		remove_unvalid_links(t_link **);
void		remove_old_links(t_link **, t_link **);

/* fonctions dans token.c */
int		check_word_token(t_link *, char *, int *);
int		check_spec_token(char *, int *, t_link *);
void		check_token2(t_link *, int *, char *, int *);
int		check_token(char *, int *, t_link *);
int		check_double_quotes(char *, int *, t_link *, char);

/* fonctions dans token2.c */
int		check_token_succession(t_link *, t_tree *);
int		aff_quote_err(t_link *, char *);

/* fonctions dans parser_tools.c */
void		aff_my_list(t_link *);
int		is_valid_char(char, char *);
int		is_double_char(char *, int *);
int		check_is_char_s(char *, int *, char, char);
int		is_equal_nbr_cahr(char *, int *, t_special *);

/* fonctions dans parser_tools2.c */
char		*get_invalid_cmd_final(int, int *, char *, int);
char		*get_invalid_cmd(char *, int, int *, char);
int		is_valid_access(t_type, int *);
int		is_valid_end_access(t_tree *);

/* fonctions dans free.c */
void		free_tree(t_tree *);
void		free_list(t_link *);
void		free_tab(char **);

/* fonctions dans get_dollar.c */
void		get_dollar_bitch(t_link **, t_list *);

/*
** Cmd tools
*/

int		wait_father(pid_t pid);
char		**get_cmd(t_link *start);

#endif /* PARSER_H_ */
