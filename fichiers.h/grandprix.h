#ifndef PROJETF1_GRANDPRIX_H
#define PROJETF1_GRANDPRIX_H

#include "pilote.h"
#include "date.h"

typedef struct {
    char nomPilote[50];
    char prenomPilote[50];
    char nationalite[50];
    char ecurie[50];
    int position;
    char tempsRealise[20];
    int pointsObtenus;
} ResultatCourse;

typedef struct {
    char nomCircuit[50];
    char pays[50];
    int nombreTours;
    Date date;
    Heure horaire;
    ResultatCourse resultats[20];
    int nombreResultats;
    int actif;
} GrandPrix;

// Affichage
void afficher_evenement(const GrandPrix *course);
void listerTousLesGPs(GrandPrix tableauCourses[], int totalGP);

// Gestion des courses
void insererCourse(GrandPrix tableauCourses[], int *totalGP);
void retirerGP(GrandPrix tableauCourses[], int *totalGP, Pilote listePilotes[], int totalPilotes);

// Gestion résultats & points
void actualiserClassementGP(GrandPrix *course, int totalPilotes);
void calculerPointsPilotes(Pilote listePilotes[], int totalPilotes, GrandPrix tableauCourses[], int totalGP);

#endif
