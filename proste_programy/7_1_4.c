#include <stdio.h>

int main() {
    for (int i = 0; i < 6; i++)
    {
        for (int l = 0; l < 5-i; l++)
        {
            printf(" ");
        }
        printf("A");
        for (int r = 0; r < i*2-1; r++)
        {
            if (i==3)
                printf("A");
            else
                printf(" ");
        }
        if (i != 0) {
            printf("A");
        }
        for (int r = 0; r < 5-i; r++)
        {
            printf(" ");
        }
        printf("\n");
    }
    

    return 0;
}