
#include <string.h>
#include "initialisation.h"
//#include "date.h"
//#include "pilote.h"
//#include "ecurie.h"
//#include "grandprix.h"

static const int pointsFIA[] = {0, 25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

//mise en place des points obtenues par les pilots

static void remplirResultat(ResultatCourse *r, const char *nom, const char *prenom, const char *nat, int pos, const char *temps) {
    strcpy(r->nomPilote, nom);
    strcpy(r->prenomPilote, prenom);
    strcpy(r->nationalite, nat);
    r->position = pos;
    strncpy(r->tempsRealise, temps, sizeof(r->tempsRealise)-1);//-1 pour laisse de la place au /0
    r->tempsRealise[sizeof(r->tempsRealise)-1] = '\0';
    r->pointsObtenus = (pos >=1 && pos <=10) ? pointsFIA[pos] : 0;
}

void initialiserLesDonnees(Ecurie ecuries[], Pilote pilotes[], GrandPrix grandsPrix[]) {
// les ecuries
    strcpy(ecuries[0].nom, "Red Bull Racing");
    strcpy(ecuries[0].pays, "Autriche");
    ecuries[0].points = 0;
    ecuries[0].anneeCreation = 2005;
    strcpy(ecuries[0].directeur, "Christian Horner");
    ecuries[0].actif = 1;

    strcpy(ecuries[1].nom, "Scuderia Ferrari");
    strcpy(ecuries[1].pays, "Italie");
    ecuries[1].points = 0;
    ecuries[1].anneeCreation = 1950;
    strcpy(ecuries[1].directeur, "Frederic Vasseur");
    ecuries[1].actif = 1;

    strcpy(ecuries[2].nom, "Mercedes-AMG");
    strcpy(ecuries[2].pays, "Allemagne");
    ecuries[2].points = 0;
    ecuries[2].anneeCreation = 2010;
    strcpy(ecuries[2].directeur, "Toto Wolff");
    ecuries[2].actif = 1;

    strcpy(ecuries[3].nom, "McLaren Racing");
    strcpy(ecuries[3].pays, "Royaume-Uni");
    ecuries[3].points = 0;
    ecuries[3].anneeCreation = 1966;
    strcpy(ecuries[3].directeur, "Andrea Stella");
    ecuries[3].actif = 1;

    strcpy(ecuries[4].nom, "Aston Martin");
    strcpy(ecuries[4].pays, "Royaume-Uni");
    ecuries[4].points = 0;
    ecuries[4].anneeCreation = 2021;
    strcpy(ecuries[4].directeur, "Mike Krack");
    ecuries[4].actif = 1;

    //initialisations de tout les pilotes & les pilotes sont 2 par ecuries
    strcpy(pilotes[0].nom, "Verstappen"); strcpy(pilotes[0].prenom, "Max"); strcpy(pilotes[0].pays, "Pays-Bas");
    strcpy(pilotes[0].ecurie, "Red Bull Racing"); pilotes[0].points = 46; pilotes[0].numero = 1; pilotes[0].age = 27; pilotes[0].actif = 1;

    strcpy(pilotes[1].nom, "Perez"); strcpy(pilotes[1].prenom, "Sergio"); strcpy(pilotes[1].pays, "Mexique");
    strcpy(pilotes[1].ecurie, "Red Bull Racing"); pilotes[1].points = 22; pilotes[1].numero = 11; pilotes[1].age = 34; pilotes[1].actif = 1;

    strcpy(pilotes[2].nom, "Leclerc"); strcpy(pilotes[2].prenom, "Charles"); strcpy(pilotes[2].pays, "Monaco");
    strcpy(pilotes[2].ecurie, "Scuderia Ferrari"); pilotes[2].points = 50; pilotes[2].numero = 16; pilotes[2].age = 27; pilotes[2].actif = 1;

    strcpy(pilotes[3].nom, "Sainz"); strcpy(pilotes[3].prenom, "Carlos"); strcpy(pilotes[3].pays, "Espagne");
    strcpy(pilotes[3].ecurie, "Scuderia Ferrari"); pilotes[3].points = 12; pilotes[3].numero = 55; pilotes[3].age = 30; pilotes[3].actif = 1;

    strcpy(pilotes[4].nom, "Hamilton"); strcpy(pilotes[4].prenom, "Lewis"); strcpy(pilotes[4].pays, "Royaume-Uni");
    strcpy(pilotes[4].ecurie, "Mercedes-AMG"); pilotes[4].points = 13; pilotes[4].numero = 44; pilotes[4].age = 39; pilotes[4].actif = 1;

    strcpy(pilotes[5].nom, "Russell"); strcpy(pilotes[5].prenom, "George"); strcpy(pilotes[5].pays, "Royaume-Uni");
    strcpy(pilotes[5].ecurie, "Mercedes-AMG"); pilotes[5].points = 17; pilotes[5].numero = 63; pilotes[5].age = 26; pilotes[5].actif = 1;

    strcpy(pilotes[6].nom, "Norris"); strcpy(pilotes[6].prenom, "Lando"); strcpy(pilotes[6].pays, "Royaume-Uni");
    strcpy(pilotes[6].ecurie, "McLaren Racing"); pilotes[6].points = 12; pilotes[6].numero = 4; pilotes[6].age = 25; pilotes[6].actif = 1;

    strcpy(pilotes[7].nom, "Piastri"); strcpy(pilotes[7].prenom, "Oscar"); strcpy(pilotes[7].pays, "Australie");
    strcpy(pilotes[7].ecurie, "McLaren Racing"); pilotes[7].points = 15; pilotes[7].numero = 81; pilotes[7].age = 23; pilotes[7].actif = 1;

    strcpy(pilotes[8].nom, "Alonso"); strcpy(pilotes[8].prenom, "Fernando"); strcpy(pilotes[8].pays, "Espagne");
    strcpy(pilotes[8].ecurie, "Aston Martin"); pilotes[8].points = 9; pilotes[8].numero = 14; pilotes[8].age = 43; pilotes[8].actif = 1;

    strcpy(pilotes[9].nom, "Stroll"); strcpy(pilotes[9].prenom, "Lance"); strcpy(pilotes[9].pays, "Canada");
    strcpy(pilotes[9].ecurie, "Aston Martin"); pilotes[9].points = 7; pilotes[9].numero = 18; pilotes[9].age = 26; pilotes[9].actif = 1;

//les grand prix
//grands prix 1
    strcpy(grandsPrix[0].nomCircuit, "Circuit de Monaco");
    strcpy(grandsPrix[0].pays, "Monaco");
    grandsPrix[0].nombreTours = 78;
    grandsPrix[0].date = creeDate(26, 5, 2024);
    grandsPrix[0].horaire = creeHeure(15, 0);
    grandsPrix[0].actif = 1;

//temps des pilotes
    remplirResultat(&grandsPrix[0].resultats[0], "Verstappen", "Max", "Pays-Bas", 1, "1:44:12.456");
    remplirResultat(&grandsPrix[0].resultats[1], "Leclerc", "Charles", "Monaco", 2, "1:44:18.234");
    remplirResultat(&grandsPrix[0].resultats[2], "Hamilton", "Lewis", "Royaume-Uni", 3, "1:44:25.678");
    remplirResultat(&grandsPrix[0].resultats[3], "Norris", "Lando", "Royaume-Uni", 4, "1:44:32.123");
    remplirResultat(&grandsPrix[0].resultats[4], "Sainz", "Carlos", "Espagne", 5, "1:44:39.456");
    remplirResultat(&grandsPrix[0].resultats[5], "Russell", "George", "Royaume-Uni", 6, "1:44:45.789");
    remplirResultat(&grandsPrix[0].resultats[6], "Perez", "Sergio", "Mexique", 7, "1:44:52.234");
    remplirResultat(&grandsPrix[0].resultats[7], "Alonso", "Fernando", "Espagne", 8, "1:44:58.567");
    remplirResultat(&grandsPrix[0].resultats[8], "Piastri", "Oscar", "Australie", 9, "1:45:04.890");
    remplirResultat(&grandsPrix[0].resultats[9], "Stroll", "Lance", "Canada", 10, "1:45:11.123");
    grandsPrix[0].nombreResultats = 10;

//grand prix 2
    strcpy(grandsPrix[1].nomCircuit, "Autodromo Nazionale Monza");
    strcpy(grandsPrix[1].pays, "Italie");
    grandsPrix[1].nombreTours = 53;
    grandsPrix[1].date = creeDate(8, 9, 2024);
    grandsPrix[1].horaire = creeHeure(14, 0);
    grandsPrix[1].actif = 1;

    remplirResultat(&grandsPrix[1].resultats[0], "Leclerc", "Charles", "Monaco", 1, "1:21:10.123");
    remplirResultat(&grandsPrix[1].resultats[1], "Verstappen", "Max", "Pays-Bas", 2, "1:21:15.456");
    remplirResultat(&grandsPrix[1].resultats[2], "Hamilton", "Lewis", "Royaume-Uni", 3, "1:21:20.789");
    remplirResultat(&grandsPrix[1].resultats[3], "Sainz", "Carlos", "Espagne", 4, "1:21:30.123");
    remplirResultat(&grandsPrix[1].resultats[4], "Perez", "Sergio", "Mexique", 5, "1:21:40.456");
    remplirResultat(&grandsPrix[1].resultats[5], "Russell", "George", "Royaume-Uni", 6, "1:21:50.789");
    remplirResultat(&grandsPrix[1].resultats[6], "Norris", "Lando", "Royaume-Uni", 7, "1:22:00.123");
    remplirResultat(&grandsPrix[1].resultats[7], "Piastri", "Oscar", "Australie", 8, "1:22:10.456");
    remplirResultat(&grandsPrix[1].resultats[8], "Alonso", "Fernando", "Espagne", 9, "1:22:20.789");
    remplirResultat(&grandsPrix[1].resultats[9], "Stroll", "Lance", "Canada", 10, "1:22:30.123");
    grandsPrix[1].nombreResultats = 10;

// grand prix 3
    strcpy(grandsPrix[2].nomCircuit, "Circuit de Spa-Francorchamps");
    strcpy(grandsPrix[2].pays, "Belgique");
    grandsPrix[2].nombreTours = 44;
    grandsPrix[2].date = creeDate(29, 8, 2024);
    grandsPrix[2].horaire = creeHeure(15, 0);
    grandsPrix[2].actif = 1;

    remplirResultat(&grandsPrix[2].resultats[0], "Hamilton", "Lewis", "Royaume-Uni", 1, "1:30:05.234");
    remplirResultat(&grandsPrix[2].resultats[1], "Verstappen", "Max", "Pays-Bas", 2, "1:30:10.567");
    remplirResultat(&grandsPrix[2].resultats[2], "Leclerc", "Charles", "Monaco", 3, "1:30:15.890");
    remplirResultat(&grandsPrix[2].resultats[3], "Perez", "Sergio", "Mexique", 4, "1:30:25.234");
    remplirResultat(&grandsPrix[2].resultats[4], "Sainz", "Carlos", "Espagne", 5, "1:30:35.567");
    remplirResultat(&grandsPrix[2].resultats[5], "Russell", "George", "Royaume-Uni", 6, "1:30:45.890");
    remplirResultat(&grandsPrix[2].resultats[6], "Norris", "Lando", "Royaume-Uni", 7, "1:30:55.234");
    remplirResultat(&grandsPrix[2].resultats[7], "Piastri", "Oscar", "Australie", 8, "1:31:05.567");
    remplirResultat(&grandsPrix[2].resultats[8], "Alonso", "Fernando", "Espagne", 9, "1:31:15.890");
    remplirResultat(&grandsPrix[2].resultats[9], "Stroll", "Lance", "Canada", 10, "1:31:25.234");
    grandsPrix[2].nombreResultats = 10;
}
