#include <stdio.h>
#include <stdlib.h>

#include "TS.h"

struct no {
    Aluno *aluno;
    struct no *proximo;
    struct no *anterior;
};

struct ts {
    No *inicio;
    No *fim;
    int n;
};

TS *criaTS() {
    TS *ts = malloc(sizeof(TS));
    ts->inicio = ts->fim =  NULL;
    ts->n = 0;
    return ts;
}

void liberaTS(TS* ts) {
    No* atual = ts->inicio;
    while (atual != NULL) {
        No* t = atual->proximo; 
        free(atual->aluno);
        free(atual);            
        atual = t;              
    }
    free(ts);
    ts = NULL;
}

void put(TS *ts, Aluno *a) {
    Aluno *aluno = get(ts, getChave(a));
    if (aluno) { //Aluno encontrado, atualizamos o seu nome
        setNome(aluno, getNome(a));
    }
    else {
        No *novo = malloc(sizeof(No));
        novo->aluno = a;
        novo->proximo = NULL;
        novo->anterior = ts->fim;
        if (ts->fim == NULL)
            ts->inicio = novo;
        else
            ts->fim->proximo = novo;
        ts->fim = novo;
        ts->n++;
    }
}

Aluno *get(TS *ts, TipoChave k) {
    for (No *p = ts->inicio; p != NULL; p = p->proximo)
        if (getChave(p->aluno) == k)
            return p->aluno;
    return NULL;
}

bool erase(TS *ts, TipoChave k) {
    No *p = ts->inicio;
    while (p && getChave(p->aluno) != k)
        p = p->proximo;
    if (p) { //Aluno encontrado
        if (p == ts->inicio)
            ts->inicio = p->proximo;
        else
            p->anterior->proximo = p->proximo;
        if (p == ts->fim)
            ts->fim = p->anterior;
        else
            p->proximo->anterior = p->anterior;
        ts->n--;
        free(p);
        return true;
    }
    return false;
}

int size(TS *ts){
    return ts->n;
}

bool isEmpity(TS *ts) {
    return ts->n == 0;
}

void imprimeTS(TS *ts) {
    printf("{");
    No *p = NULL;
    for (p = ts->inicio; p && p->proximo != NULL; p = p->proximo) {
        printf("(%d, %s), ", getChave(p->aluno), getNome(p->aluno));
    }
    if (p) {
        printf("(%d, %s)", getChave(p->aluno), getNome(p->aluno));
    }
    printf("}\n");
}
