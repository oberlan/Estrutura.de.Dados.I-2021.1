#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Objetos.h"
#include "Lista.h"

#define PAUSE printf("Pressione ENTER para continuar...\n"); getchar();

// typedef struct  {
//     int vInt;
//     double vDouble;
//     char vStr[100];
// }TipoDado;

typedef union {
    int vInt;
    double vDouble;
    char vStr[100];
}TipoDado;

int main() {
    // TipoDado tipo;
    // printf("%ld\n", sizeof(TipoDado));
    // printf("%ld\n", sizeof(TipoDadoUnion));

    // tipo.vInt = 10;
    // printf("vInt = %d\n", tipo.vInt);

    // strcpy(tipo.vStr, "Estrutura de Dados 1");
    // printf("vStr = %s\n", tipo.vStr);
    // printf("vInt = %d\n", tipo.vInt);

    // tipo.vDouble = 123456789123;
    // printf("vDouble = %lf\n", tipo.vDouble);
    // printf("vStr = %s\n", tipo.vStr);
    // printf("vInt = %d\n", tipo.vInt);

    Lista *lista = criaLista();
    Objeto obj;
    obj.r = (Retangulo){15, 10};
    // printf("%lf x %lf\n", obj.r.b, obj.r.h);
    insereInicioLista(lista, RET, obj);

    obj.t = (Triangulo){23, 15};
    // printf("%lf x %lf\n", obj.t.b, obj.t.h);
    insereInicioLista(lista, TRI, obj);

    obj.c = (Circulo){13};
    // printf("%lf\n", obj.c.r);
    insereFimLista(lista, CIRC, obj);

    imprimeLista(lista);

    liberaLista(lista);

    return 0;
}