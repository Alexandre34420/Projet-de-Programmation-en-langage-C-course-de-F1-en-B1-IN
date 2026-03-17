#ifndef PROJETF1_DATE_H
#define PROJETF1_DATE_H

typedef struct {
    int heure;
    int minute;
} Heure;


typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

void afficheDate(Date d);
void afficheHeure(Heure h);
Date creeDate(int jour, int mois, int annee);
Heure creeHeure(int heure, int minute);

#endif
