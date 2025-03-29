#include <stdio.h>
#include <stdlib.h>

FILE* fopen_check(char* name, const char* mode) {
    FILE* file = fopen(name, mode);
    if (file == NULL) {
        printf("Nie udalo sie otworzyc pliku.\n");
        exit(1);
    }
    return file;
}

int main() {
    char file_in_name[100], file_out_name[100];
    printf("Podaj nazwe pliku wejsciowego: ");
    scanf("%99s", file_in_name);
    printf("Podaj nazwe pliku wyjsciowego: ");
    scanf("%99s", file_out_name);

    FILE* file_in = fopen_check(file_in_name, "r");
    FILE* file_out = fopen_check(file_out_name, "w");

    int n = 1;

    while (1) {
        char c = fgetc(file_in);
        if (c == '\n' || c == EOF) {
            break;
        }
        if (c == ' ') {
            n++;
        }
    }

    rewind(file_in);
    int* columns = malloc(n * sizeof(int));

    int col = 0;
    int line = 1;
    while (1) {
        char c = fgetc(file_in);
        if (c == EOF) {
            break;
        } else if (c == '\n') {
            line++;
            col = 0;
        } else if (c == ' ') {
            continue;
        } else {
            ungetc(c, file_in);
            int num = 0;
            fscanf(file_in, "%d", &num);
            columns[col] += num;
            col++;
        }
    }

    fprintf(file_out, "Suma:");
    for (int j = 0; j < n; j++) {
        fprintf(file_out, " %d", columns[j]);
    }
    fprintf(file_out, "\n");
    fprintf(file_out, "Srednia:");
    for (int j = 0; j < n; j++) {
        fprintf(file_out, " %g", (float)columns[j] / line);
    }

    fprintf(file_out, "\n");

    fclose(file_in);
    fclose(file_out);
    free(columns);

    return 0;
}