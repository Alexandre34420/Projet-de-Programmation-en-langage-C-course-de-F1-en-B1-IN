#include "classement.h"

#include <string.h>
#include <stdio.h> // stdio.h pour printf

// Fonction pour calculer les points totaux de chaque écurie en additionnant les points de ses pilotes
void calculePointsConstructeurs(Ecurie ecuries[], int nbEcuries, Pilote pilotes[], int nbPilotes){
    for (int i = 0; i < nbEcuries; i++) {
        int totalPoints = 0;

        for (int j = 0; j < nbPilotes; j++) {
            // Si le pilote appartient à cette écurie, on additionne ses points
            if (strcmp(pilotes[j].ecurie, ecuries[i].nom) == 0) {
                totalPoints += pilotes[j].points;
            }
        }

        ecuries[i].points = totalPoints; // On stocke le total dans l'écurie
    }
}

// Affiche le classement des écuries (constructeurs)
void afficherClassementConstructeurs(Ecurie ecuries[], int nbEcurie) {
    printf("Classement des constructeurs :\n");
    for (int i = 0; i < nbEcurie; i++ ) {
        printf("%d. %s (%s) - Points: %d\n", i + 1, ecuries[i].nom, ecuries[i].pays, ecuries[i].points);
    }
}

// Affiche le classement des pilotes trié par points décroissants
void afficherClassementsPilotes(Pilote pilotes[], int nbPilotes) {
    // Copier le tableau pour ne pas modifier l'ordre original
    Pilote tempPilotes[nbPilotes];
    memcpy(tempPilotes, pilotes, nbPilotes * sizeof(Pilote));

    // Tri à bulle simple par points décroissants
    for (int i = 0; i < nbPilotes - 1; i++) {
        for (int j = 0; j < nbPilotes - i - 1; j++) {
            if (tempPilotes[j].points < tempPilotes[j + 1].points) {
                Pilote temp = tempPilotes[j];
                tempPilotes[j] = tempPilotes[j + 1];
                tempPilotes[j + 1] = temp;
            }
        }
    }

    // Affichage du classement
    printf("Classement général des pilotes :\n");
    for (int i = 0; i < nbPilotes; i++) {
        printf("%d. %s %s (%s) - Ecurie: %s - Points: %d\n",
               i + 1,
               tempPilotes[i].prenom,
               tempPilotes[i].nom,
               tempPilotes[i].pays,
               tempPilotes[i].ecurie,
               tempPilotes[i].points);
    }
}

// Affiche le classement d'un Grand Prix
void afficherClassementCourse(GrandPrix gp) {
    printf("=== Classement du Grand Prix : %s (%s) ===\n\n", gp.nomCircuit, gp.pays);

    // En-tête avec colonnes plus larges pour éviter chevauchement
    printf("%-8s | %-20s | %-16s | %-18s | %-10s\n",
           "Position", "Pilote", "Nationalité", "Ecurie", "Temps");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < gp.nombreResultats; i++) {
        // Ajouter un symbole podium pour les 3 premiers
        char *podium = "";
        if (gp.resultats[i].position == 1) podium = "🥇";
        else if (gp.resultats[i].position == 2) podium = "🥈";
        else if (gp.resultats[i].position == 3) podium = "🥉";

        printf("%-8d | %-20s | %-16s | %-18s | %-10s %s\n",
               gp.resultats[i].position,
               gp.resultats[i].prenomPilote,
               gp.resultats[i].nationalite,
               gp.resultats[i].ecurie,
               gp.resultats[i].tempsRealise,
               podium);
    }

    printf("\n");
}
