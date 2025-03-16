#include <stdio.h>
#include <stdlib.h>

typedef struct d2_array {
    int** arr;
    int lines;
    int columns;
} d2_array;

d2_array* d2_array_create(int lines, int columns) {
    d2_array* arr = (d2_array*)malloc(sizeof(d2_array));
    arr->lines = lines;
    arr->columns = columns;
    arr->arr = (int**)malloc(lines * sizeof(int*));
    for (int i = 0; i < lines; i++) {
        arr->arr[i] = (int*)malloc(columns * sizeof(int));
    }
    return arr;
}

void d2_array_load(d2_array* arr, FILE* file) {
    for (int i = 0; i < arr->lines; i++) {
        for (int j = 0; j < arr->columns; j++) {
            fscanf(file, "%d", &arr->arr[i][j]);
        }
    }
}

void d2_array_free(d2_array* arr) {
    for (int i = 0; i < arr->lines; i++) {
        free(arr->arr[i]);
    }
    free(arr->arr);
    free(arr);
}

int d2_array_sum_column(d2_array* arr, int column) {
    int sum = 0;
    for (int i = 0; i < arr->lines; i++) {
        sum += arr->arr[i][column];
    }
    return sum;
}

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

    int lines = 1;
    int columns = 1;
    char ch;
    while (fscanf(file_in, "%c", &ch) != EOF) {
        if (ch == '\n') {
            lines++;
            columns = 1;
        } else if (ch == ' ') {
            columns++;
        }
    }
    rewind(file_in);

    d2_array* arr = d2_array_create(lines, columns);

    d2_array_load(arr, file_in);

    fprintf(file_out, "Suma:");
    for (int i = 0; i < arr->columns; i++) {
        fprintf(file_out, " %d", d2_array_sum_column(arr, i));
    }
    fprintf(file_out, "\n");
    fprintf(file_out, "Srednia:");
    for (int i = 0; i < arr->columns; i++) {
        fprintf(file_out, " %g",
                (float)d2_array_sum_column(arr, i) / arr->lines);
    }
    fprintf(file_out, "\n");

    d2_array_free(arr);

    fclose(file_in);
    fclose(file_out);
    return 0;
}