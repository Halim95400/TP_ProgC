#include <stdio.h>

int main() {
    char c = 'A';
    short s = 1234;
    int i = 123456;
    long l = 123456789;
    long long ll = 1234567890123LL;
    float f = 12.34f;
    double d = 56.789;

    char *pc = &c;
    short *ps = &s;
    int *pi = &i;
    long *pl = &l;
    long long *pll = &ll;
    float *pf = &f;
    double *pd = &d;

    printf("AVANT manipulation :\n");
    printf("char      : adresse=%p valeur=%X\n", (void *)pc, (unsigned int)c);
    printf("short     : adresse=%p valeur=%X\n", (void *)ps, (unsigned int)s);
    printf("int       : adresse=%p valeur=%X\n", (void *)pi, (unsigned int)i);
    printf("long      : adresse=%p valeur=%lX\n", (void *)pl, l);
    printf("long long : adresse=%p valeur=%llX\n", (void *)pll, ll);

    union {
        float f;
        unsigned int u;
    } uf;

    union {
        double d;
        unsigned long long u;
    } ud;

    uf.f = f;
    ud.d = d;

    printf("float     : adresse=%p valeur=%X\n", (void *)pf, uf.u);
    printf("double    : adresse=%p valeur=%llX\n", (void *)pd, ud.u);

    *pc = 'B';
    *ps = 4321;
    *pi = 654321;
    *pl = 987654321;
    *pll = 9876543210123LL;
    *pf = 43.21f;
    *pd = 98.765;

    uf.f = f;
    ud.d = d;

    printf("\nAPRES manipulation :\n");
    printf("char      : adresse=%p valeur=%X\n", (void *)pc, (unsigned int)c);
    printf("short     : adresse=%p valeur=%X\n", (void *)ps, (unsigned int)s);
    printf("int       : adresse=%p valeur=%X\n", (void *)pi, (unsigned int)i);
    printf("long      : adresse=%p valeur=%lX\n", (void *)pl, l);
    printf("long long : adresse=%p valeur=%llX\n", (void *)pll, ll);
    printf("float     : adresse=%p valeur=%X\n", (void *)pf, uf.u);
    printf("double    : adresse=%p valeur=%llX\n", (void *)pd, ud.u);

    return 0;
}

