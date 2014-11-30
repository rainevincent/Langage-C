#include <stdio.h>
#include <stdlib.h>
#include "changement_gen.h"

int nb_voisins_M(int **tab, int i, int j, int n, int m){         // Fonction pour verifier la presence de voisins vivants
    int nb_vivantes = 0;                                         // Initialisation du compteur a 0
    int k, l;
    // Cas general : pour une cellule au centre du tableau
    if ((j > 0) && (j < m) && (i > 0) && (i < n)) {              // Dans les cas ou l'on est pas 'au bord' du tableau
        for (k = -1; k < 2; k++) {                               // Parcours des 8 cellules autour des coordonnees entrees
            for (l = -1; l < 2; l++) {
                if (tab[i+k][j+l] == 1) {                        // Test de l'etat de la cellule : si elle est a 1 : incrementer le nombre de cellule
                    nb_vivantes++;
                }
            }
        }
    }
    // Coin Haut-Gauche
    if ((j == 0) && (i == 0)) {
        for (k = 0; k < 2; k++) {                                // Parcours des 3 cellules autour des coordonnees entrees
            for (l = 0; l < 2; l++) {
                if (tab[i+k][j+l] == 1) {                        // Test de l'etat de la cellule : si elle est a 1 : incrementer le nombre de cellule
                    nb_vivantes++;
                }
            }
        }
    }
    // Coin Bas-Gauche
    if ((j == 0) && (i == n)) {
        for (k = -1; k < 1; k++) {                               // Parcours des 3 cellules autour des coordonnees entrees
            for (l = 0; l < 2; l++) {
                if (tab[i+k][j+l] == 1) {                        // Test de l'etat de la cellule : si elle est a 1 : incrementer le nombre de cellule
                    nb_vivantes++;
                }
            }
        }
    }
    // Coin Haut-Droit
    if ((j == m) && (i == 0)) {
        for (k = 0; k < 2; k++) {                               // Parcours des 3 cellules autour des coordonnees entrees
            for (l = -1; l < 1; l++) {
                if (tab[i+k][j+l] == 1) {                        // Test de l'etat de la cellule : si elle est a 1 : incrementer le nombre de cellule
                    nb_vivantes++;
                }
            }
        }
    }
    // Coin Bas-Droit
    if ((j == m) && (i == n)) {
        for (k = -1; k < 1; k++) {                               // Parcours des 3 cellules autour des coordonnees entrees
            for (l = -1; l < 1; l++) {
                if (tab[i+k][j+l] == 1) {                        // Test de l'etat de la cellule : si elle est a 1 : incrementer le nombre de cellule
                    nb_vivantes++;
                }
            }
        }
    }
    // Ligne du Bas sauf coins
    if ((j > 0) && (i == n) && (j < m)) {
        for (k = -1; k < 1; k++) {                               // Parcours des 5 cellules autour des coordonnees entrees
            for (l = -1; l < 2; l++) {
                if (tab[i+k][j+l] == 1) {                        // Test de l'etat de la cellule : si elle est a 1 : incrementer le nombre de cellule
                    nb_vivantes++;
                }
            }
        }
    }
    // Ligne du Haut sauf coins
    if ((j > 0) && (i == 0) && (j < m)) {
        for (k = 0; k < 2; k++) {                               // Parcours des 5 cellules autour des coordonnees entrees
            for (l = -1; l < 2; l++) {
                if (tab[i+k][j+l] == 1) {                        // Test de l'etat de la cellule : si elle est a 1 : incrementer le nombre de cellule
                    nb_vivantes++;
                }
            }
        }
    }
    // Colonne de Gauche sauf coins
    if ((j == 0) && (i > 0) && (i < n)) {
        for (k = -1; k < 2; k++) {                               // Parcours des 5 cellules autour des coordonnees entrees
            for (l = 0; l < 2; l++) {
                if (tab[i+k][j+l] == 1) {                        // Test de l'etat de la cellule : si elle est a 1 : incrementer le nombre de cellule
                    nb_vivantes++;
                }
            }
        }
    }
    // Colonne de Droite sauf coins
    if ((j == m) && (i > 0) && (i < n)) {
        for (k = -1; k < 2; k++) {                               // Parcours des 5 cellules autour des coordonnees entrees
            for (l = -1; l < 1; l++) {
                if (tab[i+k][j+l] == 1) {                        // Test de l'etat de la cellule : si elle est a 1 : incrementer le nombre de cellule
                    nb_vivantes++;
                }
            }
        }
    }
    if (tab[i][j] == 1) {                                    // Pour ne pas prendre en compte la cellule donnee si elle vaut 1 car on veut que les voisines
        nb_vivantes--;
    }
    return nb_vivantes;
}

void duplication(int **tab1, int **tab2, int n, int m){
    int i, j;                                                // Divers compteurs
    for (i = 0; i < n; i++) {                                // Parcours de chaque case du tableau principal et copie dans le secondaire
        for (j = 0; j < m; j++) {
            tab2[i][j] = tab1[i][j];
        }
    }
}

void generation_suivante_M(int **tab1, int **tab2, int n, int m, int B[9], int S[9]){
    int i, j, k;                                                                            // Compteurs
    for (i = 0; i < n; i++) {                                                               // Parcours du tableau principal
        for (j = 0; j < m; j++) {
            for (k = 0; k < 9; k++) {                                                       // Parcours du tableau pour les regles de naissance ou de survie
                if ((tab1[i][j] == 0) && (B[k] == 1) && (nb_voisins_M(tab1, i, j, n, m) == k)) {         // Si la celleule est morte et que les regles correspondent alors elle peut naitre a la generation suivante
                    tab2[i][j] = 1;
                }
                if ((tab1[i][j] == 1) && (S[k] == 1) && (nb_voisins_M(tab1, i, j, n, m) == k)) {         // Si la celleule est vivanteet que les regles correspondent alors elle peut survivre a la generation suivante
                    tab2[i][j] = 1;
                }
            }
        }
    }
}