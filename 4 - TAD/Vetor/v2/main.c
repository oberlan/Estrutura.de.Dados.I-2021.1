#include <stdio.h>
#include <stdlib.h>

#include "Vetor.h"

int main() {
    int n = 10;
    //int *dados = malloc(n*sizeof(int));
    Vetor *v = criaVetor(n);
    printf("   Tamanho: %d\n", tamanhoVetor(v));
    printf("Capacidade: %d\n", capacidadeVetor(v));

    for (int i = 0; i < 5; i++) {
        insereNoFimVetor(v, i + 1);
    }
    imprimeVetor(v);
    printf("   Tamanho: %d\n", tamanhoVetor(v));
    printf("Capacidade: %d\n", capacidadeVetor(v));

    Vetor *tmp = v;
    v = copiaVetor(v);
    liberaVetor(tmp);
    
    // Vetor *v1 = copiaVetor(v);
    // imprimeVetor(v1);

    // insereNoFimVetor(v, 123);
    // printf(" v: ");
    // imprimeVetor(v);
    // insereNoFimVetor(v1, -1);
    // printf("v1: ");
    // imprimeVetor(v1);
    // printf(" v: ");
    // imprimeVetor(v);

    // printf("%p ", v->dados);
    // printf("%p ", v1->dados);

    liberaVetor(v);
    // liberaVetor(v1);
    return 0;   
}