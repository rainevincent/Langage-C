/*
** action.h for ascenceurs in /home/rainev/Desktop/Exia/Prosit/Project/ascenseur
**
** Made by rainev
** Login   <vincent.raine@viacesi.fr>
**
** Started on  Sat Nov 15 09:53:54 2014 rainev
** Last update Sat Nov 15 11:00:55 2014 rainev
*/

#define __ACTION_H__

#ifndef __ACTION_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_ASC	6

void	appel(int *etg);
void	deplacement(int *tabAscenseur, int *etg, int *numAsc);
void	selection(int *etg);
void	choixAscenseur(int *tabAscenseur, int *etg, int *numAsc);
void	deplacementAscenseur(int *tabAscenseur, int *etg, int *numAsc);

#endif /* __ACTION_H__ */
