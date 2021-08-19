#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"

struct pilha {
    int capacidade; //Número máximo de elementos que a pilha pode armazenar
    int t;          //Posição do topo da pilha
    int *P;         //Vetor com os elementos
};

Pilha *criaPilha(int capacidade) {
    /*Verifique se o valor em capacidade é válido */
    /*Se for, inicialize n com -1 (indicando que a estrutura está vazia) */
    /*Aloque o vetor 'P' e retorne o ponteiro da estrutura */
    Pilha *p = malloc(sizeof(Pilha));
    p->capacidade = capacidade;
    p->t = -1;
    p->P = malloc(capacidade*sizeof(int));
    return p;
}

void liberaPilha(Pilha *pilha) {
    /* Faz a desalocação de memória */
    if(pilha) {
        if(pilha->P) free(pilha->P);
        free(pilha);
    }
}

void push(Pilha *pilha, int v) {
    /* Adiciona um elemento no fim do vetor */
    /* Lembre-se de verificar se há espaço para adicionar o elemento */
    /* Complexidade: O(1)  */
    if (pilha->t < pilha->capacidade - 1) {
        pilha->t++;
        pilha->P[pilha->t] = v;
    }
    else {
        printf("ERRO: Pilha cheia!\n");
    }
}

void pop(Pilha *pilha) {
    /* Retira o ultimo elemento*/
    /* Complexidade: O(1)  */
    if(pilhaVazia(pilha)) {
        printf("ERRO: Pilha Vazia!");
    }
    else 
        pilha->t--;
}

int top(Pilha *pilha){
    /*Retorna o elemento ultimo */
    /* Complexidade: O(1)  */
    if(pilhaVazia(pilha)) {
        printf("ERRO: Pilha Vazia!");
        return -1;
    }
    return pilha->P[pilha->t];
}

bool pilhaVazia(Pilha *pilha) {
    /* Verifica se a estrutura possui algum elemento ou está vazia */
    /* Complexidade: O(1)  */
    return pilha->t == -1;
}

bool pilhaCheia(Pilha *pilha) {
    /* Verifica se a estrutura está cheia */
    /* Complexidade: O(1)  */
    return pilha->t == pilha->capacidade;
}

int tamanhoPilha(Pilha *pilha) {
    /* Retorna o número de elementos que a estrutura armazena */
    /* Complexidade: O(1)  */
    return pilha->t + 1;
    
}
