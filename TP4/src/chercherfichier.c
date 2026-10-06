#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fichier;
    char nom_fichier[100];
    char phrase[100];
    char ligne[500];
    int numero_ligne = 0;
    int trouve = 0;

    printf("Nom du fichier : ");
    scanf("%99s", nom_fichier);

    getchar();

    printf("Phrase à rechercher : ");
    fgets(phrase, sizeof(phrase), stdin);

    phrase[strcspn(phrase, "\n")] = '\0';

    fichier = fopen(nom_fichier, "r");

    if (fichier == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier.\n");
        return 1;
    }

    while (fgets(ligne, sizeof(ligne), fichier) != NULL)
    {
        char *position = ligne;
        int occurrences = 0;

        numero_ligne++;

        while ((position = strstr(position, phrase)) != NULL)
        {
            occurrences++;
            position++;
        }

        if (occurrences > 0)
        {
            printf("Ligne %d : %d occurrence(s)\n",
                   numero_ligne, occurrences);
            trouve = 1;
        }
    }

    fclose(fichier);

    if (!trouve)
    {
        printf("Phrase non trouvée.\n");
    }

    return 0;
}
