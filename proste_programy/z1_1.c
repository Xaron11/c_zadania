#include <stdio.h>

int main() {
    double a, b, c;
    printf("Podaj a: ");
    scanf("%lf", &a);
    printf("Podaj b: ");
    scanf("%lf", &b);
    printf("Podaj c: ");
    scanf("%lf", &c);

    double max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }

    printf("Najwieksza liczba to: %lf\n", max);
    return 0;
}