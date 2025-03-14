#include <stdio.h>
#include <string.h>

int main()
{
    int a, b;

    printf("Podaj przedzial [a, b]: ");
    scanf("%d %d", &a, &b);

    for (int i = a; i <= b; i++)
    {
        int square = i * i;
        char n_str[12];
        sprintf(n_str, "%d", i);
        char square_str[12];
        sprintf(square_str, "%d", square);

        int n_len = strlen(n_str);
        int square_len = strlen(square_str);

        for (int j = n_len - 1, k = square_len - 1; j >= 0; j--, k--)
        {
            if (n_str[j] != square_str[k])
            {
                break;
            }
            if (j == 0)
            {
                printf("%d^2 = %d\n", i, square);
            }
        }

    }

    return 0;
}