#include <stdio.h>
#include <stdlib.h>

#include "FilaPrioridade.h"

struct filaprio {
    int *A;
    int n;
    int capacidade;
};

FilaPrioridade *criaFilaPrioridade(int capacidade) {
    FilaPrioridade *fp = malloc(sizeof(FilaPrioridade));
    fp->A = malloc((capacidade + 1)*sizeof(int));
    fp->n = 0;
    fp->capacidade = capacidade;
    return fp;
}

void liberaFilaPrioridade(FilaPrioridade *fp) {
    free(fp->A);
    free(fp);
    fp = NULL;
}

void insere(FilaPrioridade *fp, int elem) {
    /* Insere um elemento na fila, onde o seu valor indica a prioridade (quanto maior, maior a prioridade) */
    if(fp == NULL) {
        printf("ERRO: Fila de Prioridade não alocada\n");
        return;
    }
    if(cheia(fp)) {
        printf("ERRO: Fila de Prioridade cheia\n");
        return;
    }
    fp->n++;
    int i = fp->n;
    while(i > 1 && elem > fp->A[i / 2]) {
        fp->A[i] = fp->A[i / 2];
        i = i / 2;
    }
    fp->A[i] = elem;
}

static void troca(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

static void ajustaHeap(FilaPrioridade *fp, int i) {
    // Complexidade: O(log n)
    //imprimeFP(fp);
    int filhoEsq = 2*i;
    int filhoDir = 2*i + 1;
    int posMaior = i;

    //Definir quem tem o maior valor: i ou filhoEsq ou filhoDir;
    if(filhoEsq <= fp->n && fp->A[filhoEsq] > fp->A[posMaior])
        posMaior = filhoEsq;
    if(filhoDir <= fp->n && fp->A[filhoDir] > fp->A[posMaior])
        posMaior = filhoDir;

    if(i != posMaior) {
        troca(&fp->A[i], &fp->A[posMaior]);
        ajustaHeap(fp, posMaior);
    }
}

void removeMax(FilaPrioridade *fp) {
    /* Remove o elemento de maior prioridade */
    //Complexidade: O(log n)
    fp->A[1] = fp->A[fp->n];
    fp->n--;
    ajustaHeap(fp, 1);
}


int getMax(FilaPrioridade *fp) {
    /* Retorna o elemento de maior prioridade */
    return fp->A[1];
}


bool vazia(FilaPrioridade *fp) {
    return fp->n == 0;
}


bool cheia(FilaPrioridade *fp) {
    return fp->n == fp->capacidade;
}


int tamanhoFP(FilaPrioridade *fp) {
    return fp->n;
}

void imprimeFP(FilaPrioridade *fp) {
    if(fp == NULL)
        return;
    printf("[");
    for (int i = 1; i < fp->n; i++)
        printf("%d, ", fp->A[i]);
    printf("%d]\n", fp->A[fp->n]);
}
