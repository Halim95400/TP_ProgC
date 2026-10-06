#include <stdio.h>
#include <stdlib.h>
#include "operator.h"

int main(int argc, char *argv[])
{
    char operateur;
    int num1;
    int num2;

    if (argc != 4)
    {
        printf("Usage : %s <operateur> <nombre1> <nombre2>\n", argv[0]);
        return 1;
    }

    operateur = argv[1][0];
    num1 = atoi(argv[2]);
    num2 = atoi(argv[3]);

    switch (operateur)
    {
        case '+':
            printf("Résultat : %d\n", addition(num1, num2));
            break;

        case '-':
            printf("Résultat : %d\n", soustraction(num1, num2));
            break;

        case '*':
            printf("Résultat : %d\n", multiplication(num1, num2));
            break;

        case '/':
            printf("Résultat : %d\n", division(num1, num2));
            break;

        case '%':
            printf("Résultat : %d\n", modulo(num1, num2));
            break;

        case '&':
            printf("Résultat : %d\n", et_logique(num1, num2));
            break;

        case '|':
            printf("Résultat : %d\n", ou_logique(num1, num2));
            break;

        case '~':
            printf("Résultat : %d\n", negation(num1));
            break;

        default:
            printf("Operateur invalide.\n");
            return 1;
    }

    return 0;
}

