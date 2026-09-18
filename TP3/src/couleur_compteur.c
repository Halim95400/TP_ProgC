#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Couleur {
    unsigned char R;
    unsigned char G;
    unsigned char B;
    unsigned char A;
};

struct CouleurComptee {
    struct Couleur couleur;
    int occurrences;
};

int meme_couleur(struct Couleur c1, struct Couleur c2) {
    return c1.R == c2.R &&
           c1.G == c2.G &&
           c1.B == c2.B &&
           c1.A == c2.A;
}

int main() {
    struct Couleur couleurs[100];
    struct CouleurComptee distinctes[100];
    int nombre_distinctes = 0;

    srand(time(NULL));

    /* Création des 100 couleurs */
    for (int i = 0; i < 100; i++) {
        couleurs[i].R = rand() % 5;
        couleurs[i].G = rand() % 5;
        couleurs[i].B = rand() % 5;
        couleurs[i].A = 255;
    }

    /* Recherche et comptage des couleurs */
    for (int i = 0; i < 100; i++) {
        int trouve = 0;

        for (int j = 0; j < nombre_distinctes; j++) {
            if (meme_couleur(couleurs[i], distinctes[j].couleur)) {
                distinctes[j].occurrences++;
                trouve = 1;
                break;
            }
        }

        if (!trouve) {
            distinctes[nombre_distinctes].couleur = couleurs[i];
            distinctes[nombre_distinctes].occurrences = 1;
            nombre_distinctes++;
        }
    }

    /* Affichage */
    printf("Couleurs distinctes :\n\n");

    for (int i = 0; i < nombre_distinctes; i++) {
        printf("%02x %02x %02x %02x : %d\n",
               distinctes[i].couleur.R,
               distinctes[i].couleur.G,
               distinctes[i].couleur.B,
               distinctes[i].couleur.A,
               distinctes[i].occurrences);
    }

    printf("\nNombre de couleurs distinctes : %d\n", nombre_distinctes);

    return 0;
}
