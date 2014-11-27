#include <stdio.h>
#include <stdlib.h>
#include "affiche_moore.h"


void dimensionnement(int *n, int *m){                                                               // Pour choisir la taille du tableau principal
    do {
        printf("Choisissez le nombre de lignes du tableau : ");
        scanf("%d", n);
        printf("Choisissez le nombre de colonnes du tableau : ");
        scanf("%d", m);
    } while (*n <= 1 || *m <= 1);                                                                   // Boucle si la taille entree est non-valide
}


void initialisation(int **tab, int n, int m){                                                       // n: nb de lignes et m: nb de colonnes
    int i, j, k, l;                                                                                 // Divers compteurs utilises
    int nb_cellules_vivantes = 0;
    int tableau_abscisse[nb_cellules_vivantes];
    int tableau_ordonnee[nb_cellules_vivantes];
    int abscisse, ordonnee;
    
    for (i = 0; i < n; i++) {                                                                       // Initialisation de chaque case a '0'
        for(j = 0; j < m; j++) {
            tab[i][j] = 0;
        }
    }
    printf("Combien y a t'il de cellules vivantes a la premiere generation ? : ");
    scanf("%d", &nb_cellules_vivantes);                                                              // Saisie du nombre de cellule vivantes
    for (k = 0; k < nb_cellules_vivantes; k++) {
        printf("Abscisse et ordonnee de la cellule %d : ", k+1);
        scanf("%d\t%d", &abscisse, &ordonnee);                                                       // Abscisse et ordonnee de la n-ieme cellule stockee dans un tableau dedie
        if ((abscisse < 0) || (abscisse > m) || (ordonnee < 0) || (ordonnee > n)) {                  // Teste la valeur des coordonnees (ds le tab)
            printf("\n****** Erreur dans la saisie des coordonnees, veuillez saisir a nouveau ******\n\n");
            k--;                                                                                     // Sinon erreur et nouvelle saisie demandee
        }
        else {
            l=0;
            while ((abscisse == tableau_abscisse[l]) && (ordonnee == tableau_ordonnee[l])) {         // Teste si la cellule n'existe pas deja
                printf("\n****** Erreur : La cellule saisie existe deja... Il s'agit de la cellule numero %d ******\n\n", l+1);
                l++;
                k--;                                                                                 // Retour a la cellule precedente pour nouvelle saisie
            }
        }
        tab[ordonnee-1][abscisse-1] = 1;                                                             // Si tout est ok, enregistrement dans le tableau principal
        tableau_abscisse[k]=abscisse;                                                                // Et dans les tableaux charges de stocker les coordonnees pour la verification
        tableau_ordonnee[k]=ordonnee;
    }
}


int nb_generation() {                                                                               // Pour demander le nombre de generations souhaitees
    int nombre_generation;
    do {
        printf("Saisissez le nombre de generation souhaite : ");
        scanf("%d", &nombre_generation);
    } while (nombre_generation < 1);
    return nombre_generation;                                                                       // Puis le retourne simplement
}


void affiche(int **tab, int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if (tab[i][j]==1) {
                printf("o ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}


void affiche_fichier(int **tab, int n, int m, char *nom){
    int i, j;
    FILE *fichier = NULL;
    fichier = fopen("tableau.txt", "w");                                                            // Ecriture dans un fichier dedié et test si l'ouverture peut se faire
    if (fichier != NULL) {
        for (i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                if (tab[i][j]==1) {
                    fprintf(fichier, "o ");
                } else {
                    fprintf(fichier, ". ");
                }
            }
            fprintf(fichier, "\n");
        }
    }
    else {
        printf("\n****** Erreur : impossible d'ouvrir le fichier ******");                          // Sinon, cela renvoi une erreur a l'utilisateur
    }
    fclose(fichier);
    
}


void saisie_B_M(int B[9]){                                                                          // Saisie des regles de naissance de Moore
    int i;
    for (i = 0; i < 9; i++) {
        printf("Dans quel etat sera une cellule morte ayant %d voisins a la prochaine generation : ", i);
        scanf("%d", &B[i]);
        if ((B[i] != 0) && (B[i] != 1)) {                                                           // Teste la validite de la valeurs entree sinon recommence
            printf("\n****** Erreur dans la saisie de l'etat de la cellule, veuillez saisir a nouveau ******");
            i--;
        }
    }
}


void saisie_S_M(int S[9]){                                                                          // De meme pour les regles de Survie
    int j;
    for (j = 0; j < 9; j++) {
        printf("Dans quel etat sera une cellule vivante ayant %d voisins a la prochaine generation : ", j);
        scanf("%d", &S[j]);
        if ((S[j] != 0) && (S[j] != 1)) {
            printf("\n****** Erreur dans la saisie de l'etat de la cellule, veuillez saisir a nouveau ******");
            j--;
        }
    }
}