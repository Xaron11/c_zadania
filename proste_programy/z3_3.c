#include <stdio.h>

int main()
{
    int n, m;

    printf("Podaj n: ");
    scanf("%d", &n);
    printf("Podaj m: ");
    scanf("%d", &m);

    double r = 0.0;

    for (int i = 1; i <= n; i++)
    {
        double p = 1.0;
        double id = (double)i;
        for (int j = 1; j <= m; j++)
        {
            double jd = (double)j;

            p *= (id * id + jd * jd - 1) / (2 * id + 3 * jd + 4);
        }
        r += p;
    }

    printf("R = %lf\n", r);

    return 0;
}