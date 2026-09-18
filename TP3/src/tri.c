#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tableau[100];

    srand(time(NULL));

    /* Remplissage du tableau */
    for (int i = 0; i < 100; i++) {
        tableau[i] = rand() % 1000;
    }

    /* Affichage du tableau non trié */
    printf("Tableau non trié :\n");

    for (int i = 0; i < 100; i++) {
        printf("%d ", tableau[i]);
    }

    printf("\n\n");

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

    /* Affichage du tableau trié */
    printf("Tableau trié par ordre croissant :\n");

    for (int i = 0; i < 100; i++) {
        printf("%d ", tableau[i]);
    }

    printf("\n");

    return 0;
}
