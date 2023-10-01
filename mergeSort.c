#include <stdio.h>
#include <stdlib.h>
#include "elementarySorts.h"

#define MERGE_CUTOFF 7

void merge(int listaPrincipal[], int listaAuxiliar[], int lo, int mid, int hi){
    for(int k = lo; k<=hi; k++){
        listaAuxiliar[k] = listaPrincipal[k];
    }

    int i = lo, j = mid+1;

    for(int k = lo; k <= hi; k++){
        if(i>mid)       listaPrincipal[k] = listaAuxiliar[j++];
        else if(j>hi)   listaPrincipal[k] = listaAuxiliar[i++];
        else if(listaAuxiliar[j] < listaAuxiliar[i]) listaPrincipal[k] = listaAuxiliar[j++];
        else listaPrincipal[k] = listaAuxiliar[i++];
    }
}

void mergeSortClassical(int listaPrincipal[], int listaAuxiliar[], int lo, int hi){
    if(hi <= lo) return;
    int mid = lo + (hi - lo) / 2;

    mergeSortClassical(listaPrincipal, listaAuxiliar, lo, mid);
    mergeSortClassical(listaPrincipal, listaAuxiliar, mid+1, hi);
    merge(listaPrincipal, listaAuxiliar, lo, mid, hi);
}

void mergeSortWInsertionSortCuttof(int listaPrincipal[], int listaAuxiliar[], int lo, int hi){
    if (hi <= lo + MERGE_CUTOFF - 1) {
        insertionSort(listaPrincipal, hi+1);
        return;
    }

    int mid = lo + (hi - lo) / 2;
    mergeSortWInsertionSortCuttof(listaPrincipal, listaAuxiliar, lo, mid);
    mergeSortWInsertionSortCuttof(listaPrincipal, listaAuxiliar, mid+1, hi);
    merge(listaPrincipal, listaAuxiliar, lo, mid, hi);
}

void mergeInsertionSort(int listaPrincipal[], int lo, int hi){    
    printf("== MERGE SORT w/ CUTOFF == \n");
    int n = (hi - lo) + 1;
    int *listaAuxiliar = malloc(n * sizeof(int));

    mergeSortWInsertionSortCuttof(listaPrincipal, listaAuxiliar, lo, hi);

    free(listaAuxiliar);
    imprimeLista(listaPrincipal, hi + 1);
}

void mergeSortWMergeSkip(int listaPrincipal[], int listaAuxiliar[], int lo, int hi){
    if(hi <= lo) return;
    
    int mid = lo + (hi - lo) / 2;
    mergeSortWMergeSkip(listaPrincipal, listaAuxiliar, lo, mid);
    mergeSortWMergeSkip(listaPrincipal, listaAuxiliar, mid+1, hi);
    if (listaPrincipal[mid] <= listaPrincipal[mid+1]) return;
    merge(listaPrincipal, listaAuxiliar, lo, mid, hi);
}

void mergeSkipSort(int listaPrincipal[], int lo, int hi){    
    printf("== MERGE SORT w/ EARLY SKIP == \n");
    int n = (hi - lo) + 1;
    int *listaAuxiliar = malloc(n * sizeof(int));

    mergeSortWMergeSkip(listaPrincipal, listaAuxiliar, lo, hi);

    free(listaAuxiliar);
    imprimeLista(listaPrincipal, hi + 1);
}

void mergeSort(int listaPrincipal[], int lo, int hi){
    printf("== MERGE SORT == \n");
    
    int n = (hi - lo) + 1;
    int *listaAuxiliar = malloc(n * sizeof(int));

    mergeSortClassical(listaPrincipal, listaAuxiliar, lo, hi);

    free(listaAuxiliar);
    imprimeLista(listaPrincipal, hi + 1);
}

void bottomUpMergeSort(int listaPrincipal[], int lo, int hi){
    printf("== BOTTOM UP MERGE SORT == \n");

    int N = (hi - lo) + 1;
    int y = N - 1;
    int *aux = malloc(N * sizeof(int));
    
    for (int sz = 1; sz < N; sz = (sz+sz)) {
        for (int lo = 0; lo < N-sz; lo += (sz+sz)) {
            int x = lo + sz+sz - 1;
            merge(listaPrincipal, aux, lo, lo+sz-1, ((x < y) ? (x) : (y)));
        }
    }
    
    free(aux);
    imprimeLista(listaPrincipal, hi + 1);
}          