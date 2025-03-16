#include <math.h>
#include <stdio.h>

#define MAX_SIZE 50

double calc_b(double a) {
    double one = (sin(a) * sin(a)) - 3;
    double two = sqrt(a + 1);

    double b = one / two;

    if (isnan(b) || isinf(b)) {
        return 3.31;
    }

    return b;
}

int main() {
    int n, m;

    double A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE];

    printf("Podaj n: ");
    scanf("%d", &n);
    printf("Podaj m: ");
    scanf("%d", &m);

    if (n >= MAX_SIZE || m >= MAX_SIZE) {
        printf("n, m < 50\n");
        return 1;
    }

    printf("Podaj macierz A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            B[i][j] = calc_b(A[i][j]);
        }
    }

    printf("Macierz B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%lf ", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}