#include <stdio.h>

#define MAX_TOWAROW 50

typedef struct Towar {
    char nazwa[20];
    int sztuk;
    float cena;
} Towar;

typedef struct TablicaTowarow {
    Towar towary[MAX_TOWAROW];
    int ilosc_towarow;
} TablicaTowarow;

char wczytaj_polecenie() {
    char polecenie;
    scanf(" %c", &polecenie);
    return polecenie;
}

void nowy_towar(TablicaTowarow* tablica_towarow) {
    Towar towar;
    printf("Podaj nazwe towaru: ");
    scanf("%s", towar.nazwa);
    printf("Podaj liczbe sztuk: ");
    scanf("%d", &towar.sztuk);
    printf("Podaj cene 1 sztuki: ");
    scanf("%f", &towar.cena);

    tablica_towarow->towary[tablica_towarow->ilosc_towarow] = towar;
    tablica_towarow->ilosc_towarow++;

    printf("Dodano nowy towar.\n");
}

void wyswietl_towary(TablicaTowarow* tablica_towarow) {
    if (tablica_towarow->ilosc_towarow == 0) {
        printf("Brak towarow.\n");
        return;
    }
    for (int i = 0; i < tablica_towarow->ilosc_towarow; i++) {
        printf("=== Towar %d ===\n", i);
        printf("Nazwa: %s\n", tablica_towarow->towary[i].nazwa);
        printf("Liczba sztuk: %d\n", tablica_towarow->towary[i].sztuk);
        printf("Cena 1 sztuki: %.2f\n", tablica_towarow->towary[i].cena);
    }
}

void oblicz_sume(TablicaTowarow* tablica_towarow) {
    float suma = 0;
    for (int i = 0; i < tablica_towarow->ilosc_towarow; i++) {
        suma +=
            tablica_towarow->towary[i].sztuk * tablica_towarow->towary[i].cena;
    }
    printf("Suma wartosci wszystkich towarow: %.2f\n", suma);
}

void instrukcja() {
    printf("Dostepne polecenia:\n");
    printf("N | n - Nowy towar\n");
    printf("W | w - Wyswietl wszystkie towary\n");
    printf("R | r - Oblicz sume wartosci wszystkich towarow\n");
    printf("H | h - Wyswietl pomoc\n");
    printf("Q | q - Zakoncz\n");
}

int main() {
    TablicaTowarow tablica_towarow = {0};

    instrukcja();

    while (1) {
        printf("Podaj polecenie: ");
        char p = wczytaj_polecenie();
        switch (p) {
            case 'N':
            case 'n':
                nowy_towar(&tablica_towarow);
                break;

            case 'W':
            case 'w':
                wyswietl_towary(&tablica_towarow);
                break;

            case 'R':
            case 'r':
                oblicz_sume(&tablica_towarow);
                break;

            case 'H':
            case 'h':
                instrukcja();
                break;

            case 'Q':
            case 'q':
                return 0;
        }
    }

    return 0;
}