#ifndef __LISTA_H_
#define __LISTA_H_

#include "Objetos.h"
#include "No.h"

typedef struct lista Lista;

Lista *criaLista();

void liberaLista(Lista *lista);

void insereLista(Lista *lista, No*); //insereFim

void imprimeLista(Lista *lista);

int listaVazia(Lista *l);

int tamanhoLista(Lista *lista);




#endif