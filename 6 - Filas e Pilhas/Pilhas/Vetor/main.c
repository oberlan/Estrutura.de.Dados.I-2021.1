#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"

int main() {
    Pilha  *pilha = criaPilha(5);
    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 3);
    push(pilha, 4);
    push(pilha, 5);
    if (!pilhaVazia(pilha))
        printf("1) Elemento Retornado: %d\n", top(pilha));
    push(pilha, 6);
    if (!pilhaVazia(pilha))
        printf("2) Elemento Retornado: %d\n", top(pilha));

    pop(pilha);
    push(pilha, 6);
    if (!pilhaVazia(pilha))
        printf("3) Elemento Retornado: %d\n", top(pilha));
    pop(pilha);
    if (!pilhaVazia(pilha))
        printf("4) Elemento Retornado: %d\n", top(pilha));
    pop(pilha);
    if (!pilhaVazia(pilha))
        printf("5) Elemento Retornado: %d\n", top(pilha));
    pop(pilha);
    if (!pilhaVazia(pilha))
        printf("6) Elemento Retornado: %d\n", top(pilha));
    pop(pilha);
    if (!pilhaVazia(pilha))
        printf("7) Elemento Retornado: %d\n", top(pilha));
    pop(pilha);
    if (!pilhaVazia(pilha))
        printf("8) Elemento Retornado: %d\n", top(pilha));
    else
        printf("Estrutura sem elementos\n");
    push(pilha, 11);
    if (!pilhaVazia(pilha))
        printf("9) Elemento Retornado: %d\n", top(pilha));

    liberaPilha(pilha);
    return 0;
}