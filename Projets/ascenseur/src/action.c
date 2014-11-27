/*
** action.c for ascenceurs in /home/rainev/Desktop/Exia/Prosit/Project/ascenseur
**
** Made by rainev
** Login   <vincent.raine@viacesi.fr>
**
** Started on  Sat Nov 15 09:56:05 2014 rainev
** Last update Sat Nov 15 11:01:50 2014 rainev
*/

#include "action.h"

void	appel(int *etg)
{
  int	i;

  *etg = -6;
  while((*etg <=-6) || (*etg >= 16) && (*etg < 100) || (*etg > 100))
    {
      printf("A  quel étage vous situez vous ? :");
      scanf("%d", etg);
      printf("\n");
    }
}

void	deplacement(int *tabAscenseur, int *etg, int *numAsc)
{
  choixAscenseur(tabAscenseur, etg, numAsc);
  selection(etg);

  if (*etg != 100)
    deplacementAscenseur(tabAscenseur, etg, numAsc);
  else
    {
      printf("Erreur :\n\n");
      printf("- Il n'y à pas 100 étages (Nous ne sommes pas à New York ^^)\n");
      printf("- Fermeture de la simulation des ascenseur\n");

      exit(EXIT_SUCCESS);
    }
}

void	selection(int *etg)
{
  int temp = -6;
  while ( (temp <=-6)||(temp >= 16)&&(temp <100)||(temp>100) )
    {
      printf ("Entrez le numéro de l'étage où vous souhaitez allez :");
      scanf ("%d", &temp);
      printf ("\n");
    }
  *etg = temp;
}

void	choixAscenseur(int *tabAscenseur, int *etg, int *numAsc)
{
  int	ecart;
  int	i;
  int	temp;

  ecart = 21;
  i = 0;
  while(i < NB_ASC)
    {
      if (*etg >= tabAscenseur [i])
	/* l'ascenseur appelé doit monter */
	temp = *etg - tabAscenseur [i];
      else
	/* l'ascenseur appelé doit descendre */
	temp = tabAscenseur [i] - *etg;
      if (temp < ecart)
	{
	  ecart = temp;
	  *numAsc = i;
	}
      i++;
    }

  i = 0;
  while(i < ecart)
    {
      if (*etg > tabAscenseur[*numAsc])
	/* l'ascenseur appelé doit monter */
	{
	  printf ("Ascenseur numéro: %d\n", (*numAsc + 1));
	  printf("Etage %d\n", (tabAscenseur[*numAsc]+i));
	  sleep (1);
	}
      if (*etg < tabAscenseur[*numAsc])
	/* l'ascenseur appelé doit descendre */
	{
	  printf("Ascenseur numéro %d\n", (*numAsc + 1));
	  printf("Etage %d\n", (tabAscenseur[*numAsc] - i));
	  sleep (1);
	}

      if (*etg > tabAscenseur[*numAsc])
	/* l'ascenseur appelé doit monter */
	{
	  printf("Ascenseur numéro %d\n", (*numAsc + 1));
	  printf("Etage %d\n", (tabAscenseur [*numAsc]+ecart));
	  sleep (1);
	}
      if (*etg < tabAscenseur [*numAsc])
	/* l'ascenseur appelé doit descendre */
	{
	  printf("Ascenseur numéro %d\n", (*numAsc + 1));
	  printf("Etage %d\n", (tabAscenseur[*numAsc] - ecart));
	  sleep (1);
	}
      if (*etg == tabAscenseur[*numAsc])
	/* l'ascenseur appelé ne bouge pas */
	{
	  printf("Ascenseur numéro %d\n", (*numAsc + 1));
	  printf("Etage %d\n", (tabAscenseur[*numAsc]-ecart));
	  sleep (1);
	}
      /*
	Déplacement de l'ascenseur selectionné vers l'utilisateur
	Ascenseur: 1 seconde d'attente par étage
      */

      printf ("vous êtes dans l'ascenseur numéro %d\n", *numAsc+1);
      tabAscenseur [*numAsc] = *etg;
      /* l'ascenseur sélectionné est à l'étage de l'utilisateur */
    }
}

void	deplacementAscenseur(int *tabAscenseur, int *etg, int *numAsc)
{
  int	ecart;
  int	i;

  if (*etg >= tabAscenseur[*numAsc])
    /* l'ascenseur appelé doit monter */
    ecart = *etg - tabAscenseur[*numAsc];
  else
    /* l'ascenseur appelé doit descendre */
    ecart = tabAscenseur[*numAsc] - *etg;
  i = 0;
  while(i < ecart)
    {
      if (*etg > tabAscenseur[*numAsc])
	/* l'ascenseur appelé doit monter */
	{
	  printf("Ascenseur numéro %d\n", (*numAsc + 1));
	  printf("Etage %d\n", (tabAscenseur [*numAsc]+i));
	  sleep (1);
	}
      if (*etg < tabAscenseur [*numAsc])
	/* l'ascenseur appelé doit descendre */
	{
	  printf("Ascenseur numéro %d\n", (*numAsc + 1));
	  printf("Etage %d\n", (tabAscenseur[*numAsc] - i));
	  sleep (1);
	}
      i++;
    }
  if (*etg > tabAscenseur[*numAsc])
    /* l'ascenseur appelé doit monter */
    {
      printf("Ascenseur numéro %d\n", (*numAsc + 1));
      printf("Etage %d\n", (tabAscenseur[*numAsc] + ecart));
      printf("Vous êtes arrivé\n");
      sleep (1);
    }

  if (*etg < tabAscenseur[*numAsc])
    /* L'ascenseur appelé doit descendre */
    {
      printf("Ascenseur numéro %d\n", (*numAsc+1));
      printf("Etage %d\n",tabAscenseur[*numAsc] - ecart);
      sleep (1);
    }
  if (*etg == tabAscenseur [*numAsc])
    /* l'ascenseur appelé rester la */
    {
      printf("Ascenseur numéro %d\n", (*numAsc + 1));
      printf("Etage %d\n", (tabAscenseur[*numAsc] - ecart));
      printf("Vous êtes arrivés");
      sleep (1);
    }
  /*
    Déplacement de l'ascenseur vers l'étage
    selectionné par l'utilisateur
  */
tabAscenseur [*numAsc] = *etg;
}
