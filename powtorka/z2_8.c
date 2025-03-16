#include <stdio.h>
#include <stdlib.h>

#define N 4

typedef enum Kod { AVG = 0, MIN = 1, MAX = 2 } Kod;

typedef struct SeriaPomiaru {
    int nr;
    double pomiary[N];
    Kod kod;
} SeriaPomiaru;

typedef struct WynikPomiaru {
    int nr;
    double wartosc;
    Kod kod;
} WynikPomiaru;

FILE* fopen_check(char* name, const char* mode) {
    FILE* file = fopen(name, mode);
    if (file == NULL) {
        printf("Nie udalo sie otworzyc pliku.\n");
        exit(1);
    }
    return file;
}

int main() {
    FILE* file_in = fopen_check("Pomiary.txt", "r");
    FILE* file_out = fopen_check("Wyniki.txt", "w");

    int nr;
    while (fscanf(file_in, "%d", &nr) != EOF) {
        SeriaPomiaru seria;
        seria.nr = nr;
        for (int i = 0; i < N; i++) {
            fscanf(file_in, "%lf", &seria.pomiary[i]);
        }
        int kod;
        fscanf(file_in, "%d", &kod);
        seria.kod = kod;

        WynikPomiaru wynik;
        wynik.nr = seria.nr;
        wynik.kod = seria.kod;

        switch (seria.kod) {
            case AVG:
                wynik.wartosc = 0;
                for (int i = 0; i < N; i++) {
                    wynik.wartosc += seria.pomiary[i];
                }
                wynik.wartosc /= N;
                break;
            case MIN:
                wynik.wartosc = seria.pomiary[0];
                for (int i = 1; i < N; i++) {
                    if (seria.pomiary[i] < wynik.wartosc) {
                        wynik.wartosc = seria.pomiary[i];
                    }
                }
                break;
            case MAX:
                wynik.wartosc = seria.pomiary[0];
                for (int i = 1; i < N; i++) {
                    if (seria.pomiary[i] > wynik.wartosc) {
                        wynik.wartosc = seria.pomiary[i];
                    }
                }
                break;
        }

        fprintf(file_out, "%d %g %d\n", wynik.nr, wynik.wartosc, wynik.kod);
    }

    fclose(file_in);
    return 0;
}