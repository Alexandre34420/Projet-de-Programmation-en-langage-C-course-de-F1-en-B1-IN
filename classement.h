#ifndef PROJETF1_CLASSEMENT_H
#define PROJETF1_CLASSEMENT_H
#include "pilote.h"
#include "ecurie.h"
#include "grandprix.h"
void calculePointsConstructeurs(Ecurie ecuries[], int nbEcuries, Pilote pilotes[], int nbPilotes);
void afficherClassementsPilotes(Pilote pilotes[], int nbPilotes);
void afficherClassementConstructeurs(Ecurie ecuries[], int nbEcurie);
void afficherClassementCourse(GrandPrix gp);

#endif