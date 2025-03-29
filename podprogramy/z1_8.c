#include <stdio.h>

int set_digits(int n, char* digits) {
    int i = 0;
    while (n > 0) {
        digits[i++] = (n % 10);
        n /= 10;
    }
    return i;
}

int main() {
    int a, b;

    printf("Podaj przedzial [a, b]: ");
    scanf("%d %d", &a, &b);

    char n_digits[10];
    char square_digits[10];

    for (int i = a; i <= b; i++) {
        int square = i * i;
        int n_len = set_digits(i, n_digits);
        set_digits(square, square_digits);

        for (int j = 0, k = 0; j < n_len; j++, k++) {
            if (n_digits[j] != square_digits[k]) {
                break;
            }
            if (j == n_len - 1) {
                printf("%d^2 = %d\n", i, square);
            }
        }
    }

    return 0;
}