#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

struct lista {
    No *inicio;
    No *fim;
    int n;
};

Lista *criaLista() {
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio = lista->fim = NULL;
    lista->n = 0;
    return lista;
}

void liberaLista(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* t = atual->proximo;
        free(atual);
        atual = t;
    }
    free(lista);
    lista = NULL;
}

void insereInicioLista(Lista *lista, int elem) {
    /* Complexidade: O(1) */
    No *no = malloc(sizeof(No));
    no->dado = elem;
    no->anterior = NULL;
    no->proximo = lista->inicio;
    if (listaVazia(lista))
        lista->fim = no;
    else
        lista->inicio->anterior = no;
    lista->inicio = no;
    lista->n++;
}

void insereFimLista(Lista *lista, int elem) {
    /* Insere um novo elemento no fim da lista
     *
     * Complexidade: O(1)
    */
    No *no = malloc(sizeof(No));
    no->dado = elem;
    no->proximo = NULL;
    no->anterior = lista->fim;
    if (listaVazia(lista))
        lista->inicio = no;
    else
        lista->fim->proximo = no;

    lista->fim = no;
    lista->n++;
}

int tamanhoLista(Lista *lista){
    /* Retorna o número de elementos da lista
     *
     * Complexidade: O(n)
    */
    return lista->n;
}



No* primeiroElementoLista(Lista *lista) {
    /* Retorna uma referência para o primeiro no da lista
     *
     * Complexidade: O(1)
    */
    return lista->inicio;
}

No* ultimoElementoLista(Lista *lista) {
    /* Retorna uma referência para o último no da lista
     *
     * Complexidade: O(1)
    */
    return lista->fim;
}

No* procuraLista(Lista *lista, int valor){
    /* Retorna uma referência para o nó tal que no->dado == valor
     *
     * Complexidade: O(n)
    */
    for (No *p = lista->inicio; p != NULL; p = p->proximo)
        if (p->dado == valor)
            return p;
    return NULL;
}

void removeLista(Lista *lista, int valor) {
    //Compexidade O(n)
    //1 2 3 4
    //removeLista(lista, 2) -> 1 3 4

    if(listaVazia(lista)) return;

    //No *p = procuraLista(lista, valor);
    No *p = lista->inicio;
    while(p != NULL) {
        No *tmp = p->proximo;
        if(p->dado == valor) {
            if (p == lista->inicio)
                lista->inicio = p->proximo; // lista->inicio = lista->inicio->proximo;
            else
                p->anterior->proximo = p->proximo;

            if (p == lista->fim)
                lista->fim = p->anterior; // lista->fim = lista->fim->anterior;
            else
                p->proximo->anterior = p->anterior;

            free(p);
            lista->n--;
        }
        p = tmp;//procuraLista(lista, valor); //O(n)
    }

    //O(n²)
}

void imprimeLista(Lista *lista) {
    No *atual = lista->inicio;
    while(atual != NULL){
    	printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int listaVazia(Lista *l){
    return (l->inicio == NULL);
}

void imprimeReversoLista(Lista *lista) {
    No *atual = lista->fim;
    while(atual != NULL){
    	printf("%d -> ", atual->dado);
        atual = atual->anterior;
    }
    printf("NULL\n");
}