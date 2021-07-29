#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;           // Informação do nó
    struct no *proximo; // End. do próximo nó
} No;

int main()
{
    No *primeiro = malloc(sizeof(No));
    //No *segundo = malloc(sizeof(No));

    primeiro->dado = 2;
    primeiro->proximo = malloc(sizeof(No));
    primeiro->proximo->dado = 3;
    primeiro->proximo->proximo = malloc(sizeof(No));
    primeiro->proximo->proximo->dado = 5;
    primeiro->proximo->proximo->proximo = NULL;

    printf("%d\n", primeiro->dado);
    printf("%d\n", primeiro->proximo->dado);
    printf("%d\n", primeiro->proximo->proximo->dado);


    return 0;
}