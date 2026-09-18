#include <stdio.h>

int main() {
    double rayon = 5.0;
    double pi = 3.14159;

    double aire = pi * rayon * rayon;
    double perimetre = 2 * pi * rayon;

    printf("Rayon : %.2f\n", rayon);
    printf("Aire : %.2f\n", aire);
    printf("Perimetre : %.2f\n", perimetre);

    return 0;
}
