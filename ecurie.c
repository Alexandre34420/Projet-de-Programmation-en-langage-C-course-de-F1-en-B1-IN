#include <stdio.h>
#include <string.h>
#include "ecurie.h"

// Affiche les informations d'une écurie
void afficherEcurie(const Ecurie *e) {
    if (e == NULL) return;
    printf("Nom : %s\n", e->nom);
    printf("Pays : %s\n", e->pays);
    printf("Directeur : %s\n", e->directeur);
    printf("Annee de creation : %d\n", e->anneeCreation);
    printf("Points : %d\n", e->points);
    printf("________________________________\n");
}

// Affiche toutes les écuries actives
void afficherToutesLesEcuries(Ecurie ecuries[], int *nbEcuries) {
    printf("\n/// Liste des Ecuries\n");
    for (int i = 0; i < *nbEcuries; i++) {
        if (ecuries[i].actif) {
            printf("[%d] ", i+1);
            afficherEcurie(&ecuries[i]);
        }
    }
}

// Ajoute une écurie à la liste
int ajouterEcurie(Ecurie ecuries[], int* nbEcuries) {
    if (*nbEcuries >= 10) { // Limite à 10 écuries
        printf("Nombre maximum d'ecuries atteint.\n");
        return 0;
    }
    Ecurie e;
    printf("Nom de l'ecurie : ");
    scanf("%49s", e.nom);  // Limite de caractères pour éviter erreurs
    printf("Pays : ");
    scanf("%49s", e.pays);
    printf("Annee de creation : ");
    scanf("%d", &e.anneeCreation);
    printf("Nom du directeur : ");
    scanf("%49s", e.directeur);

    e.points = 0;
    e.actif = 1;

    ecuries[*nbEcuries] = e;
    (*nbEcuries)++;
    return 1;
}

// Supprime une écurie et tous ses pilotes associés
void supprimerEcurie(Ecurie ecuries[], int* nbEcuries, Pilote pilotes[], int *nbPilotes) {
    char nomEcurie[50];
    int index = -1;

    printf("Vous souhaitez supprimer une ecurie\n");
    printf("Mettre le nom de l'ecurie à supprimer: ");
    scanf(" %[^\n]", nomEcurie); // Lit toute la ligne

    // Cherche l'écurie dans la liste
    for (int i = 0; i < *nbEcuries; i++) {
        if (strcmp(ecuries[i].nom, nomEcurie) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Ecurie %s n'a pas pu être trouvée.\n", nomEcurie);
        return;
    }

    // Supprime tous les pilotes de l'écurie
    for (int i = 0; i < *nbPilotes; ) {
        if (strcmp(pilotes[i].ecurie, nomEcurie) == 0) {
            // Décale tous les pilotes suivants pour écraser celui supprimé
            for (int j = i; j < *nbPilotes - 1; j++) {
                pilotes[j] = pilotes[j + 1];
            }
            (*nbPilotes)--;
        } else {
            i++;
        }
    }

    // Supprime l'écurie elle-même
    for (int i = index; i < *nbEcuries - 1; i++) {
        ecuries[i] = ecuries[i + 1];
    }
    (*nbEcuries)--;

    printf("L'ecurie %s ainsi que tous ses pilotes ont été correctement supprimés.\n", nomEcurie);
}
