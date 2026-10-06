#include <stdio.h>

int factorielle(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * factorielle(n - 1);
}

int main(void)
{
    int nombre;

    printf("Entrez un entier naturel : ");
    scanf("%d", &nombre);

    if (nombre < 0)
    {
        printf("Erreur : le nombre doit être positif.\n");
        return 1;
    }

    printf("%d! = %d\n", nombre, factorielle(nombre));

    return 0;
}
