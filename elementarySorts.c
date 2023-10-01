#include <stdio.h>
#include <stdlib.h>

// Algoritmos elementares

void selectionSort(int lista[], int n){
    printf("== SELECTION SORT ==\n");
    // Loop externo para percorrer a lista a partir do primeiro elemento até o penúltimo.
    for(int i = 0; i < n - 1; i++){
        // Inicializa o índice do menor elemento como o índice atual (i).
        int indiceMenorElemento = i;

        // Loop interno para encontrar o índice do menor elemento na parte não ordenada da lista.
        for(int j = i + 1; j < n; j++){
            // Verifica se o valor atual é menor que o menor elemento encontrado até agora.
            if(lista[j] < lista[indiceMenorElemento]){
                // Se sim, atualiza o índice do menor elemento para o índice atual (j).
                indiceMenorElemento = j;
            }
        }

        // Troca o menor elemento encontrado com o elemento atual (i) na lista.
        if(lista[i] > lista[indiceMenorElemento]){
            int aux = lista[i];
            lista[i] = lista[indiceMenorElemento];
            lista[indiceMenorElemento] = aux;
        }
    }

    // Imprime a lista ordenada.
    imprimeLista(lista, 10);
}

void bubbleSort(int lista[], int n){
    printf("== BUBBLE SORT ==\n");

    // Loop externo para percorrer a lista da esquerda para a direita.
    for(int i = 0; i < n - 1; i++){
        // Loop interno para comparar e trocar elementos adjacentes.
        for(int j = 0; j < n - 1; j++){
            // Verifica se o elemento atual é maior que o próximo elemento.
            if(lista[j] > lista[j+1]){
                // Se sim, troca os elementos de posição.
                int aux = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = aux;
            }
        }
    }

    // Imprime a lista ordenada.
    imprimeLista(lista, n);
}

void insertionSort(int lista[], int n){
    printf("== INSERTION SORT ==\n");

    int operacoesTroca = 0;

    // Loop externo para percorrer a lista da esquerda para a direita.
    for (int i = 1; i < n; i++) {
        int elementoMovido = lista[i];
        int j = i - 1;

        // Move os elementos do arr[0..i-1] que são maiores que o elemento a ser movido
        // para uma posição à frente de sua posição atual
        while (j >= 0 && lista[j] > elementoMovido) {
            lista[j + 1] = lista[j];
            j = j - 1;
            operacoesTroca++;
        }
        lista[j + 1] = elementoMovido;
    }

    // Imprime a lista ordenada.
    imprimeLista(lista, n);
}

void improvedInsertionSort(int lista[], int n){
    printf("== INSERTION SORT COM SENTINELA ==\n");

    int operacoesTroca = 0;

    // Adiciona o menor elemento no início do array
    for (int i = n-1; i > 0; i--){
        if(lista[i] < lista[i-1]){
            int aux = lista[i];
            lista[i] = lista[i-1];
            lista[i-1] = aux;
        }
    }
    //imprimeLista(lista, 10);
    //printf("menor valor: %d\n", lista[0]);

    // Loop externo para percorrer a lista da esquerda para a direita.
    for ( int i = 2; i < n; i++) {
        int j=i;
        int elementoMovido = lista[i];

        // Move os elementos do arr[0..i-1] que são maiores que o elemento a ser movido
        // para uma posição à frente de sua posição atual.
        // Note que o loop agora vai até 0 em vez de 1.
        while (lista[j - 1] > elementoMovido) {
            lista[j] = lista[j - 1];
            operacoesTroca++;
            j--;
        }

        // Insere o elemento na posição correta.
        lista[j] = elementoMovido;
    }

    // Imprime a lista ordenada.
    imprimeLista(lista, n);
}
