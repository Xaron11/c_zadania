#include <stdio.h>
#include <stdlib.h>

#define N 4

typedef enum Kod { AVG = 0, MAX = 1, MIN = 2 } Kod;

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

typedef WynikPomiaru (*FunkcjaPrzetwarzania)(SeriaPomiaru*);

WynikPomiaru avg(SeriaPomiaru* seria) {
    WynikPomiaru wynik;
    wynik.nr = seria->nr;
    wynik.kod = seria->kod;
    wynik.wartosc = 0;
    for (int i = 0; i < N; i++) {
        wynik.wartosc += seria->pomiary[i];
    }
    wynik.wartosc /= N;
    return wynik;
}

WynikPomiaru min(SeriaPomiaru* seria) {
    WynikPomiaru wynik;
    wynik.nr = seria->nr;
    wynik.kod = seria->kod;
    wynik.wartosc = seria->pomiary[0];
    for (int i = 1; i < N; i++) {
        if (seria->pomiary[i] < wynik.wartosc) {
            wynik.wartosc = seria->pomiary[i];
        }
    }
    return wynik;
}

WynikPomiaru max(SeriaPomiaru* seria) {
    WynikPomiaru wynik;
    wynik.nr = seria->nr;
    wynik.kod = seria->kod;
    wynik.wartosc = seria->pomiary[0];
    for (int i = 1; i < N; i++) {
        if (seria->pomiary[i] > wynik.wartosc) {
            wynik.wartosc = seria->pomiary[i];
        }
    }
    return wynik;
}

FILE* fopen_check(char* name, const char* mode) {
    FILE* file = fopen(name, mode);
    if (file == NULL) {
        printf("Nie udalo sie otworzyc pliku.\n");
        exit(1);
    }
    return file;
}

void read_series(FILE* file_in, SeriaPomiaru* seria) {
    for (int i = 0; i < N; i++) {
        fscanf(file_in, "%lf", &seria->pomiary[i]);
    }
    int kod;
    fscanf(file_in, "%d", &kod);
    if (kod < 0 || kod > 2) {
        printf("Nieprawidłowy kod: %d\n", kod);
        exit(1);
    }
    seria->kod = kod;
}

void calculate(FILE* file_out, SeriaPomiaru* seria,
               FunkcjaPrzetwarzania* funkcje) {
    FunkcjaPrzetwarzania funkcja = funkcje[seria->kod];
    WynikPomiaru wynik = funkcja(seria);
    fprintf(file_out, "%d %g %d\n", wynik.nr, wynik.wartosc, wynik.kod);
}

int main() {
    FILE* file_in = fopen_check("Pomiary.txt", "r");
    FILE* file_out = fopen_check("Wyniki.txt", "w");
    FunkcjaPrzetwarzania funkcje[3] = {avg, max, min};

    int nr;
    while (fscanf(file_in, "%d", &nr) != EOF) {
        SeriaPomiaru seria;
        seria.nr = nr;
        read_series(file_in, &seria);
        calculate(file_out, &seria, funkcje);
    }

    fclose(file_in);
    fclose(file_out);
    return 0;
}