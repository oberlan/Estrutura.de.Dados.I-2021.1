#ifndef __TADP_H
#define __TADP_H

typedef enum {
    false,
    true
}bool;

typedef struct pilha Pilha;

Pilha *criaPilha();

void liberaPilha(Pilha *);

void push(Pilha *, int);

void pop(Pilha *);

int top(Pilha *);

bool pilhaVazia(Pilha *);

bool pilhaCheia(Pilha *);

int tamanhoPilha(Pilha *);

#endif