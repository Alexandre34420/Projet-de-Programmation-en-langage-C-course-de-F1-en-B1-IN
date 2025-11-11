#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "initialisation.h"
#include "grandprix.h"
#include "classement.h"

// --- Met à jour les points des écuries en additionnant les points de leurs pilotes
void mettreAJourPointsConstructeurs(Ecurie ecuries[], int nbEcuries, Pilote pilotes[], int nbPilotes)
{
    // On remet les points des écuries à zéro
    for (int i = 0; i < nbEcuries; i++) {
        ecuries[i].points = 0;
    }

    // Chaque écurie récupère les points de ses deux pilotes
    for (int i = 0; i < nbEcuries; i++) {
        int compteurPilotes = 0;

        for (int j = 0; j < nbPilotes; j++) {
            if (strcmp(pilotes[j].ecurie, ecuries[i].nom) == 0) {
                ecuries[i].points += pilotes[j].points;
                compteurPilotes++;

                // On arrête dès qu’on a trouvé les deux pilotes
                if (compteurPilotes == 2)
                    break;
            }
        }
    }
}

int main() {

    int choixPrincipal = -1; // choix du menu principal
    int choixSousMenu = -1;  // choix des sous-menus

    // Déclaration des tableaux
    Ecurie tableauEcuries[10];
    GrandPrix tableauGP[30];
    Pilote tableauPilotes[20];

    // Nombre initial d'éléments
    int nbEcuries = 5;
    int nbGP = 3;
    int nbPilotes = 10;

    // Initialisation des données par défaut
    initialiserLesDonnees(tableauEcuries, tableauPilotes, tableauGP);

    do {
        // Mise à jour des points des constructeurs à chaque boucle principale
        mettreAJourPointsConstructeurs(tableauEcuries, nbEcuries, tableauPilotes, nbPilotes);

        // Menu principal
        printf("Programme du championnat de F1\n");
        printf("1 - ecuries\n");
        printf("2 - Pilotes\n");
        printf("3 - Grands Prix\n");
        printf("4 - Classement\n");
        printf("0 - Quitter\n");
        printf("Choix : ");

        // Lecture sécurisée de l'entrée utilisateur
        if(scanf("%d", &choixPrincipal) != 1) {
            while(getchar() != '\n');
            choixPrincipal = -1;
        }
        getchar();

        switch(choixPrincipal) {

            case 1: // Écuries
                do {
                    printf("\n--- Menu Écuries ---\n");
                    printf("1 - Afficher toutes les écuries\n");
                    printf("2 - Ajouter une écurie\n");
                    printf("3 - Supprimer une écurie\n");
                    printf("0 - Retour au menu principal\n");
                    printf("Choix : ");
                    scanf("%d", &choixSousMenu);
                    getchar();

                    switch(choixSousMenu) {
                        case 1:
                            // Affiche toutes les écuries actives
                            for(int i=0; i<nbEcuries; i++)
                                if(tableauEcuries[i].actif)
                                    printf("%d) %s [%s] - %d pts | Dir: %s\n",
                                           i+1, tableauEcuries[i].nom, tableauEcuries[i].pays,
                                           tableauEcuries[i].points, tableauEcuries[i].directeur);
                            break;
                        case 2:
                            // Ajouter une écurie
                            ajouterEcurie(tableauEcuries, &nbEcuries);
                            break;
                        case 3:
                            // Supprimer une écurie et ses pilotes
                            supprimerEcurie(tableauEcuries, &nbEcuries, tableauPilotes, &nbPilotes);
                            break;
                        case 0:
                            break;
                        default:
                            printf("Choix invalide.\n");
                    }
                } while(choixSousMenu != 0);
                break;

            case 2: // Pilotes
                do {
                    printf("\n--- Menu Pilotes ---\n");
                    printf("1 - Afficher tous les pilotes\n");
                    printf("2 - Ajouter un pilote\n");
                    printf("3 - Supprimer un pilote\n");
                    printf("0 - Retour au menu principal\n");
                    printf("Choix : ");
                    scanf("%d", &choixSousMenu);
                    while (getchar() != '\n');

                    switch(choixSousMenu) {
                        case 1:
                            // Affiche la liste des pilotes
                            afficherListePilotes(tableauPilotes, nbPilotes);
                            break;
                        case 2:
                            // Ajoute un nouveau pilote
                            ajouterNouveauPilote(tableauPilotes, &nbPilotes);
                            break;
                        case 3:
                            // Supprime un pilote
                            retirerPilote(tableauPilotes, &nbPilotes);
                            break;
                        case 0:
                            break;
                        default:
                            printf("Choix invalide.\n");
                    }
                } while(choixSousMenu != 0);
                break;

            case 3: // Grands Prix
                do {
                    printf("\n--- Menu des Courses (Grands Prix) ---\n");
                    printf("1 - Afficher toutes les courses\n");
                    printf("2 - Ajouter une course\n");
                    printf("3 - Supprimer une course\n");
                    printf("0 - Retour au menu principal\n");
                    printf("Choix : ");
                    scanf("%d", &choixSousMenu);
                    while (getchar() != '\n');

                    switch(choixSousMenu) {
                        case 1:
                            // Affiche tous les GP
                            listerTousLesGPs(tableauGP, nbGP);
                            break;
                        case 2:
                            // Ajouter une nouvelle course
                            insererCourse(tableauGP, &nbGP);
                            break;
                        case 3:
                            // Supprimer une course et recalculer les points
                            retirerGP(tableauGP, &nbGP, tableauPilotes, nbPilotes);
                            break;
                        case 0:
                            break;
                        default:
                            printf("Choix invalide.\n");
                    }

                } while(choixSousMenu != 0);
                break;

            case 4: // Classement
                do {
                    printf("\n--- Menu Grands Prix ---\n");
                    printf("1 - Afficher le classement des pilotes\n");
                    printf("2 - Afficher le classement des constructeurs\n");
                    printf("0 - Retour au menu principal\n");
                    printf("Choix : ");
                    scanf("%d", &choixSousMenu);
                    getchar();

                    switch(choixSousMenu) {
                        case 1:
                            // Affiche le classement des pilotes
                            afficherClassementsPilotes(tableauPilotes, nbPilotes);
                            break;
                        case 2:
                            // Affiche le classement des constructeurs
                            afficherClassementConstructeurs(tableauEcuries, nbEcuries);
                            break;
                        default:
                            printf("Choix invalide.\n");
                    }
                } while(choixSousMenu != 0);
                break;

            case 0:
                printf("Fermeture du programme...\n");
                break;

            default:
                printf("Choix invalide.\n");
        }

    } while(choixPrincipal != 0);

    return 0;
}
