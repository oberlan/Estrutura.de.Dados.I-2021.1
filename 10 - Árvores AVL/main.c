#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct no {
    int dado;
    struct no *esq;
    struct no *dir;
    int altura;
}No;

No *criaNo(int v) {
    No *novo = malloc(sizeof(No));
    novo->dado = v;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->altura = 0;
    return novo;
}

void libera (No* r) {
    if (r != NULL) {
        libera(r-> esq);
        libera(r-> dir);
        free(r);
    }
}

No* busca (No* r, int v) {
    if (r == NULL || r->dado == v)
        return r;
    if (r->dado > v)
        return busca(r->esq , v);
    else
        return busca(r->dir, v);
}

void padding ( char ch, int n ){
  int i;
  for ( i = 0; i < n; i++ )
    putchar ( ch );
}

void imprimeArvore( No *root, int level ){
  if ( root == NULL ) {
    padding ('\t', level );
    puts ("~" );
  } else {
      imprimeArvore(root->dir, level + 1);
      padding('\t', level);
      printf("%d\n", root->dado);
      imprimeArvore(root->esq, level + 1);
  }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int altura(No *r) {
    //Complexidade: O(1)
    if(r == NULL)
        return -1;
    return r->altura;
}

int fatorBalanceamento(No * r){
    //Complexidade: O(1)
    return altura(r->esq) - altura(r->dir);
}


No *rotacaoDireita(No *A) {
    //Complexidade: O(1)
    No *B = A->esq;

    //Realiza a rotação
    A->esq = B->dir;
    B->dir = A;

    //Atualiza a altura dos nós
    A->altura = max(altura(A->dir), altura(A->esq)) + 1;
    B->altura = max(altura(B->dir), altura(B->esq)) + 1;

    //Retorna a nova raiz
    return B;
}

No *rotacaoEsquerda(No *A) {
    //Complexidade: O(??)
    No *B = A->dir;

    //Realiza a rotação
    A->dir = B->esq;
    B->esq = A;

    //Atualiza a altura dos nós
    A->altura = max(altura(A->dir), altura(A->esq)) + 1;
    B->altura = max(altura(B->dir), altura(B->esq)) + 1;

    //Retorna a nova raiz
    return B;
}

No *insere(No *r, No* novo) {
    /*PASSO 1: Faz a inserção normal de uma ABB */
    if (r == NULL) return novo;
    if(r->dado > novo->dado)
        r->esq = insere(r->esq, novo);
    else
        r->dir = insere(r->dir, novo);

    //PASSO 2: Atualizar a altura do nó
    r->altura = max(altura(r->dir), altura(r->esq)) + 1;

    /*PASSO 3: Obter o fator de balanceamento do nó e verifica se é necessário o rebalanceamento */
    int fb = fatorBalanceamento(r);

    //Rotação RR
    if (fb > 1 && fatorBalanceamento(r->esq) >= 0){
        return rotacaoDireita(r);
    }
    //Rotação LL
    if (fb < -1 && fatorBalanceamento(r->dir) <= 0) {
        return rotacaoEsquerda(r);
    }
    //Rotação LR (Rotação LL + Rotação RR)
    if (fb > 1 && fatorBalanceamento(r->esq) < 0) {
        r->esq = rotacaoEsquerda(r->esq);
        return rotacaoDireita(r);
    }
    //Rotação RL (Rotação RR + Rotação LL)
    if (fb < -1 && fatorBalanceamento(r->dir) > 0) {
        r->dir = rotacaoDireita(r->dir);
        return rotacaoEsquerda(r);
    }

    return r;
}

int main() {

    No *raiz = NULL;
    for(int i = 10; i<= 70; i+= 10) {
        printf("\nInserindo %d\n", i);
        getchar();
        raiz = insere(raiz, criaNo(i));
        imprimeArvore(raiz, 0);
    }

    return 0;
}