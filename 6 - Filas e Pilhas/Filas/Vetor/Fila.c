#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"

struct fila {
    int capacidade; //Tamanho do array F
    int ini;        //Posicao do "primeiro" elemento
    int fim;        //Posição livre onde um elemento deve ser inserido
    int n;          //Número de elementos na estrutura
    int *F;         //Array para armazenar os elementos
};


Fila *criaFila(int capacidade) {
    /*Verifique se o valor em capacidade é válido */
    /*Se for, inicialize n, ini e fim com 0 (indicando que a estrutura está vazia) */
    /*Aloque o array 'F' e retorne o ponteiro da estrutura */
    Fila *fila = malloc(sizeof(Fila));
    fila->capacidade = capacidade;
    fila->ini = fila->fim = fila->n = 0;
    fila->F = malloc(sizeof(int)*capacidade);

    return fila;
}

void liberaFila(Fila *fila) {
    /* Faz a desalocação de memória */
    free(fila->F);
    free(fila);
}

void enqueue(Fila *fila, int v) {
    /* Adiciona um elemento no fim do vetor */
    /* Lembre-se de verificar se há espaço para adicionar o elemento */
    /* Complexidade: O(1)  */
    if(filaCheia(fila)) {
        printf("ERRO: Fila cheia!\n");
    }
    else {
        fila->F[fila->fim] = v;
        fila->fim = (fila->fim + 1) % fila->capacidade;
        fila->n++;
    }

}

void dequeue(Fila *fila) {
    /* Retira o primeiro elemento*/
    /* Complexidade: O(???)  */
    if (filaVazia(fila)) {
        printf("ERRO: Fila vazia!");
        return;
    }
    else {
        fila->ini = (fila->ini + 1) % fila->capacidade;
        fila->n--;
    }

}

int front(Fila *fila){
    /* Retorna o primeiro elemento */
    /* Complexidade: O(???)  */
    if (filaVazia(fila)) {
        printf("ERRO: Fila vazia!");
        return -1;
    }
    return fila->F[fila->ini];
}

bool filaVazia(Fila *fila) {
    /* Verifica se a estrutura está vazia */
    /* Complexidade: O(???)  */
    return fila->n == 0;
}

bool filaCheia(Fila *fila) {
    /* Verifica se a estrutura está cheia */
    /* Complexidade: O(1)  */
    return fila->n == fila->capacidade;
}

int tamanhoFila(Fila *fila) {
    /* Retorna o número de elementos que a estrutura armazena */
    /* Complexidade: O(1)  */

    return fila->n;
}
