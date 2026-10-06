#include <stdio.h>
#include <string.h>
#include "fichier.h"

typedef struct
{
    char nom[50];
    char prenom[50];
    int age;
    float note;
} Etudiant;

int main(void)
{
    Etudiant etudiants[5];
    FILE *fichier;

    fichier = fopen("etudiant.txt", "w");

    if (fichier == NULL)
    {
        printf("Erreur : impossible de créer le fichier.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("\n--- Etudiant %d ---\n", i + 1);

        printf("Nom : ");
        scanf("%49s", etudiants[i].nom);

        printf("Prenom : ");
        scanf("%49s", etudiants[i].prenom);

        printf("Age : ");
        scanf("%d", &etudiants[i].age);

        printf("Note : ");
        scanf("%f", &etudiants[i].note);

        fprintf(fichier, "%s %s %d %.2f\n",
                etudiants[i].nom,
                etudiants[i].prenom,
                etudiants[i].age,
                etudiants[i].note);
    }

    fclose(fichier);

    printf("\nLes 5 étudiants ont été enregistrés dans etudiant.txt.\n");

    return 0;
}
