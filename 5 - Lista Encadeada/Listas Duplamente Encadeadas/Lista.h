#ifndef __LISTA_H_
#define __LISTA_H_

typedef struct no {
    int dado;
    struct no *proximo;
    struct no *anterior;
} No;

typedef struct lista Lista;

Lista *criaLista();

void liberaLista(Lista *lista);

void insereInicioLista(Lista *lista, int elem);

void insereFimLista(Lista *lista, int elem);

void imprimeLista(Lista *lista);

int listaVazia(Lista *l);

int tamanhoLista(Lista *lista);

No *primeiroElementoLista(Lista *lista);

No *ultimoElementoLista(Lista *lista);

void removeLista(Lista *lista, int valor);

void imprimeReversoLista(Lista *lista);

#endif