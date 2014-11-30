/*
** flag2.c for flag2 in /home/merran_g/work/c_elem/PSU_2018_my_printf
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Nov  6 15:32:01 2013 Geoffrey Merran
** Last update Sun Nov 17 15:39:27 2013 Geoffrey Merran
*/

#include "my_printf.h"
#include "my.h"

int		flag_X(va_list ap)
{
  return (my_putuint_base(va_arg(ap, int), "0123456789ABCDEF"));
}

int		flag_b(va_list ap)
{
  return (my_putuint_base(va_arg(ap, int), "01"));
}

int		flag_u(va_list ap)
{
  return (my_put_uint(va_arg(ap, unsigned int)));
}

int			flag_p(va_list ap)
{
  unsigned long int	ptr;

  ptr = va_arg(ap, unsigned long int);
  my_putstr("0x");
  return (my_putlonguint_base(ptr, "0123456789abcdef") + 2);
}

int		flag_percent()
{
  my_putchar('%');
  return (1);
}
