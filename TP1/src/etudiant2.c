#include <stdio.h>
#include <string.h>

struct Etudiant {
    char nom[30];
    char prenom[30];
    char adresse[100];
    float programmation;
    float systeme;
};

int main() {
    struct Etudiant etudiants[5];

    strcpy(etudiants[0].nom, "Dupont");
    strcpy(etudiants[0].prenom, "Marie");
    strcpy(etudiants[0].adresse, "20 Boulevard Niels Bohr, Lyon");
    etudiants[0].programmation = 16.5;
    etudiants[0].systeme = 12.1;

    strcpy(etudiants[1].nom, "Martin");
    strcpy(etudiants[1].prenom, "Pierre");
    strcpy(etudiants[1].adresse, "22 Boulevard Niels Bohr, Lyon");
    etudiants[1].programmation = 14.0;
    etudiants[1].systeme = 14.1;

    strcpy(etudiants[2].nom, "Bernard");
    strcpy(etudiants[2].prenom, "Lucas");
    strcpy(etudiants[2].adresse, "10 Rue de Paris, Cergy");
    etudiants[2].programmation = 12.5;
    etudiants[2].systeme = 15.0;

    strcpy(etudiants[3].nom, "Durand");
    strcpy(etudiants[3].prenom, "Sophie");
    strcpy(etudiants[3].adresse, "15 Rue Victor Hugo, Paris");
    etudiants[3].programmation = 17.0;
    etudiants[3].systeme = 13.5;

    strcpy(etudiants[4].nom, "Petit");
    strcpy(etudiants[4].prenom, "Hugo");
    strcpy(etudiants[4].adresse, "8 Avenue de la Republique, Pontoise");
    etudiants[4].programmation = 15.5;
    etudiants[4].systeme = 16.0;

    for (int i = 0; i < 5; i++) {
        printf("\nEtudiant %d :\n", i + 1);
        printf("Nom : %s\n", etudiants[i].nom);
        printf("Prenom : %s\n", etudiants[i].prenom);
        printf("Adresse : %s\n", etudiants[i].adresse);
        printf("Note Programmation C : %.1f\n", etudiants[i].programmation);
        printf("Note Systeme d'exploitation : %.1f\n", etudiants[i].systeme);
    }

    return 0;
}

