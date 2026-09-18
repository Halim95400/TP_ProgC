#include <stdio.h>

int main() {
    char noms[5][30] = {
        "Dupont",
        "Martin",
        "Bernard",
        "Durand",
        "Petit"
    };

    char prenoms[5][30] = {
        "Marie",
        "Pierre",
        "Lucas",
        "Sophie",
        "Hugo"
    };

    char adresses[5][100] = {
        "20 Boulevard Niels Bohr, Lyon",
        "22 Boulevard Niels Bohr, Lyon",
        "10 Rue de Paris, Cergy",
        "15 Rue Victor Hugo, Paris",
        "8 Avenue de la Republique, Pontoise"
    };

    float programmation[5] = {16.5, 14.0, 12.5, 17.0, 15.5};
    float systeme[5] = {12.1, 14.1, 15.0, 13.5, 16.0};

    for (int i = 0; i < 5; i++) {
        printf("\nEtudiant %d :\n", i + 1);
        printf("Nom : %s\n", noms[i]);
        printf("Prenom : %s\n", prenoms[i]);
        printf("Adresse : %s\n", adresses[i]);
        printf("Programmation C : %.1f\n", programmation[i]);
        printf("Systeme d'exploitation : %.1f\n", systeme[i]);
    }

    return 0;
}
