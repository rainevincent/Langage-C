/*
** my_sort_int_tabs.c for my_sort_int_tables in /home/merran_g/work/c_piscine/Piscine-C-Jour_07
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Tue Oct  8 16:10:16 2013 Geoffrey Merran
** Last update Mon Oct 21 12:58:24 2013 Geoffrey Merran
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	temp;

  i = 0;
  while (i != size)
    {
      if (tab[i] > tab[i + 1])
	{
	  temp = tab[i + 1];
	  tab[i + 1] = tab[i];
	  tab[i] = temp;
	  i = 0;
	}
      i++;
    }
}
