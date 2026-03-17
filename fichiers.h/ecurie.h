#ifndef PROJETF1_ECURIE_H
#define PROJETF1_ECURIE_H
#include "ecurie.h"
#include "pilote.h"

typedef struct {
    char nom[50];
    char pays[50];
    int points;
    int anneeCreation;
    char directeur[50];
    int actif;
} Ecurie;

void afficherEcurie(const Ecurie *e);
void afficherToutesLesEcuries(Ecurie ecuries[], int *nbEcuries);
int ajouterEcurie(Ecurie ecuries[], int *nbEcuries);
void supprimerEcurie(Ecurie ecuries[], int* nbEcuries, Pilote pilotes[], int *nbPilotes);

#endif
