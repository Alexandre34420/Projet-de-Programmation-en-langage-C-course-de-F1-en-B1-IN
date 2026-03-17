#include "pilote.h"
#include <stdio.h>
#include <string.h>

// --- Attribution des points à chaque pilote selon son classement dans une course
void attribuerPointsCourse(Pilote tableauPilotes[], int totalPilotes, int classement[], int nbClassement) {
    // Grille de points standard (10 premiers)
    int tableauPoints[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

    for (int pos = 0; pos < nbClassement && pos < 10; pos++) {
        int idxPilote = classement[pos];

        // Vérifie que l'index du pilote est valide
        if (idxPilote >= 0 && idxPilote < totalPilotes) {
            tableauPilotes[idxPilote].points += tableauPoints[pos];
        }
    }
}

// --- Supprime un pilote à partir de son nom et prénom
void retirerPilote(Pilote listePilotes[], int *nombrePilotes) {
    char nomRecherche[50], prenomRecherche[50];
    int position = -1;

    printf("\n--- Suppression d'un pilote ---\n");
    printf("Nom du pilote : ");
    scanf(" %[^\n]", nomRecherche);

    printf("Prénom du pilote : ");
    scanf(" %[^\n]", prenomRecherche);

    // Recherche du pilote correspondant
    for (int i = 0; i < *nombrePilotes; i++) {
        if (strcmp(listePilotes[i].nom, nomRecherche) == 0 &&
            strcmp(listePilotes[i].prenom, prenomRecherche) == 0) {
            position = i;
            break;
        }
    }

    if (position == -1) {
        printf("Aucun pilote ne correspond au nom %s %s.\n", prenomRecherche, nomRecherche);
        return;
    }

    // Décalage du tableau pour supprimer le pilote
    for (int j = position; j < *nombrePilotes - 1; j++) {
        listePilotes[j] = listePilotes[j + 1];
    }

    (*nombrePilotes)--; // Décrémente le nombre total de pilotes
    printf("Le pilote %s %s a été retiré.\n", prenomRecherche, nomRecherche);
}

// --- Affiche les informations détaillées d'un pilote
void afficherInfosPilote(const Pilote *p) {
    if (p == NULL) return;

    printf(">> %s %s\n", p->prenom, p->nom);
    printf("Nationalité : %s\n", p->pays);
    printf("Équipe : %s\n", p->ecurie);
    printf("Numéro : %d | Points : %d | Âge : %d\n", p->numero, p->points, p->age);
    printf("---------------------------------------------\n");
}

// --- Affiche tous les pilotes actifs
void afficherListePilotes(Pilote listePilotes[], int totalPilotes) {
    printf("\n=== Liste des pilotes actifs ===\n");
    for (int i = 0; i < totalPilotes; i++) {
        if (listePilotes[i].actif) {  // Ne montre que les pilotes actifs
            printf("[%d] ", i + 1);
            afficherInfosPilote(&listePilotes[i]);
        }
    }
}

// --- Ajoute un nouveau pilote dans la liste
void ajouterNouveauPilote(Pilote listePilotes[], int *totalPilotes) {
    Pilote insertion;

    printf("\n--- Ajouter un pilote ---\n");

    // Saisie des informations du pilote
    printf("Nom : ");
    scanf(" %[^\n]", insertion.nom);

    printf("Prénom : ");
    scanf(" %[^\n]", insertion.prenom);

    printf("Nationalité : ");
    scanf(" %[^\n]", insertion.pays);

    printf("Écurie : ");
    scanf(" %[^\n]", insertion.ecurie);

    printf("Points initiaux : ");
    scanf("%d", &insertion.points);

    printf("Numéro de course : ");
    scanf("%d", &insertion.numero);

    printf("Âge : ");
    scanf("%d", &insertion.age);

    printf("Actif (1 Oui / 0 Non) : ");
    scanf("%d", &insertion.actif);

    // Ajout du pilote à la fin du tableau
    listePilotes[*totalPilotes] = insertion;
    (*totalPilotes)++;

    printf("✅ Pilote %s %s ajouté avec succès.\n", insertion.prenom, insertion.nom);
}
