#include <stdio.h>
#include "fichier.h"

void lire_fichier(char *nom_fichier)
{
    FILE *fichier;
    char caractere;

    fichier = fopen(nom_fichier, "r");

    if (fichier == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier.\n");
        return;
    }

    while ((caractere = fgetc(fichier)) != EOF)
    {
        printf("%c", caractere);
    }

    fclose(fichier);
}

void ecrire_dans_fichier(char *nom_fichier, char *message)
{
    FILE *fichier;

    fichier = fopen(nom_fichier, "w");

    if (fichier == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier.\n");
        return;
    }

    fprintf(fichier, "%s", message);

    fclose(fichier);

    printf("Message écrit dans le fichier.\n");
}

