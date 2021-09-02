#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Aluno.h"

struct aluno {
    TipoChave matricula;
    char nome[100];
};

Aluno *criaAluno(TipoChave k, char *v) {
    Aluno *a = malloc(sizeof(Aluno));
    a->matricula = k;
    strcpy(a->nome, v);
    return a;
}

TipoChave getChave(Aluno *a) {
    return a->matricula;
}

char *getNome(Aluno *a) {
    return a->nome;
}

void setChave(Aluno *a, TipoChave k) {
    a->matricula = k;
}

void setNome(Aluno *a, char *nome) {
    strcpy(a->nome, nome);
}
