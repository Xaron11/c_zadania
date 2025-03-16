#include <stdio.h>
#include <stdlib.h>

#define MAX_INDENT 6

typedef void (*Formatter)(FILE*, int*, int);

void formatter_1(FILE* file_out, int* indents, int curr_indent) {
    for (int i = 1; i <= curr_indent; i++) {
        fprintf(file_out, "%d.", indents[i]);
    }
}

void formatter_a(FILE* file_out, int* indents, int curr_indent) {
    const char LETTER_INDENTS[] = {'A', '1', 'a', '1', 'a'};
    char base_l = LETTER_INDENTS[(curr_indent - 1) % 5];
    char count_l = indents[curr_indent];
    char letter = base_l + count_l - 1;
    if (curr_indent > 3) {
        fprintf(file_out, "(%c)", letter);
    } else {
        fprintf(file_out, "%c.", letter);
    }
}

Formatter select_formatter(char format) {
    if (format == '1') {
        return formatter_1;
    } else if (format == 'a') {
        return formatter_a;
    } else {
        printf("Niepoprawny format.\n");
        exit(1);
    }
}

void add_indent(FILE* file_out, int* indents, int curr_indent,
                Formatter formatter) {
    for (int i = 1; i < curr_indent; i++) {
        fprintf(file_out, "  ");
    }
    formatter(file_out, indents, curr_indent);
}

void create_indent(FILE* file_out, char format, int* indents, int curr_indent,
                   int last_indent) {
    indents[curr_indent]++;
    // wyzeruj wieksze wciecia
    if (curr_indent < last_indent) {
        for (int i = curr_indent + 1; i < MAX_INDENT; i++) {
            indents[i] = 0;
        }
    }
    // dodaj wciecie
    Formatter formatter = select_formatter(format);
    add_indent(file_out, indents, curr_indent, formatter);
}

void write_line(FILE* file_in, FILE* file_out, char ch) {
    fprintf(file_out, "%c", ch);
    while (fscanf(file_in, "%c", &ch) != EOF && ch != '\n') {
        fprintf(file_out, "%c", ch);
    }
    fprintf(file_out, "\n");
}

void convert_format(FILE* file_in, FILE* file_out, char format) {
    int indents[MAX_INDENT] = {0};

    int curr_indent = 0;
    int last_indent = 0;

    char ch;
    while (fscanf(file_in, "%c", &ch) != EOF) {
        if (ch == '*') {
            // gwiazdka, zwieksz wciecie
            curr_indent++;
        } else {
            // koniec gwiazdek
            create_indent(file_out, format, indents, curr_indent, last_indent);
            write_line(file_in, file_out, ch);
            last_indent = curr_indent;
            curr_indent = 0;
        }
    }
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
    char file_name[100];
    printf("Podaj nazwe pliku: ");
    scanf("%99s", file_name);

    FILE* file_in = fopen_check(file_name, "r");
    FILE* file_out = fopen_check("wynik.txt", "w");

    char format;
    printf("Podaj format (1 lub a): ");
    scanf(" %c", &format);

    convert_format(file_in, file_out, format);

    fclose(file_in);
    fclose(file_out);

    return 0;
}