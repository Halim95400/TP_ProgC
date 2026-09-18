#include <stdio.h>

int comparer_chaines(char *chaine1, char *chaine2) {
    int i = 0;

    while (chaine1[i] != '\0' || chaine2[i] != '\0') {
        if (chaine1[i] != chaine2[i]) {
            return 0;
        }

        i++;
    }

    return 1;
}

int main() {
    char *phrases[10] = {
        "Bonjour, comment ca va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journee.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent etre deroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est interessante.",
        "Les structures de donnees sont importantes.",
        "Programmer en C, c'est genial."
    };

    char recherche[200];
    int trouve = 0;

    printf("Entrez la phrase que vous souhaitez chercher : ");
    fgets(recherche, sizeof(recherche), stdin);

    /* Suppression du retour à la ligne */
    int i = 0;
    while (recherche[i] != '\0') {
        if (recherche[i] == '\n') {
            recherche[i] = '\0';
            break;
        }
        i++;
    }

    for (i = 0; i < 10; i++) {
        if (comparer_chaines(phrases[i], recherche)) {
            trouve = 1;
            break;
        }
    }

    if (trouve) {
        printf("Phrase trouvée\n");
    } else {
        printf("Phrase non trouvée\n");
    }

    return 0;
}

