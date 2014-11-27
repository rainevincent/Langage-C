/*
** main.c for ascenceurs in /home/rainev/Desktop/Exia/Prosit/Project/ascenseur
**
** Made by rainev
** Login   <vincent.raine@viacesi.fr>
**
** Started on  Sat Nov 15 09:47:33 2014 rainev
** Last update Sat Nov 15 10:56:41 2014 rainev
*/

#include "action.h"

int	main(void)
{
  int	*etg;
  int	*numAsc;
  int	*tabAscenseur;
  int	i;

  etg = (int*) malloc (sizeof(int));
  numAsc = (int*) malloc (sizeof(int));
  tabAscenseur = (int*) malloc (NB_ASC*sizeof(int));
  i = 0;

  while(i < NB_ASC)
    {
      tabAscenseur[i] = 0;
      i++;
    }
  *etg = 0;

  while(*etg != 100)
    {
      printf("============= Bloc d'ascenseurs ===============\n");
      i = 0;
      while(i < NB_ASC)
	{
	  printf("Ascenseur numéro:  %d\n", (i + 1));
	  printf("Etage :%d\n", tabAscenseur [i]);
	  i++;
	}
      printf("============= Bloc d'ascenseurs ===============\n\n");
      appel(etg);
      if (*etg != 100)
	deplacement (tabAscenseur, etg, numAsc);
      else
	printf ("Fermeture de la simalation du bloc d'ascenseur\n");
      /*
	si l'utilisateur tape un nombre supérieur à 100,
	erreur -> fin du programme
      */
    }
  exit(EXIT_SUCCESS);
}
