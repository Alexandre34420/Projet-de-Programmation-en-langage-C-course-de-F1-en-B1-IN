#include <stdio.h>
#include "date.h"

// Crée une date avec le jour, mois et année spécifiés
Date creeDate(int jour, int mois, int annee) {
    Date d;
    d.jour = jour;
    d.mois = mois;
    d.annee = annee;
    return d;
}

// Crée une heure avec les heures et minutes spécifiées
Heure creeHeure(int heure, int minute) {
    Heure h;
    h.heure = heure;
    h.minute = minute;
    return h;
}

// Affiche la date au format jj/mm/aaaa
void afficheDate(Date d) {
    printf("%02d/%02d/%04d", d.jour, d.mois, d.annee);
}

// Affiche l'heure au format hh:mm
void afficheHeure(Heure h) {
    printf("%02dh%02d", h.heure, h.minute);
}
