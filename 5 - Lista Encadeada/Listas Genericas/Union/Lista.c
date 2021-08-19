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
        No* t = atual->proximo; /* guarda referência para o próximo elemento */
        free(atual);            /* libera a memória apontada por atual */
        atual = t;              /* faz atual apontar para o próximo */
    }
    free(lista);
    lista = NULL;
}

void insereInicioLista(Lista *lista, Tipo t, Objeto elem) {
    No *no = malloc(sizeof(No));
    no->tipo = t;
    no->objeto = elem;
    no->proximo = lista->inicio;
    if(lista->fim == NULL)
        lista->fim = no;
    lista->inicio = no;
    lista->n++;
}

void insereFimLista(Lista *lista, Tipo t, Objeto elem) {
    /* Insere um novo elemento no fim da lista
     *
     * Complexidade: O(1)
    */
    No *novo = malloc(sizeof(No));
    novo->tipo = t;
    novo->objeto = elem;
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

void imprimeNo(No *no) {
    if (no->tipo == RET) {
        printf("** Retangulo **\n");
        Retangulo r = no->objeto.r;
        printf("-   Base: %lf\n", r.b);
        printf("- Altura: %lf\n", r.h);
    }
    else if(no->tipo == TRI) {
        printf("** Triangulo **\n");
        Triangulo t = no->objeto.t;
        printf("-   Base: %lf\n", t.b);
        printf("- Altura: %lf\n", t.h);
    }
    else if (no->tipo == CIRC) {
        printf("** Circulo **\n");
        Circulo c = no->objeto.c;
        printf("- Raio: %lf\n", c.r);
    }
    else {
        printf("Objeto não reconhecido\n");
    }
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

