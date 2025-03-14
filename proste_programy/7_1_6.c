#include <stdio.h>

int main() {
    int s, w;

    scanf("%d %d", &s, &w);

    for (int i = 0; i < w; i++)
    {
       for (int j = 0; j < s; j++)
        {
            printf("X");
        }
        printf("\n");
    }
    
    

    return 0;
}