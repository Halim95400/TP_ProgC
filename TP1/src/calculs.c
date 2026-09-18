#include <stdio.h>

int main() {
    int num1 = 16;
    int num2 = 3;
    char op = '&';

    switch (op) {
        case '+':
            printf("Resultat : %d\n", num1 + num2);
            break;

        case '-':
            printf("Resultat : %d\n", num1 - num2);
            break;

        case '*':
            printf("Resultat : %d\n", num1 * num2);
            break;

        case '/':
            if (num2 != 0)
                printf("Resultat : %d\n", num1 / num2);
            else
                printf("Division par zero impossible\n");
            break;

        case '%':
            if (num2 != 0)
                printf("Resultat : %d\n", num1 % num2);
            else
                printf("Modulo par zero impossible\n");
            break;

        case '&':
            printf("Resultat : %d\n", num1 & num2);
            break;

        case '|':
            printf("Resultat : %d\n", num1 | num2);
            break;

        case '~':
            printf("Resultat : %d\n", ~num1);
            break;

        default:
            printf("Operateur inconnu\n");
    }

    return 0;
}
