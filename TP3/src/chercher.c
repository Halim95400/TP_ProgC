#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tableau[100];
    int recherche;
    int trouve = 0;

    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        tableau[i] = rand() % 1000 + 1;
    }

    printf("Tableau :\n");

    for (int i = 0; i < 100; i++) {
        printf("%d ", tableau[i]);
    }

    printf("\n\nEntrez l'entier que vous souhaitez chercher : ");
    scanf("%d", &recherche);

    for (int i = 0; i < 100; i++) {
        if (tableau[i] == recherche) {
            trouve = 1;
            break;
        }
    }

    if (trouve) {
        printf("Résultat : entier présent\n");
    } else {
        printf("Résultat : entier absent\n");
    }

    return 0;
}

