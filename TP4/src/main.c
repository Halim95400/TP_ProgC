#include <stdio.h>
#include <string.h>
#include "fichier.h"

int main(void)
{
    int choix;
    char nom_fichier[100];
    char message[500];

    printf("1. Lire un fichier\n");
    printf("2. Écrire dans un fichier\n");
    printf("Choix : ");
    scanf("%d", &choix);

    printf("Nom du fichier : ");
    scanf("%99s", nom_fichier);

    if (choix == 1)
    {
        lire_fichier(nom_fichier);
    }
    else if (choix == 2)
    {
        getchar();

        printf("Message à écrire : ");
        fgets(message, sizeof(message), stdin);

        message[strcspn(message, "\n")] = '\0';

        ecrire_dans_fichier(nom_fichier, message);
    }
    else
    {
        printf("Choix invalide.\n");
    }

    return 0;
}
