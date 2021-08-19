#ifndef __NO_H_
#define __NO_H_

#include "Objetos.h"

typedef struct no {
    Tipo tipo;
    void *objeto; 
    struct no *proximo;
}No;

No *criaRetangulo(double, double);

No *criaTriangulo(double, double);

No *criaCirculo(double);

void liberaNo(No *);

void imprimeNo(No *);

#endif