/*
** flag.c for flag in /home/merran_g/work/c_elem/PSU_2018_my_printf
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Nov  6 13:09:34 2013 Geoffrey Merran
** Last update Sun Nov 17 15:39:02 2013 Geoffrey Merran
*/

#include "my_printf.h"
#include "my.h"

int	flag_s(va_list ap)
{
  char	*str;

  str = va_arg(ap, char *);
  my_putstr(str);
  return (my_strlen(str));
}

int	flag_d(va_list ap)
{
  return (my_put_nbr(va_arg(ap, int)));
}

int	flag_c(va_list ap)
{
  my_putchar(va_arg(ap, int));
  return (1);
}

int	flag_o(va_list ap)
{
  return (my_putuint_base(va_arg(ap, unsigned int), "01234567"));
}

int	flag_x(va_list ap)
{
  return (my_putuint_base(va_arg(ap, unsigned int), "0123456789abcdef"));
}
