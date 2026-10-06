#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
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
