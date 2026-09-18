#include <stdio.h>

int longueur(char chaine[]) {
    int i = 0;

    while (chaine[i] != '\0') {
        i++;
    }

    return i;
}

void copier(char destination[], char source[]) {
    int i = 0;

    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }

    destination[i] = '\0';
}

void concatener(char destination[], char source[]) {
    int i = 0;
    int j = 0;

    while (destination[i] != '\0') {
        i++;
    }

    while (source[j] != '\0') {
        destination[i] = source[j];
        i++;
        j++;
    }

    destination[i] = '\0';
}

int main() {
    char chaine1[100] = "Hello";
    char chaine2[] = " World!";
    char copie[100];

    printf("Longueur de chaine1 : %d\n", longueur(chaine1));

    copier(copie, chaine1);
    printf("Copie : %s\n", copie);

    concatener(chaine1, chaine2);
    printf("Concatenation : %s\n", chaine1);

    printf("Longueur finale : %d\n", longueur(chaine1));

    return 0;
}

