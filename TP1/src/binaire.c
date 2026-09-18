#include <stdio.h>

void afficher_binaire(unsigned int nombre) {
    if (nombre == 0) {
        printf("0");
        return;
    }

    int bits[32];
    int i = 0;

    while (nombre > 0) {
        bits[i] = nombre % 2;
        nombre = nombre / 2;
        i++;
    }

    for (i = i - 1; i >= 0; i--) {
        printf("%d", bits[i]);
    }
}

int main() {
    unsigned int nombres[] = {0, 4096, 65536, 65535, 1024};
    int taille = 5;

    for (int i = 0; i < taille; i++) {
        printf("%u en binaire : ", nombres[i]);
        afficher_binaire(nombres[i]);
        printf("\n");
    }

    return 0;
}