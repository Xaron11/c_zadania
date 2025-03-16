#include <stdio.h>

int main() {
    char znak;
    char nazwa_pliku[100];
    printf("Podaj znak do zliczania wystapien: ");
    scanf("%c", &znak);
    printf("Podaj nazwe pliku: ");
    scanf("%s", nazwa_pliku);

    FILE* plik = fopen(nazwa_pliku, "r");
    if (plik == NULL) {
        printf("Nie udalo sie otworzyc pliku.\n");
        return 1;
    }

    int wystapienia = 0;

    char c;
    while ((c = fgetc(plik)) != EOF) {
        if (c == znak) {
            wystapienia++;
        }
    }

    printf("Znak '%c' wystapil %d razy.\n", znak, wystapienia);

    fclose(plik);

    return 0;
}