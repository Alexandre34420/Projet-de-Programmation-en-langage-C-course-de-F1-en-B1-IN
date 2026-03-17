#include <stdio.h>
#include <string.h>
#include "date.h"
// #include "pilote.h" // à inclure si Pilote est utilisé
#include "grandprix.h"

// --- Insère un nouveau Grand Prix dans le tableau
void insererCourse(GrandPrix tableauCourses[], int *totalGP) {

    // Vide le buffer d'entrée pour éviter les inputs fantômes
    while (getchar() != '\n');

    GrandPrix course;

    printf("\n--- Creation d'une nouvelle course ---\n");

    printf("Intitule du circuit : ");
    scanf(" %[^\n]", course.nomCircuit);  // lit toute la ligne

    printf("Localisation (pays) : ");
    scanf(" %[^\n]", course.pays);

    printf("Nombre total de tours : ");
    scanf("%d", &course.nombreTours);

    int j, m, a;
    printf("Date (jour mois annee) : ");
    scanf("%d %d %d", &j, &m, &a);
    course.date = creeDate(j, m, a);

    int h, min;
    printf("Horaire (heures minutes) : ");
    scanf("%d %d", &h, &min);
    course.horaire = creeHeure(h, min);

    course.actif = 1;
    course.nombreResultats = 0;

    tableauCourses[*totalGP] = course;
    (*totalGP)++;

    printf("Course '%s' enregistree avec succes !\n\n", course.nomCircuit);
}


// --- Actualise les resultats (classement) d'un Grand Prix
void actualiserClassementGP(GrandPrix *evenement, int totalPilotes) {
    printf("--- Saisie des resultats pour : %s ---\n", evenement->nomCircuit);

    evenement->nombreResultats = totalPilotes;

    for (int i = 0; i < totalPilotes; i++) {
        printf("\nPilote %d sur %d\n", i + 1, totalPilotes);
        printf("Nom : ");
        // BUG : scanf(" %[^]") n'est pas correct. Il faut limiter le format avec une taille max et inclure un espace pour ignorer les blancs
        scanf(" %49[^\n]", evenement->resultats[i].nomPilote);
        printf("Prenom : ");
        scanf(" %49[^\n]", evenement->resultats[i].prenomPilote);
        printf("Nationalite : ");
        scanf(" %49[^\n]", evenement->resultats[i].nationalite);
        printf("Ecurie : ");
        scanf(" %49[^\n]", evenement->resultats[i].ecurie);
        printf("Position finale : ");
        scanf("%d", &evenement->resultats[i].position);

        // Initialisation des points obtenus à 0
        evenement->resultats[i].pointsObtenus = 0;
    }

    printf("\nResultats enregistres pour %s !\n", evenement->nomCircuit);
}


// --- Recalcule les points de tous les pilotes a partir des resultats sauvegardes
void calculerPointsPilotes(Pilote piloteListe[], int totalPilotes, GrandPrix tableauCourses[], int totalGP) {
    // Remise a zero des points
    for (int i = 0; i < totalPilotes; i++) {
        piloteListe[i].points = 0;
    }

    // Grille de points standard pour les 10 premiers
    int grillePoints[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

    for (int i = 0; i < totalGP; i++) {
        for (int r = 0; r < tableauCourses[i].nombreResultats && r < 10; r++) {
            for (int p = 0; p < totalPilotes; p++) {
                if (strcmp(piloteListe[p].nom, tableauCourses[i].resultats[r].nomPilote) == 0 &&
                    strcmp(piloteListe[p].prenom, tableauCourses[i].resultats[r].prenomPilote) == 0) {
                    piloteListe[p].points += grillePoints[r];
                    // Stocke les points obtenus dans le GP pour l'affichage
                    tableauCourses[i].resultats[r].pointsObtenus = grillePoints[r];
                    break;
                }
            }
        }
    }
}


// --- Retire un Grand Prix et recalcul les points pilotes
void retirerGP(GrandPrix tableauCourses[], int *totalGP, Pilote piloteListe[], int totalPilotes) {
    char circuitASuppr[50];
    int idx = -1;

    printf("--- Suppression d'une course ---\n");
    printf("Saisir le nom du circuit a supprimer : ");
    scanf(" %49[^\n]", circuitASuppr); // Correction du scanf

    for (int i = 0; i < *totalGP; i++) {
        if (strcmp(tableauCourses[i].nomCircuit, circuitASuppr) == 0) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        printf("Circuit '%s' introuvable.\n", circuitASuppr);
        return;
    }

    for (int i = idx; i < *totalGP - 1; i++) {
        tableauCourses[i] = tableauCourses[i + 1];
    }
    (*totalGP)--;

    // Recalcule les points après suppression
    calculerPointsPilotes(piloteListe, totalPilotes, tableauCourses, *totalGP);

    printf("Circuit '%s' supprime et points pilotes mis a jour.\n", circuitASuppr);
}


// --- Affiche les informations d'un Grand Prix
void afficher_evenement(const GrandPrix *evenement) {
    if (evenement == NULL) return;
    printf("Circuit -> %s (pays: %s)\n", evenement->nomCircuit, evenement->pays);
    printf("Jour : ");
    afficheDate(evenement->date);
    printf("  Horaire : ");
    afficheHeure(evenement->horaire);
    printf("\nTours : %d\n", evenement->nombreTours);
    printf("Classement (%d pilotes) :\n", evenement->nombreResultats);
    for (int i = 0; i < evenement->nombreResultats; i++) {
        ResultatCourse rc = evenement->resultats[i];
        printf(" %2d) %s %s - %s - %s - %d pts\n",
               rc.position, rc.prenomPilote, rc.nomPilote, rc.nationalite, rc.ecurie, rc.pointsObtenus);
    }
    printf("----------------------------------------\n");
}


// --- Parcourt et affiche toutes les courses actives
void listerTousLesGPs(GrandPrix listeCourses[], int totalGP) {
    printf("\n=== Catalogue des Courses enregistrees ===\n");
    for (int i = 0; i < totalGP; i++) {
        if (listeCourses[i].actif) {
            printf("[%d] ", i + 1);
            afficher_evenement(&listeCourses[i]);
        }
    }
}
