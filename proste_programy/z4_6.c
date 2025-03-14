#include <stdio.h>
#include <stdlib.h>

// Liczby zaprzyjaźnione to takie dwie liczby, z których każda jest równa sumie podzielników drugiej
// liczby mniejszych od tej liczby. Na przykład 220 i 284 są zaprzyjaźnione, ponieważ: 220 dzieli się
// przez 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 i 110, których suma wynosi 284, zaś 284 dzieli się przez 1, 2,
// 71 i 142, których suma wynosi 220. Napisz program znajdujący wszystkie liczby zaprzyjaźnione z
// przedziału [1, a].

int main()
{
    int a;

    printf("Podaj a: ");
    scanf("%d", &a);

    int* sumy = (int*)malloc(a * sizeof(int));

    for (int l = 1; l < a; l++)
    {
        int sum = 0;
        for (int i = 1; i < l; i++)
        {
            if (l % i == 0)
            {
                sum += i;
            }
        }
        sumy[l] = sum;
    }

    for (int i = 1; i < a - 1; i++)
    {
        for (int j = i + 1; j < a; j++)
        {
            if (sumy[i] == j && sumy[j] == i)
            {
                printf("%d - %d\n", i, j);
            }
        }
    }

    free(sumy);

    return 0;
}