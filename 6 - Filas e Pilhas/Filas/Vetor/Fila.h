#ifndef __FILA_H
#define __FILA_H

typedef enum {
    false,
    true
}bool;

typedef struct fila Fila;

Fila *criaFila(int);

void liberaFila(Fila *);

void enqueue(Fila *, int v);

void dequeue(Fila *);

int front(Fila *);

bool filaVazia(Fila *);

bool filaCheia(Fila *);

int tamanhoFila(Fila *);

#endif