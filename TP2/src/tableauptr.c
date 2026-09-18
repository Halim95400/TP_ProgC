#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tabInt[10];
    float tabFloat[10];

    srand(time(NULL));

    /* Remplissage des tableaux */
    for (int i = 0; i < 10; i++) {
        tabInt[i] = rand() % 100;
        tabFloat[i] = (float)(rand() % 100);
    }

    /* Affichage avant modification */
    printf("Tableau int avant :\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", tabInt[i]);
    }

    printf("\n\nTableau float avant :\n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", tabFloat[i]);
    }

    /* Manipulation avec des pointeurs */
    int *pInt = tabInt;
    float *pFloat = tabFloat;

    for (int i = 0; i < 10; i += 2) {
        *(pInt + i) *= 3;
        *(pFloat + i) *= 3;
    }

    /* Affichage après modification */
    printf("\n\nTableau int après :\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", tabInt[i]);
    }

    printf("\n\nTableau float après :\n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", tabFloat[i]);
    }

    printf("\n");

    return 0;
}
