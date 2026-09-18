#include <stdio.h>

int main() {
    char c = 'A';
    short s = -100;
    unsigned short us = 100;
    int i = -1000;
    unsigned int ui = 1000;
    long int l = -100000;
    unsigned long int ul = 100000;
    long long int ll = -1000000;
    unsigned long long int ull = 1000000;
    float f = 3.14f;
    double d = 3.14159;
    long double ld = 3.1415926535L;

    printf("char : %c\n", c);
    printf("short : %hd\n", s);
    printf("unsigned short : %hu\n", us);
    printf("int : %d\n", i);
    printf("unsigned int : %u\n", ui);
    printf("long int : %ld\n", l);
    printf("unsigned long int : %lu\n", ul);
    printf("long long int : %lld\n", ll);
    printf("unsigned long long int : %llu\n", ull);
    printf("float : %.2f\n", f);
    printf("double : %.5f\n", d);
    printf("long double : %.10Lf\n", ld);

    return 0;
}