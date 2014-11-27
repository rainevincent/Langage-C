#include <stdio.h>
#include <stdlib.h>

#include "affiche_moore.h"
#include "changement_gen.h"
#include "jeu.h"

int main(int argc, const char * argv[])
{
    int nb_lignes, nb_colonnes;                                                 // Entiers pour les lignes et colonnes du tableau 'principal'
    int **tableau_principal = NULL;                                             // Declaration d'un tableau d'entiers a 2 dimensions (tableau de tableau)
    int **tableau_secondaire = NULL;                                            // Declaration d'un tableau d'entiers a 2 dimensions (tableau de tableau)
    int tableau_regles_naissance_moore[9], tableau_regles_survie_moore[9];      // Tableau pour les regles de naissance et survie pour Moore
    int i;
    int nombre_generation;                                                      // Nombre de generations voulues
    int choix = 0;
    
    dimensionnement(&nb_lignes, &nb_colonnes);                                  // Appel de la fonction de dimensionnment du tableau principal
    
    tableau_principal=malloc(nb_lignes * sizeof(int*));                         // Demande d'allocation du tableau principal
    if(tableau_principal == NULL) {
        EXIT_FAILURE;
    }                                                                           // Parcours du tableau et demande d'allocation d'un nouveau tableau
    for(i = 0; i < nb_lignes; i++) {                                            // dans chaque case du 'premier' tableau
        tableau_principal[i] = malloc(nb_colonnes * sizeof(int));
        if(tableau_principal[i] == NULL) {
            EXIT_FAILURE;
        }
    }                                                                           
    tableau_secondaire=malloc(nb_lignes * sizeof(int*));                         // Demande d'allocation du tableau secondaire
    if(tableau_secondaire == NULL) {
        EXIT_FAILURE;
    }                                                                           // Parcours du tableau et demande d'allocation d'un nouveau tableau
    for(i = 0; i < nb_lignes; i++) {                                            // dans chaque case du 'premier' tableau
        tableau_secondaire[i] = malloc(nb_colonnes * sizeof(int));
        if(tableau_secondaire[i] == NULL) {
            EXIT_FAILURE;
        }
    }
    
    initialisation(tableau_principal, nb_lignes, nb_colonnes);                  // Initialisation du tableau principal
    nombre_generation = nb_generation();                                        // Demande du nombre de generation souhaite et stockage dans un entier

    
    printf("\n\n============== Menu ==============");                           // Menu pour le type de jeu (Convivialite utilisateur)
    printf("\n\n1. Regles manuelles");
    printf("\n2. Regles de Conway");
    printf("\n3. Regles de Fredkin");
    printf("\n\nVotre Choix ? ");
    scanf("%d", &choix);
    printf("\n====================================\n\n\n");
    switch (choix) {
        case 1:                                                                 // Appel des fonctions de jeu de la vie defini 'a la main'
            saisie_B_M(tableau_regles_naissance_moore);                         // Regles de Naissance
            saisie_S_M(tableau_regles_survie_moore);                            // Regles de survie
            duplication(tableau_principal, tableau_secondaire, nb_lignes, nb_colonnes);
            jeu_M(tableau_principal, nb_lignes, nb_colonnes, tableau_regles_naissance_moore, tableau_regles_survie_moore, nombre_generation);
            break;
        case 2:
            jeu_conway(tableau_principal, nb_lignes, nb_colonnes, nombre_generation);
            break;
        case 3:
            jeu_fredkin(tableau_principal, nb_lignes, nb_colonnes, nombre_generation);
            break;
        default:
            printf("****** Erreur : Choix Invalide ******");
            break;
    }
    
    
    for (i = 0; i < nb_lignes; i++) {                                           // Liberation des 2 tebleaux de tableaux puis des 2 tableaux
        free(tableau_principal[i]);
        free(tableau_secondaire[i]);
    }
    free(tableau_principal);
    free(tableau_secondaire);
    return 0;
}