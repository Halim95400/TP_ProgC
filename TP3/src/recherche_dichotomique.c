#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tableau[100];
    int recherche;
    int debut = 0;
    int fin = 99;
    int trouve = 0;

    srand(time(NULL));

    /* Remplissage du tableau */
    for (int i = 0; i < 100; i++) {
        tableau[i] = rand() % 1000 + 1;
    }

    /* Tri à bulles */
    for (int i = 0; i < 99; i++) {
        for (int j = 0; j < 99 - i; j++) {
            if (tableau[j] > tableau[j + 1]) {
                int temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
            }
        }
    }

    printf("Tableau trié :\n");

    for (int i = 0; i < 100; i++) {
        printf("%d ", tableau[i]);
    }

    printf("\n\nEntrez l'entier que vous souhaitez chercher : ");
    scanf("%d", &recherche);

    /* Recherche dichotomique */
    while (debut <= fin) {
        int milieu = (debut + fin) / 2;

        if (tableau[milieu] == recherche) {
            trouve = 1;
            break;
        } else if (recherche < tableau[milieu]) {
            fin = milieu - 1;
        } else {
            debut = milieu + 1;
        }
    }

    if (trouve) {
        printf("Résultat : entier présent\n");
    } else {
        printf("Résultat : entier absent\n");
    }

    return 0;
}
