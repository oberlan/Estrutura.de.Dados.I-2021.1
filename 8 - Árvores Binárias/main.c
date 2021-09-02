#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq;
    struct no *dir;
}No;

No *criaNo(int v) {
    No *novo = malloc(sizeof(No));
    novo->dado = v;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void imprime(No *raiz) {
    if(raiz != NULL) {
        printf("%d\n", raiz->dado);
        imprime(raiz->esq);
        imprime(raiz->dir);
    }
}

void libera(No *raiz) {
    if (raiz) {
        libera(raiz->esq);
        libera(raiz->dir);
        free(raiz);
    }
}

int pertence (No *raiz, int x) {
    if (raiz == NULL)
        return 0; //false
    if (raiz->dado == x)
        return 1; //true
    if ( pertence(raiz->esq, x) )
        return 1;
    else
        return pertence(raiz->dir, x);
}

int main() {
    No *raiz = criaNo(1);
    raiz->esq = criaNo(2);
    raiz->dir = criaNo(3);
    raiz->esq->esq = criaNo(4);
    raiz->dir->dir = criaNo(5);
    raiz->dir->dir->esq = criaNo(10);
    raiz->dir->dir->dir = criaNo(11);

    imprime(raiz);

    if(pertence(raiz, -1))
        printf("Ok\n");

    libera(raiz);

    return 0;
}