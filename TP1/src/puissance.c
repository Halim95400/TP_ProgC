#include <stdio.h>

int main() {
    int a = 2;
    int b = 3;
    int resultat = 1;

    for (int i = 0; i < b; i++) {
        resultat = resultat * a;
    }

    printf("%d puissance %d = %d\n", a, b, resultat);

    return 0;
}
