#ifndef PROJETF1_PILOTE_H
#define PROJETF1_PILOTE_H

typedef struct {
    char nom[50];
    char prenom[50];
    char pays[50];
    char ecurie[50];
    int points; int numero; int age; int actif;
} Pilote;

void afficherPilote(const Pilote *p);
void afficherListePilotes(Pilote liste[], int nbPilotes);
void ajouterNouveauPilote(Pilote liste[], int *nbPilotes);
void retirerPilote(Pilote liste[], int *nbPilotes);
void miseAJourPointsManuelle(Pilote liste[], int nbPilotes);
void miseAJourPointsCourse(Pilote liste[], int nbPilotes, int classement[], int nbPositions);

#endif
