/*
** my_printf.h for printf in /home/merran_g/work/c_elem/PSU_2018_my_printf
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Nov  6 00:17:51 2013 Geoffrey Merran
** Last update Thu May 22 13:39:06 2014 Geoffrey Merran
*/

#ifndef MY_PRINTF_
# define MY_PRINTF_
# define NB_FLAGS 14
# define FLAG_N 11
# include <stdarg.h>

struct		s_count
{
  int		nb_char;
  int		i;
};

typedef struct s_count t_count;
typedef int (*flag)(va_list);

int		my_printf(const char *format, ...);
void		init_my_printf(t_count *count, flag **flag_ptr);
void		read_fg(const char *format, t_count *count, flag *flag_ptr, va_list ap);
flag		*stock_flags();
int		flag_s(va_list ap);
int		flag_d(va_list ap);
int		flag_c(va_list ap);
int		flag_o(va_list ap);
int		flag_x(va_list ap);
int		flag_X(va_list ap);
int		flag_b(va_list ap);
int		flag_u(va_list ap);
int		flag_p(va_list ap);
int		flag_S(va_list ap);

/*
** %t imprime un char ** (utile pour debug)
*/

int		flag_t(va_list ap);
int		flag_n(va_list ap, int nb_char);
int		flag_percent();

#endif /* MY_PRINTF_ */
