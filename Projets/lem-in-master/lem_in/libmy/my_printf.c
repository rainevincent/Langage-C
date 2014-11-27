/*
** main.c for  in /home/merran_g/work/c_piscine/mkdir
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Fri Oct  4 09:11:03 2013 Geoffrey Merran
** Last update Fri Dec  6 14:18:53 2013 Geoffrey Merran
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

void		read_fg(const char *format, t_count *count,
			flag *flag_ptr, va_list ap)
{
  char		*list_flags;
  int		k;

  list_flags = "sdcioxXbupSnt%";
  k = 0;
  while (format[count->i] != list_flags[k] && k < NB_FLAGS)
    k++;
  if (k == FLAG_N)
    flag_n(ap, count->nb_char);
  else if (k < NB_FLAGS)
    count->nb_char = count->nb_char + flag_ptr[k](ap);
  else
    {
      my_putchar('%');
      my_putchar(format[count->i]);
    }
}

flag		*stock_flags()
{
  flag		*flag_ptr;

  flag_ptr = my_xmalloc((NB_FLAGS + 1) * sizeof(void *));
  flag_ptr[0] = flag_s;
  flag_ptr[1] = flag_d;
  flag_ptr[2] = flag_c;
  flag_ptr[3] = flag_d;
  flag_ptr[4] = flag_o;
  flag_ptr[5] = flag_x;
  flag_ptr[6] = flag_X;
  flag_ptr[7] = flag_b;
  flag_ptr[8] = flag_u;
  flag_ptr[9] = flag_p;
  flag_ptr[10] = flag_S;
  flag_ptr[12] = flag_t;
  flag_ptr[13] = flag_percent;
  flag_ptr[14] = NULL;
  return (flag_ptr);
}

void		init_my_printf(t_count *count, flag **flag_ptr)
{
  count->nb_char = 0;
  count->i = 0;
  *flag_ptr = stock_flags();
}

int		my_printf(const char *format, ...)
{
  t_count      	count;
  va_list	ap;
  flag		*flag_ptr;

  init_my_printf(&count, &flag_ptr);
  va_start(ap, format);
  while (format[count.i] != '\0')
    {
      if (format[count.i] == '%')
	{
	  count.i++;
	  read_fg(format, &count, flag_ptr, ap);
	}
      else
	{
	  my_putchar(format[count.i]);
	  count.nb_char++;
	}
      count.i++;
    }
  va_end(ap);
  free(flag_ptr);
  return (count.nb_char);
}
