#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Lista.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

struct lista {
    No *inicio;
    No *fim;
    int n;
};

Lista *criaLista() {
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio =  NULL;
    lista->fim = NULL;
    lista->n = 0;
    return lista;
}

void liberaLista(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* t = atual->proximo;
        liberaNo(atual);
        atual = t;
    }
    free(lista);
    lista = NULL;
}


void insereLista(Lista *lista, No *novo) {
    /* Insere um novo elemento no fim da lista
     *
     * Complexidade: O(1)
    */
    novo->proximo = NULL;
    if(listaVazia(lista)) {
        lista->inicio = lista->fim = novo;
    }
    else {
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
    lista->n++;
}

void imprimeLista(Lista *lista){
    No *atual = lista->inicio;
    while(atual != NULL){
    	imprimeNo(atual);
        atual = atual->proximo;
    }
    printf("\n\n");
}


int listaVazia(Lista *l){
    return (l->inicio == NULL);
}

int tamanhoLista(Lista *lista){
    /* Retorna o número de elementos da lista
     *
     * Complexidade: O(1)
    */
    return lista->n;
}

