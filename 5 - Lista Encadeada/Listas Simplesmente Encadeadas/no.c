#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;           // Informação do nó
    struct no *proximo; // End. do próximo nó
}No;


int main() {
    No *primeiro = malloc(sizeof(No));
    No *segundo = malloc(sizeof(No));
    No *terceiro = malloc(sizeof(No));
    No *quarto = malloc(sizeof(No));

    primeiro->dado = 2;
    primeiro->proximo = segundo;

    segundo->dado = 3;
    segundo->proximo = terceiro;

    terceiro->dado = 5;
    terceiro->proximo = quarto;

    quarto->dado = 7;
    quarto->proximo = NULL;

    printf("%d\n", primeiro->dado);
    printf("%d\n", segundo->dado);
    printf("%d\n", terceiro->dado);
    printf("%d\n", quarto->dado);

    printf("\n\n");
    
    printf("%d\n", primeiro->dado);
    printf("%d\n", primeiro->proximo->dado);
    printf("%d\n", primeiro->proximo->proximo->dado);
    printf("%d\n", primeiro->proximo->proximo->proximo->dado);

    // printf("%p\n", primeiro);
    // printf("%p\n", segundo);
    // printf("%p\n", terceiro);

    // int primos[10000000];
    // primos[3] = 7;
    // int *primos2 = malloc(10*sizeof(int));//1 realloc -> O(n)
    //                                       //n realloc -> n O(n) -> O(n²)  

    return 0;
}