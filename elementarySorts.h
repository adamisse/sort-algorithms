#ifndef ELEMENTARY_SORTS
#define ELEMENTARY_SORTS

// Selection Sort:
// Começa a varredura pelo primeiro elemento da lista;
// A varredura interna serve para encontrar a posicao do menor elemento da lista;
// Quando encontrado, troca o menor elemento da lista com o elemento iterado no for externo;
// O for interno sempre começa uma posicao apos o for interno, pois tudo à esquerda de i já está ordenado;
void selectionSort(int lista[], int n);

// Bubble Sort:
// Começa a varredura pelo primeiro elemento da lista;
// A varredura interna compara e troca elementos adjacentes se estiverem fora de ordem;
// O maior elemento da lista "sobe" gradualmente para a posição correta;
void bubbleSort(int lista[], int n);

// Insertion Sort:
// Começa a varredura pelo segundo elemento da lista;
// O elemento atual é comparado com os elementos à sua esquerda e inserido na posição correta;
void insertionSort(int lista[], int n);

void improvedInsertionSort(int lista[], int n);

#endif