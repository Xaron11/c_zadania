#include <stdio.h>

int main() {
    int w;

    scanf("%d", &w);

    for (int i = 1; i < w+1; i++)
    {
        for (int l = 0; l < w-i; l++)
        {
            printf(" ");
        }
        for (int j = 0; j < i*2-1; j++)
        {
            printf("X");
        }
        printf("\n");
    }
    

    return 0;
}