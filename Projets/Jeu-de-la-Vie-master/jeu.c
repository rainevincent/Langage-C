#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "changement_gen.h"
#include "affiche_moore.h"

void jeu_M(int **tab1, int n, int m, int B[9], int S[9], int ng) {                              // Jeu via des regles definies par le joueur
    int i;
    int **tab2 = NULL;
    FILE *fichier = NULL;
    
    for (i = 0; i < ng; i++) {                                                                  // Appel des fonctions vues dans les autres fichiers
        duplication(tab1, tab2, n, m);
        generation_suivante_M(tab1, tab2, n, m, &B[9], &S[9]);
        printf("\nAffichage pour la generation %d\n", i+1);
        affiche(tab2, n, m);
        affiche_fichier(tab2, n, m, fichier);
    }
}

void jeu_conway(int **tab1, int n, int m, int ng) {                                             // Jeu via des regles de Conway
    int i;
    int **tab2 = NULL;
    int tableau_naissance_conway[9] = {0,0,0,1,0,0,0,0,0};                                      // Definies dans ces tableaux
    int tableau_survie_conway[9] = {0,0,1,1,0,0,0,0,0};
    FILE *fichier = NULL;
    
    for (i = 0; i < ng; i++) {
        duplication(tab1, tab2, n, m);
        generation_suivante_M(tab1, tab2, n, m, tableau_naissance_conway, tableau_survie_conway);
        printf("\n\nAffichage pour la generation %d\n", i+1);
        affiche(tab2, n, m);
        affiche_fichier(tab2, n, m, fichier);
    }
}

void jeu_fredkin(int **tab1, int n, int m, int ng) {                                            // De meme pour le jeu de Fredkin
    int i;
    int **tab2 = NULL;
    int tableau_naissance_fredkin[9] = {0,1,0,1,0,1,0,1,0};
    int tableau_survie_fredkin[9] = {0,1,0,1,0,1,0,1,0};
    FILE *fichier = NULL;
    
    for (i = 0; i < ng; i++) {
        duplication(tab1, tab2, n, m);
        generation_suivante_M(tab1, tab2, n, m, tableau_naissance_fredkin, tableau_survie_fredkin);
        printf("\n\nAffichage pour la generation %d\n", i+1);
        affiche(tab2, n, m);
        affiche_fichier(tab2, n, m, fichier);
    }
}