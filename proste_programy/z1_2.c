#include <stdio.h>

int main() {
    int a, b;

    do {
        printf("Podaj a (!= 0): ");
        scanf("%d", &a);

    } while (a == 0);

    do {
        printf("Podaj b (!= 0): ");
        scanf("%d", &b);

    } while (b == 0);

    double ad = (double)a;
    double bd = (double)b;
    double c = ad * (ad + bd) / ((ad + bd) * (ad + bd));

    printf("Wartosc wyrazenia to: %lf\n", c);

    return 0;
}