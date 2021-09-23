#include <stdio.h>
#include <stdlib.h>

#include "FilaPrioridade.h"

int main() {
    FilaPrioridade  *fila = criaFilaPrioridade(100);

    insere(fila, 100);
    insere(fila, 19);
    insere(fila, 36);
    insere(fila, 13);
    insere(fila, 3);
    insere(fila, 25);
    insere(fila, 1);
    insere(fila, 2);
    insere(fila, 7);

    imprimeFP(fila);
    insere(fila, 42);
    imprimeFP(fila);

    printf("Elemento de maior prioridade: %d\n", getMax(fila));
    
    printf("Removendo o elemento de maior prioridade...\n");
    removeMax(fila);
    imprimeFP(fila);
    printf("Novo elemento de maior prioridade: %d\n", getMax(fila));

    printf("Removendo o elemento de maior prioridade...\n");
    removeMax(fila);
    imprimeFP(fila);
    printf("Novo elemento de maior prioridade: %d\n", getMax(fila));

    printf("Removendo o elemento de maior prioridade...\n");
    removeMax(fila);
    imprimeFP(fila);
    printf("Novo elemento de maior prioridade: %d\n", getMax(fila));

    liberaFilaPrioridade(fila);
    return 0;
}