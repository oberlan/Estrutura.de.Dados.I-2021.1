#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"

typedef struct no {
    int dado;
    struct no *proximo;
} No;

struct pilha {
    No *inicio;
    int n;
};

Pilha *criaPilha() {
    Pilha *p = malloc(sizeof(Pilha));
    p->inicio = NULL;
    p->n = 0;
    return p;
}

void liberaPilha(Pilha *pilha) {
    /* Faz a desalocação de memória */
    No *aux = pilha->inicio;
    while(aux) {
        No *t = aux->proximo;
        free(aux);
        aux = t;
    }
    free(pilha);
}

void push(Pilha *pilha, int v) {
    /* Adiciona um elemento na pilha */
    /* Complexidade: O(1)  */
    No *novo = malloc(sizeof(No));
    novo->dado = v;
    novo->proximo = pilha->inicio;
    pilha->inicio = novo;
    pilha->n++;
}

void pop(Pilha *pilha) {
    /* Retira o ultimo elemento*/
    /* Complexidade: O(1)  */
    if(pilhaVazia(pilha)) {
        printf("ERRO: Pilha Vazia!");
        return;
    }
    else {
        No *tmp = pilha->inicio;
        pilha->inicio = pilha->inicio->proximo;
        free(tmp);
        pilha->n--;
    }
}

int top(Pilha *pilha){
    /*Retorna o elemento ultimo */
    /* Complexidade: O(1)  */
    if(pilhaVazia(pilha)) {
        printf("ERRO: Pilha Vazia!");
        return -1;
    }
    return pilha->inicio->dado;
}

bool pilhaVazia(Pilha *pilha) {
    /* Verifica se a estrutura possui algum elemento ou está vazia */
    /* Complexidade: O(1)  */
    return pilha->n == 0;
}

bool pilhaCheia(Pilha *pilha) {
    /* Verifica se a estrutura está cheia */
    /* Complexidade: O(1)  */
    return false;
}

int tamanhoPilha(Pilha *pilha) {
    /* Retorna o número de elementos que a estrutura armazena */
    /* Complexidade: O(1)  */
    return pilha->n;

}
