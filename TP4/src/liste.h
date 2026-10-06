#ifndef LISTE_H
#define LISTE_H

typedef struct Couleur
{
    int rouge;
    int vert;
    int bleu;
    struct Couleur *suivant;
} Couleur;

void init_liste(Couleur **liste);
void insertion(Couleur **liste, int rouge, int vert, int bleu);
void parcours(Couleur *liste);

#endif

