#ifndef Automate_moore_h
#define Automate_moore_h

void dimensionnement(int *n, int*m);

void initialisation(int **tab, int n, int m);

int nb_generation();

void affiche(int **tab, int n, int m);

void affiche_fichier(int **tab, int n, int m, char *nom);

void saisie_B_M(int B[9]);

void saisie_S_M(int S[9]);

#endif
