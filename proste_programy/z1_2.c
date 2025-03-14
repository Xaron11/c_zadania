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

    int c = a * (a + b) / ((a + b) * (a + b));

    printf("Wartosc wyrazenia to: %d\n", c);

    return 0;
}