#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *proximo;
}No;

typedef struct lista {
    No *inicio;
    //No *fim;
    //long tamanho;
}Lista;

Lista *criaLista() {
    Lista *l = malloc(sizeof(Lista));
    l->inicio = NULL;
    //l->fim = NULL;
    //l->tamanho = 0;
    return l;
}

void insereInicioLista(Lista *l, int valor) {
    //Complexidade: O(1)
    No *no = malloc(sizeof(No));
    no->dado = valor;
    no->proximo = l->inicio;
    //if(vaziaLista(l))
    //    l->fim = no;
    l->inicio = no;
    //l->tamanho++;
}

int listaVazia(Lista *l){
    return l->inicio == NULL;
}

void insereFimLista(Lista *l, int valor) {
    //Complexidade: O(n)
    No *no = malloc(sizeof(No));
    no->dado = valor;
    no->proximo = NULL;
    No *aux = l->inicio;
    if(listaVazia(l)) {
        l->inicio = no;
    }
    else {
        while(aux->proximo) {
            aux = aux->proximo;
        }
        aux->proximo = no;
    }
}

void imprimeLista(Lista *l) {
    // No *atual = l->inicio;
    // while (atual != NULL) { // while (atual)
    //     printf("%d\n", atual->dado);
    //     atual = atual->proximo;
    // }
    No *atual = l->inicio;
    while(atual != NULL){
    	printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

void liberaLista(Lista *l) {
    No *atual = l->inicio;
    while (atual != NULL) {
        No *tmp = atual->proximo;
        free(atual);
        atual = tmp;
    }
    free(l);
    l = NULL;
}



int tamanhoLista(Lista *l) {
    //Complexidade: O(1)
    //return l->tamanho;


    //Complexidade: O(n)
    int t = 0;
    No *aux = l->inicio;
    while(aux != NULL) {
        t++;
        aux = aux->proximo;
    }
    return t;
}

No *primeiroElementoLista(Lista *l) {
    //Complexidade: O(1)
    return l->inicio;
}

No *ultimoElementoLista(Lista *l) {
    //Complexidade: O(1)
    //return l->fim;

    //Complexidade: O(n)
    if(listaVazia(l)) return NULL;
    No *aux = l->inicio;
    while(aux->proximo /*!= NULL*/){
        aux = aux->proximo;
    }
    return aux;
}

No *anteriorNoLista(Lista *l, No *no){
    //Complexidade: O(n)
    if(listaVazia(l)) return NULL;
    No *aux = l->inicio;
    No *anterior = NULL;
    while(aux != no) {
        anterior = aux;
        aux = aux->proximo;
    }

    return anterior;
}

No* procuraLista(Lista *l, int valor) {
    //Complexidade: O(??)
    for(No *aux = l->inicio; aux != NULL; aux = aux->proximo) {
         if(aux->dado == valor)
            return aux;
    }
    return NULL;
    /*
    if(listaVazia(l)) return NULL;
    No *aux = l->inicio;
    while(aux != NULL) {
        if(aux->dado == valor)
            return aux;
        aux = aux->proximo;
    }
    return aux;
    */
}

void removeElementoLista(Lista *lista, int valor) {
    /* Remove os nós tal que no->dado == valor
     *
     * Complexidade: O(n)
     */
    if(listaVazia(lista)) return;

    No *aux = lista->inicio;
    No *anterior = NULL;
    while(aux != NULL) {
        if(aux->dado == valor) {
            if(aux == lista->inicio) { //Primeiro nó
                lista->inicio = lista->inicio->proximo; // aux->proximo;
                free(aux);
                aux = lista->inicio;
            }
            else if (aux->proximo == NULL) { //Ultimo nó
                anterior->proximo = NULL;
                free(aux);
                aux = NULL;
            }
            else { //No meio da lista
                anterior->proximo = aux->proximo;
                free(aux);
                aux = anterior->proximo;
            }
        }
        else {
            anterior = aux;
            aux = aux->proximo;
        }
    }
}

int ehPar(int x) {
    return x%2 == 0;
}
int ehImpar(int x) {
    return x%2 != 0;
}

int maior5(int x) {
    return x >= 5;
}

void imprimeSeLista(Lista *l, int (*compara)(int) ){
    No *atual = l->inicio;
    while(atual != NULL){
        if(compara(atual->dado))
    	    printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int main() {
    Lista *l = criaLista();
    insereFimLista(l, 2);
    insereFimLista(l, 3);
    insereFimLista(l, 3);
    insereFimLista(l, 3);
    insereFimLista(l, 5);
    insereFimLista(l, 7);
    imprimeSeLista(l, ehPar);
    imprimeSeLista(l, ehImpar);
    imprimeSeLista(l, maior5);

    /*
    insereInicioLista(l, 2);
    insereInicioLista(l, 3);
    insereInicioLista(l, 5);
    insereInicioLista(l, 7);
    */

    imprimeLista(l);
    printf("%d\n", tamanhoLista(l));

    insereInicioLista(l, 11);
    insereFimLista(l, 13);
    imprimeLista(l);
    printf("%d\n", tamanhoLista(l));

    No *n = ultimoElementoLista(l);
    printf("%d\n", n->dado);

    n = anteriorNoLista(l, ultimoElementoLista(l));
    printf("%d\n", n->dado);

    Lista *l1 = criaLista();

    n = procuraLista(l1, 13);
    if(n)
        printf("Está na lista\n");
    else
        printf("Não está na lista\n");

    imprimeLista(l);
    removeElementoLista(l, 3);
    imprimeLista(l);

    removeElementoLista(l, 11);
    imprimeLista(l);

    removeElementoLista(l, 13);
    imprimeLista(l);

    removeElementoLista(l, 5);
    imprimeLista(l);

    removeElementoLista(l, 7);
    imprimeLista(l);

    removeElementoLista(l, 2);
    imprimeLista(l);

    // No *n1 = malloc(sizeof(No));
    // n1->dado = 13;
    // n1->proximo = NULL;
    // n = anteriorNoLista(l, n1);
    // printf("%d\n", n->dado);

    liberaLista(l);
    liberaLista(l1);
    return 0;
}