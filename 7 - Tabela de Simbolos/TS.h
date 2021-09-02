#ifndef __TS_H_
#define __TS_H_

#include "Aluno.h"

typedef enum {
    false,
    true
} bool;

typedef struct no No;

// typedef struct no {
//     Aluno aluno;
//     struct no *proximo;
//     struct no *anterior;
// } No;

typedef struct ts TS;

TS *criaTS();

void liberaTS(TS *ts);

void put(TS *, Aluno *);

Aluno *get(TS *, TipoChave );

int size(TS *);

bool erase(TS *, TipoChave);

bool isEmpity(TS *);

void imprimeTS(TS *);


#endif