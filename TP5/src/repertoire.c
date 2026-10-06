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
