#include <stdio.h>

int main() {
    int g, w, s;

    scanf("%d %d %d", &g, &w, &s);

    for (int i = 0; i < w-g; i++)
    {
        for (int j = 0; j < g; j++)
        {
            printf("L");
        }
        printf("\n");
    }

    for (int i = 0; i < g; i++)
    {
        for (int j = 0; j < s; j++)
        {
            printf("L");
        }
        printf("\n");
    }
    
    

    return 0;
}