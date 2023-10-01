#ifndef MERGE_SORT
#define MERGE_SORT

void mergeSort(int lista[], int lo, int hi);
void mergeSortClassical(int lista[], int listaAuxiliar[], int lo, int hi);

void mergeInsertionSort(int listaPrincipal[], int lo, int hi);
void mergeSortWInsertionSortCuttof(int lista[], int listaAuxiliar[], int lo, int hi);

void mergeSkipSort(int listaPrincipal[], int lo, int hi); 
void mergeSortWMergeSkip(int lista[], int listaAuxiliar[], int lo, int hi);

void merge(int lista[], int listaAuxiliar[], int lo, int mid, int hi);

#endif