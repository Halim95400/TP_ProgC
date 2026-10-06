#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#include "repertoire.h"

void lire_dossier(char *nom_repertoire)
{
    DIR *dossier;
    struct dirent *entree;

    dossier = opendir(nom_repertoire);

    if (dossier == NULL)
    {
        printf("Erreur : impossible d'ouvrir le répertoire.\n");
        return;
    }

    while ((entree = readdir(dossier)) != NULL)
    {
        printf("%s\n", entree->d_name);
    }

    closedir(dossier);
}

void lire_dossier_recursif(char *nom_repertoire)
{
    DIR *dossier;
    struct dirent *entree;
    char chemin[1024];
    struct stat informations;

    dossier = opendir(nom_repertoire);

    if (dossier == NULL)
    {
        printf("Erreur : impossible d'ouvrir %s\n", nom_repertoire);
        return;
    }

    while ((entree = readdir(dossier)) != NULL)
    {
        if (strcmp(entree->d_name, ".") == 0 ||
            strcmp(entree->d_name, "..") == 0)
        {
            continue;
        }

        printf("%s/%s\n", nom_repertoire, entree->d_name);

        snprintf(chemin, sizeof(chemin), "%s/%s",
                 nom_repertoire, entree->d_name);

        if (stat(chemin, &informations) == 0 &&
            S_ISDIR(informations.st_mode))
        {
            lire_dossier_recursif(chemin);
        }
    }

    closedir(dossier);
}

void lire_dossier_iteratif(char *nom_repertoire)
{
    char **pile;
    int taille = 0;
    int capacite = 100;

    pile = malloc(capacite * sizeof(char *));

    if (pile == NULL)
    {
        printf("Erreur : allocation mémoire impossible.\n");
        return;
    }

    pile[taille] = malloc(strlen(nom_repertoire) + 1);

    if (pile[taille] == NULL)
    {
        free(pile);
        return;
    }

    strcpy(pile[taille], nom_repertoire);
    taille++;

    while (taille > 0)
    {
        char *dossier_actuel;
        DIR *dossier;
        struct dirent *entree;

        taille--;
        dossier_actuel = pile[taille];

        dossier = opendir(dossier_actuel);

        if (dossier == NULL)
        {
            free(dossier_actuel);
            continue;
        }

        while ((entree = readdir(dossier)) != NULL)
        {
            char chemin[1024];
            struct stat informations;

            if (strcmp(entree->d_name, ".") == 0 ||
                strcmp(entree->d_name, "..") == 0)
            {
                continue;
            }

            snprintf(chemin, sizeof(chemin), "%s/%s",
                     dossier_actuel, entree->d_name);

            printf("%s\n", chemin);

            if (stat(chemin, &informations) == 0 &&
                S_ISDIR(informations.st_mode))
            {
                if (taille >= capacite)
                {
                    capacite *= 2;
                    pile = realloc(pile, capacite * sizeof(char *));
                }

                pile[taille] = malloc(strlen(chemin) + 1);

                if (pile[taille] != NULL)
                {
                    strcpy(pile[taille], chemin);
                    taille++;
                }
            }
        }

        closedir(dossier);
        free(dossier_actuel);
    }

    free(pile);
}
