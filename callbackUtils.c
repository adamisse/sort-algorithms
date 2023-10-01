#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define um tipo de função de comparação genérica.
typedef int (*Comparator)(const void *a, const void *b);

// Função de comparação para números inteiros.
int compareInt(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Função de comparação para strings.
int compareString(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}