#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

void init_liste(Couleur **liste)
{
    *liste = NULL;
}

void insertion(Couleur **liste, int rouge, int vert, int bleu)
{
    Couleur *nouvelle;

    nouvelle = malloc(sizeof(Couleur));

    if (nouvelle == NULL)
    {
        printf("Erreur : allocation mémoire impossible.\n");
        return;
    }

    nouvelle->rouge = rouge;
    nouvelle->vert = vert;
    nouvelle->bleu = bleu;

    nouvelle->suivant = *liste;
    *liste = nouvelle;
}

void parcours(Couleur *liste)
{
    Couleur *courante = liste;
    int numero = 1;

    while (courante != NULL)
    {
        printf("Couleur %d : RGB(%d, %d, %d)\n",
               numero,
               courante->rouge,
               courante->vert,
               courante->bleu);

        courante = courante->suivant;
        numero++;
    }
}
