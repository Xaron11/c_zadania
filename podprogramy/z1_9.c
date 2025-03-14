#include <stdio.h>

int suma_cyfr(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return suma_cyfr(n / 10) + n % 10;
}

int main()
{
    int n;

    printf("Podaj n: ");
    scanf("%d", &n);

    int suma = suma_cyfr(n);

    printf("Suma cyfr: %d\n", suma);

    return 0;
}