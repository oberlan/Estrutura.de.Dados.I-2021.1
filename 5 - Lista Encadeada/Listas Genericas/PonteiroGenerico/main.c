#include <stdio.h>
#include <stdlib.h>

#include "Objetos.h"
#include "Lista.h"

#define PAUSE printf("Pressione ENTER para continuar...\n"); getchar();

int main() {
    Lista *lista = criaLista();
    // insereLista(lista, criaRetangulo(15, 10));
    // insereLista(lista, criaTriangulo(25, 20));
    // insereLista(lista, criaRetangulo(50, 100));
    // insereLista(lista, criaCirculo(15));

    // imprimeLista(lista);
    insereLista(lista, criaRetangulo(10, 10));
    insereLista(lista, criaRetangulo(15, 13));
    // imprimeLista(lista);
    // PAUSE

    insereLista(lista, criaTriangulo(20, 10));
    insereLista(lista, criaTriangulo(50, 25));
    // imprimeLista(lista);
    // PAUSE

    insereLista(lista, criaCirculo(15));
    imprimeLista(lista);

    liberaLista(lista);
    return 0;
}