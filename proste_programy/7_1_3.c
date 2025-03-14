#include <stdio.h>

int main() {
    for (int i = 0; i < 10; i++)
    {
        printf("X");
    }
    printf("\n");
    for (int i = 0; i < 2; i++)
    {
        printf("X");
        for (int i = 0; i < 8; i++)
        {
            printf(" ");
        }
        printf("X\n");
    }
    for (int i = 0; i < 10; i++)
    {
        printf("X");
    }
    

    return 0;
}