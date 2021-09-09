#include <stdio.h>
#include <stdlib.h>

typedef enum {
    false,
    true
}bool;

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

void padding( char ch, int n ){
  for (int i = 0; i < n; i++ )
    putchar(ch);
}

void imprimeArvore ( No *root, int nivel ){
  if ( root == NULL ) {
    padding('\t', nivel );
    puts("~");
  } else {
    imprimeArvore ( root->dir, nivel + 1 );
    padding('\t', nivel );
    printf("%d\n", root->dado );
    imprimeArvore ( root->esq, nivel + 1 );
  }
}

void libera(No *raiz) {
    if (raiz) {
        libera(raiz->esq);
        libera(raiz->dir);
        free(raiz);
    }
}

int altura(No *r) {
    if(r == NULL)
        return -1;
    int hSAE = altura(r->esq);
    int hSAD = altura(r->dir);
    if (hSAE > hSAD)
        return hSAE + 1;
    else
        return hSAD + 1;
}
int numeroDeNos(No *raiz) {
    if(raiz == NULL)
        return 0;
    return numeroDeNos(raiz->esq) + numeroDeNos(raiz->dir) + 1;
}

No* busca(No* r, int chave) {
    if(r == NULL || r->dado == chave)
        return r;
    if(r->dado < chave)
        return busca(r->dir, chave);
    else
        return busca(r->esq, chave);
}

// No *insereNo(No *raiz, No *novo){
//     if(raiz == NULL)
//         return novo;

//     No *pai = NULL;
//     No *atual = raiz;
//     while(atual != NULL) {
//         pai = atual;
//         if (atual->dado > novo->dado)
//             atual = atual->esq;
//         else
//             atual = atual->dir;
//     }
//     if(pai->dado > novo->dado)
//         pai->esq = novo;
//     else
//         pai->dir = novo;

//     return raiz;
// }

No *insereNo(No *raiz, No *novo){
    if(raiz == NULL)
        return novo;
    if (raiz->dado > novo->dado)
        raiz->esq = insereNo(raiz->esq, novo);
    else
        raiz->dir = insereNo(raiz->dir, novo);
    return raiz;
}

No *removeNo(No *raiz, int chave) {
    No *pai = NULL;
    No *atual = raiz;
    while(atual != NULL && atual->dado != chave ) {
        pai = atual;
        if (atual->dado > chave)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    if(atual == NULL) {
        printf("Chave não encontrada\n");
        return raiz;
    }
    /* Nó é uma folha */
    if (atual->esq == NULL && atual->dir == NULL) {
        if(atual != raiz) { // pai != NULL
            if(pai->esq == atual)
                pai->esq = NULL;
            else
                pai->dir = NULL;
        }
        else {
            raiz = NULL;
        }
        free(atual);
    }
    /* Nó tem um único filho à esquerda */
    else if(atual->dir == NULL) {
        if(atual != raiz) { // pai != NULL
            if(pai->esq == atual)
                pai->esq = atual->esq;
            else
                pai->dir = atual->esq;
        }
        else {
            raiz = atual->esq;
        }
        free(atual);
    }
    /* Nó tem um único filho à direita */
    else if(atual->esq == NULL) {
        if(atual != raiz) { // pai != NULL
            if(pai->esq == atual)
                pai->esq = atual->dir;
            else
                pai->dir = atual->dir;
        }
        else {
            raiz = atual->dir;
        }
        free(atual);
    }
    /* Nó tem dois filhos */
    else {
        No *t = atual->esq;
        pai = NULL;
        while(t->dir) {
            pai = t;
            t = t->dir;
        }
        if(pai != NULL)
            pai->dir = t->esq;
        else
            atual->esq = t->esq;
        atual->dado = t->dado;
        free(t);
    }
    return raiz;
}

int main() {
    No *raiz = NULL;
    // raiz = insereNo(raiz, criaNo(8));
    // raiz = insereNo(raiz, criaNo(3));
    // raiz = insereNo(raiz, criaNo(10));
    // raiz = insereNo(raiz, criaNo(1));
    // raiz = insereNo(raiz, criaNo(6));
    // raiz = insereNo(raiz, criaNo(4));
    // raiz = insereNo(raiz, criaNo(7));
    // raiz = insereNo(raiz, criaNo(14));
    // raiz = insereNo(raiz, criaNo(13));
    // raiz = insereNo(raiz, criaNo(0));
    // raiz = insereNo(raiz, criaNo(100));
    // raiz = insereNo(raiz, criaNo(2));
    // raiz = insereNo(raiz, criaNo(-2));
    raiz = insereNo(raiz, criaNo(5));
    raiz = insereNo(raiz, criaNo(3));
    raiz = insereNo(raiz, criaNo(7));
    raiz = insereNo(raiz, criaNo(1));
    raiz = insereNo(raiz, criaNo(2));
    raiz = insereNo(raiz, criaNo(4));
    raiz = insereNo(raiz, criaNo(6));
    raiz = insereNo(raiz, criaNo(8));

    raiz = removeNo(raiz, 7);
    raiz = removeNo(raiz, 8);
    raiz = removeNo(raiz, 3);
    raiz = removeNo(raiz, 5);
    raiz = removeNo(raiz, 1);
    raiz = removeNo(raiz, 4);
    imprimeArvore(raiz, 0);

    // raiz->esq = criaNo(3);
    // raiz->dir = criaNo(10);
    // raiz->esq->esq = criaNo(1);
    // raiz->esq->dir = criaNo(6);
    // raiz->esq->dir->esq = criaNo(4);
    // raiz->esq->dir->dir = criaNo(7);
    // raiz->dir->dir = criaNo(14);
    // raiz->dir->dir->esq = criaNo(13);

    //imprimeArvore(raiz, 0);
    printf("Altura: %d\n", altura(raiz));
    printf("  #Nos: %d\n", numeroDeNos(raiz));
    // int chave = 8;
    // No *no = busca(raiz, chave);
    // if(no)
    //     printf("%d? %d\n", chave, no->dado);
    // else
    //     printf("Nao encontrado\n");

    libera(raiz);

    return 0;
}