#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *proximo;
}No;

typedef struct lista {
    No *primeiro;
}Lista;

Lista *criaLista() {
    Lista *l = malloc(sizeof(Lista));
    l->primeiro = NULL;
    return l;
}

void insere(Lista *l, int valor) {
    //Complexidade: O(1)

    //Alocar o no
    No *no = malloc(sizeof(No));
    //Modificar o campo 'dado' do 'no'
    no->dado = valor;
    //Campo 'proximo' do no aponta para NULL
    no->proximo = l->primeiro;
    //'l->primeiro' aponta para o novo nó
    l->primeiro = no;
}

void imprimeLista(Lista *l) {
    No *atual = l->primeiro;
    while (atual != NULL) { // while (atual)
        printf("%d\n", atual->dado);
        atual = atual->proximo;
    }
}

void liberaLista(Lista *l) {
    No *atual = l->primeiro;
    while (atual != NULL) {
        No *tmp = atual->proximo;
        free(atual);
        atual = tmp;
    }
    free(l);
    l = NULL;
}

int vazia(Lista *l){
    return l->primeiro == NULL;
}

int main() {
    Lista *l = criaLista();
    insere(l, 2);
    insere(l, 3);
    insere(l, 5);
    insere(l, 7);

    imprimeLista(l);

    liberaLista(l);

    return 0;
}