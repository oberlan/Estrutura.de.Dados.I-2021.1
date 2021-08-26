#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"

int main() {
    Fila  *fila = criaFila(5);
    enqueue(fila, 1);
    enqueue(fila, 2);
    enqueue(fila, 3);
    enqueue(fila, 4);
    enqueue(fila, 5);
    if (!filaVazia(fila))
        printf("1) Elemento Retornado: %d\n", front(fila));
    enqueue(fila, 6);
    if (!filaVazia(fila))
        printf("2) Elemento Retornado: %d\n", front(fila));

    dequeue(fila);
    enqueue(fila, 6);
    if (!filaVazia(fila))
        printf("3) Elemento Retornado: %d\n", front(fila));
    dequeue(fila);
    if (!filaVazia(fila))
        printf("4) Elemento Retornado: %d\n", front(fila));
    dequeue(fila);
    if (!filaVazia(fila))
        printf("5) Elemento Retornado: %d\n", front(fila));
    dequeue(fila);
    if (!filaVazia(fila))
        printf("6) Elemento Retornado: %d\n", front(fila));
    dequeue(fila);
    if (!filaVazia(fila))
        printf("7) Elemento Retornado: %d\n", front(fila));
    dequeue(fila);
    if (!filaVazia(fila))
        printf("8) Elemento Retornado: %d\n", front(fila));
    else
        printf("Estrutura sem elementos\n");
    enqueue(fila, 11);
    if (!filaVazia(fila))
        printf("9) Elemento Retornado: %d\n", front(fila));

    printf("\n\n");
    Fila *fila2 = criaFila(5);
    /*Note que o código insere e remove elementos na estrutura*/
    /*A estrutura tem capacidade = 5 e são inseridos 10 valores*/
    /*Se sua implementação está correta, isso não deve ser problema*/
    for(int i = 0; i < 10; i++){
        printf("Iteracao %d:\n", i);
        printf(" - Inserindo o valor: %d\n", i);
        enqueue(fila2, i);
        printf(" -        #Elementos: %d\n", tamanhoFila(fila2));
        printf(" - Primeiro Elemento: %d\n\n", front(fila2));
        dequeue(fila2);
    }

    printf("#Elementos: %d\n", tamanhoFila(fila2)); /* Deve ser 0 */

    liberaFila(fila);
    liberaFila(fila2);
    return 0;
}