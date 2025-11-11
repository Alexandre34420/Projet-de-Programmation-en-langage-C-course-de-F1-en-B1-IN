#ifndef PROJETF1_INITIALISATION_H
#define PROJETF1_INITIALISATION_H
#include "ecurie.h"
#include "pilote.h"
#include "grandprix.h"

void initialiserLesDonnees(Ecurie ecuries[], Pilote pilotes[], GrandPrix grandsPrix[]);
static void remplirResultat(ResultatCourse *r, const char *nom, const char *prenom, const char *nat, int pos, const char *temps);

#endif