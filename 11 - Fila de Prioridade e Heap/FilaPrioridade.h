#ifndef __FILA_H
#define __FILA_H

typedef enum {
    false,
    true
} bool;

typedef struct filaprio FilaPrioridade;

FilaPrioridade *criaFilaPrioridade(int);

void liberaFilaPrioridade(FilaPrioridade *);

void insere(FilaPrioridade *, int);

void removeMax(FilaPrioridade *);

int getMax(FilaPrioridade *);

bool vazia(FilaPrioridade *);

bool cheia(FilaPrioridade *);

int tamanhoFP(FilaPrioridade *);

void imprimeFP(FilaPrioridade *);

#endif