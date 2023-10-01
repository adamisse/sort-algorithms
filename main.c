#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "callbackUtils.h"
#include "elementarySorts.h"
#include "mergeSort.h"
#include "quickSort.h"

void imprimeLista(int lista[], int n);
void imprimeListaStrings(char* strings[], int tamanho);
void ordenaComCallback();

int main(int argc, char** argv){
    int lista[10] = {9, 7, 5, 3, 1, 8, 6, 4, 2, 10};
    int arr_size = sizeof(lista) / sizeof(lista[0]);
    
    imprimeLista(lista, 10);

    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // selectionSort(lista, 10);
    // bubbleSort(lista, 10);
    //insertionSort(lista, 10);
    //improvedInsertionSort(lista, 10);
    
    //mergeSort(lista, 0, arr_size-1);
    //mergeInsertionSort(lista, 0, arr_size-1);
    mergeSkipSort(lista, 0, arr_size-1);
    //bottomUpMergeSort(lista, 0, arr_size-1);

    clock_gettime(CLOCK_MONOTONIC, &end_time);
    double execution_time = (end_time.tv_sec - start_time.tv_sec) +
                           (double)(end_time.tv_nsec - start_time.tv_nsec) / 1e9;

    // Imprimir o tempo de execução
    printf("Tempo de execução: %.9f segundos\n", execution_time);
    return 0;
}


void imprimeLista(int lista[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", lista[i]);
    }

    printf("\n");
}

void imprimeListaStrings(char* strings[], int tamanho){
    for(int i=0; i<tamanho; i++){
        printf("%s ", strings[i]);
    }

    printf("\n");
}

void ordenaComCallback(){
    // Exemplos de ordenações genéricas com função de callback

    int lista[10] = {9, 7, 5, 3, 1, 8, 6, 4, 2, 10};
    qsort(lista, sizeof(lista) / sizeof(lista[0]), sizeof(lista[0]), compareInt);
    imprimeLista(lista, 10);

    char *strings[] = {"maçã", "banana", "abacaxi", "uva", "laranja"};
    qsort(strings, sizeof(strings) / sizeof(strings[0]), sizeof(strings[0]), compareString);
    imprimeListaStrings(strings, 5);
}