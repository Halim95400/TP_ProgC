#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main(void)
{
    Couleur *liste;

    init_liste(&liste);

    insertion(&liste, 255, 0, 0);
    insertion(&liste, 0, 255, 0);
    insertion(&liste, 0, 0, 255);
    insertion(&liste, 255, 255, 0);
    insertion(&liste, 255, 0, 255);
    insertion(&liste, 0, 255, 255);
    insertion(&liste, 255, 255, 255);
    insertion(&liste, 128, 128, 128);
    insertion(&liste, 0, 0, 0);
    insertion(&liste, 128, 0, 128);

    parcours(liste);

    while (liste != NULL)
    {
        Couleur *temp = liste;
        liste = liste->suivant;
        free(temp);
    }

    return 0;
}
