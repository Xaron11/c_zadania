#include <stdio.h>

#define MAX_SIZE 15

int r_matrix(int a, int b) { return a == b ? 1 : 0; }

int p_matrix(int a, int b) { return a <= b ? 1 : 0; }

int main() {
    int n, m;

    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE];
    int R[MAX_SIZE][MAX_SIZE], P[MAX_SIZE][MAX_SIZE];

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
            scanf("%d", &A[i][j]);
        }
    }

    printf("Podaj macierz B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            R[i][j] = r_matrix(A[i][j], B[i][j]);
            P[i][j] = p_matrix(A[i][j], B[i][j]);
        }
    }

    printf("Macierz R:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }

    printf("Macierz P:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", P[i][j]);
        }
        printf("\n");
    }

    return 0;
}